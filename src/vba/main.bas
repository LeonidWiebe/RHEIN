Attribute VB_Name = "main"
Option Explicit

Public Type OPENFILENAME
    lStructSize As Long
    hwndOwner As Long
    hInstance As Long
    lpstrFilter As String
    lpstrCustomFilter As String
    nMaxCustFilter As Long
    nFilterIndex As Long
    lpstrFile As String
    nMaxFile As Long
    lpstrFileTitle As String
    nMaxFileTitle As Long
    lpstrInitialDir As String
    lpstrTitle As String
    flags As Long
    nFileOffset As Integer
    nFileExtension As Integer
    lpstrDefExt As String
    lCustData As Long
    lpfnHook As Long
    lpTemplateName As String
End Type

' Константы для управления флагами окна "Открыть/Сохранить файл"
Public Enum OFN_FLAGS
    OFN_READONLY = &H1
    OFN_OVERWRITEPROMPT = &H2
    OFN_HIDEREADONLY = &H4
    OFN_NOCHANGEDIR = &H8
    OFN_SHOWHELP = &H10
    OFN_ENABLEHOOK = &H20
    OFN_ENABLETEMPLATE = &H40
    OFN_ENABLETEMPLATEHANDLE = &H80
    OFN_NOVALIDATE = &H100
    OFN_ALLOWMULTISELECT = &H200
    OFN_EXTENSIONDIFFERENT = &H400
    OFN_PATHMUSTEXIST = &H800
    OFN_FILEMUSTEXIST = &H1000
    OFN_CREATEPROMPT = &H2000
    OFN_SHAREAWARE = &H4000
    OFN_NOREADONLYRETURN = &H8000
    OFN_NOTESTFILECREATE = &H10000
    OFN_NONETWORKBUTTON = &H20000
    OFN_NOLONGNAMES = &H40000
    OFN_EXPLORER = &H80000
    OFN_NODEREFERENCELINKS = &H100000
    OFN_LONGNAMES = &H200000
End Enum

Public Declare Function GetOpenFileName Lib "comdlg32.dll" Alias "GetOpenFileNameA" (pOpenfilename As OPENFILENAME) As Long
Public Declare Function GetSaveFileName Lib "comdlg32.dll" Alias "GetSaveFileNameA" (pOpenfilename As OPENFILENAME) As Long


Private Declare Function GetUserName Lib "advapi32" Alias "GetUserNameA" (ByVal lpBuffer As String, nSize As Long) As Long

Public Declare Function mdlModelRef_getElementRef Lib "stdmdlbltin.dll" (ByVal modelRef As Long, ByVal filePos As Long) As Long
Public Declare Sub mdlLocate_hiliteElement Lib "stdmdlbltin.dll" (ByVal elemRef As Long, ByVal modelRef As Long)

Public Declare Function mdlModelRef_getCache Lib "stdmdlbltin.dll" (ByVal modelRef As Long) As Long
Public Declare Function dgnCache_findElemByID Lib "stdmdlbltin.dll" (ByVal cache As Long, ByVal elementID As Long) As Long

Declare Function mdlRefFile_getParameters Lib "stdmdlbltin.dll" _
     (ByRef param As Long, _
     ByVal paramName As Long, _
     ByVal modelRef As Long) As Long

Declare Sub mdlLocate_clearHilited Lib "stdmdlbltin.dll" (ByVal redraw As Long)

Public usrName As String
Public usrID As Long

Public bGridFormLoaded As Boolean
Public bBarFormLoaded As Boolean

Public Const appID As Long = 15973 ' для привязки файла DGN к каталогу через ApplicationElement

Public cn As New ADODB.Connection

Public Enum oper
    operUnknown
    operCreate
    operModify
    operGlobal
    operDelete
    operRestore
    operErase
End Enum

Public strDBServer As String
Public strDBName   As String
Public strDBUser As String
Public strDBPass   As String

Public lngCurCatalogID As Long
Public lngCurProjectID As Long
Public catName As String

Public strProjName As String
Public strBlockNumber As String
Public strBuildingCode As String


Public bars As Collection
Public cages As Collection ' каркасы
Public hides As Collection

Public objs As Collection


Public bBrys As Boolean
'Public a As Integer

Public srtm(100) As Long

Public globLaps As Offtmisc.colArmLap


Public armCtl As Rein2D_prj.Rein2d

Public f As F1
Public fm As frmRep

Public bFormLoaded As Boolean

Public refsAll As Collection

Public lngMuftEndQty As Long
Public lngMuftLapQty As Long

Public Function getElem(ByRef ele As Element, strID As String) As Boolean

On Error GoTo err

    Set ele = ActiveModelReference.GetElementByID(DLongFromString(strID))
    
    getElem = True
    
    Exit Function

err:

End Function


Public Function getModelRefByRefNumber(refnum As Long) As Attachment

    On Error GoTo err


    Dim a As Integer
    Dim att As Attachment
    Dim lngSlotNumber As Long

    If refnum = 0 Then
    
        Set getModelRefByRefNumber = ActiveModelReference
        
    Else
    
        For a = 1 To ActiveModelReference.Attachments.Count
        
            Set att = ActiveModelReference.Attachments(a)
            
            mdlRefFile_getParameters lngSlotNumber, 28, att.MdlModelRefP
            
            If refnum = lngSlotNumber Then
                Set getModelRefByRefNumber = att
                Exit For
            
            End If
        Next a
    End If

    Exit Function
    
err:
Set getModelRefByRefNumber = Nothing
    



End Function


Public Function getCage(strKey As String) As clsBar

On Error GoTo err

    Set getCage = cages(strKey)
    
    Exit Function

err:
    Set getCage = Nothing

End Function



Public Sub getCages()

On Error GoTo err

    Dim at As Attachment
    Dim isElem As Long
    Dim br As clsBar

    
    Set cages = New Collection
    
    If Not tryToConnectDB Then Exit Sub
    
    lngCurCatalogID = GetCExpressionValue("iOfftCatID", "rein")
    lngCurProjectID = GetCExpressionValue("iOfftProjID", "rein")
    
    If lngCurCatalogID = 0 Then Exit Sub
    
    
    Dim RS As New ADODB.Recordset
    
    RS.Open "select * from view_object_catalog where objID = 7 and objectID = " & lngCurCatalogID & " and deleted = 0", cn, adOpenForwardOnly, adLockReadOnly
    
    If Not RS.EOF Then
        RS.MoveFirst
        Do
            Dim brr As New clsBar
            brr.partID = RS.Fields("catID").Value
            brr.sName = correctPartName(RS.Fields("catName").Value)
            cages.Add brr, brr.sName
            Set brr = Nothing
            RS.MoveNext
        Loop Until RS.EOF
    End If
    
    
    
    
    For Each at In ActiveModelReference.Attachments
    
        If at.IsMissingFile Then GoTo cnt
        If at.IsMissingModel Then GoTo cnt
    
        mdlRefFile_getParameters isElem, 67, at.MdlModelRefP ' REFERENCE_TREAT_AS_ELEMENT
        
        If isElem > 0 Then
            
            Set br = getCage(correctPartName(at.AttachModelName))
            
            If br Is Nothing Then
                Set br = New clsBar
                br.sName = correctPartName(at.AttachModelName)
                br.base_qty = 1
                cages.Add br, br.sName
                Set br = Nothing
            Else
                br.base_qty = br.base_qty + 1
            End If
            
        
        
        End If
        
cnt:
            
    Next at
    
    
    Set fm = New frmRep
    
    fm.FG.Rows = 1
    fm.lblErrs.Visible = False
    fm.cmbCatList.Visible = True
'    fm.btnSave.Caption = "Добавить" & vbNewLine & "в список"
'    fm.btnSave.Enabled = False
    fm.FG.TextMatrix(0, 0) = ""
    fm.FG.TextMatrix(0, 1) = "Изделие"
    fm.FG.TextMatrix(0, 2) = "Кол-во"
    fm.FG.TextMatrix(0, 3) = "Примечание"
    
    
    For Each br In cages
        fm.FG.AddItem br.partID & vbTab & br.sName & vbTab & br.base_qty
        If br.partID = 0 Then fm.FG.TextMatrix(fm.FG.Rows - 1, 3) = "нет в базе"
        If br.base_qty = 0 Then fm.FG.TextMatrix(fm.FG.Rows - 1, 3) = "нет в файле"
    Next br
    
    fm.FG.AutoSize 0, fm.FG.Cols - 1
    fm.FG.ColHidden(0) = True
    
    RS.NextRecordset
    RS.Open "select * from catlist where catID = " & lngCurCatalogID & " and deleted = 0", cn, adOpenForwardOnly, adLockReadOnly
    
    If Not RS.EOF Then
        RS.MoveFirst
        Do
            Set br = New clsBar
            br.sName = RS.Fields("catlistName").Value
            br.partID = RS.Fields("catlistID").Value
            
            fm.colMufts.Add br, CStr(br.partID)
            
            Set br = Nothing

            RS.MoveNext
        Loop Until RS.EOF
    End If
    
    
    For Each br In fm.colMufts
        fm.cmbCatList.AddItem br.sName
    Next br
    
    
    fm.Show 0




    RS.Close
    Set RS = Nothing
    
    Exit Sub
err:
    MsgBox err.Description


End Sub


Public Function getHidePosNum(strKey As String) As Long

On Error GoTo err

    Dim br As clsBar
    
    Set br = hides(strKey)

    getHidePosNum = br.numpos

Exit Function
err:
    getHidePosNum = 0

End Function


Public Function getHidePos(strKey As String) As clsBar

On Error GoTo err

    Dim br As clsBar
    
    Set br = hides(strKey)

    Set getHidePos = br

Exit Function
err:
    Set getHidePos = Nothing

End Function


Public Sub syncHides(br As clsBar)

On Error GoTo err

    Dim strKey As String
    
    strKey = CStr(br.numpos) & "|" & br.refnum & "|" & br.pcatID
    
    Dim bar As clsBar
    
    Set bar = getHidePos(strKey)
    
    If bar Is Nothing Then
        hides.Add br, strKey
        Set br = Nothing
    Else
        If br.bHide = False And br.bHide_V = False And br.bHide_X = False And br.bHide_O = False And br.bHide_S = False Then
            hides.Remove strKey
        Else
            bar.bHide = br.bHide
            bar.bHide_V = br.bHide_V
            bar.bHide_X = br.bHide_X
            bar.bHide_O = br.bHide_O
            bar.bHide_S = br.bHide_S
        End If
    End If


    
    
    
err:

End Sub



Public Sub addPosHide()

On Error GoTo err


    Dim ar00() As String

    ar00 = Split(Application.KeyinArguments, "|")
    
    If UBound(ar00) <> 7 Then Exit Sub
    
    Dim br As New clsBar
    br.numpos = Val(ar00(0))
    br.refnum = Val(ar00(1))
    br.pcatID = Val(ar00(2))
    br.bHide = CBool(Val(ar00(3)))
    br.bHide_V = CBool(Val(ar00(4)))
    br.bHide_X = CBool(Val(ar00(5)))
    br.bHide_O = CBool(Val(ar00(6)))
    br.bHide_S = CBool(Val(ar00(7)))
    
    syncHides br
    
    
    
err:

End Sub




Public Sub savePos()


    lngCurCatalogID = GetCExpressionValue("iOfftCatID", "rein")
    lngCurProjectID = GetCExpressionValue("iOfftProjID", "rein")


    Dim iRM As Integer

    Dim ar() As String
    Dim ar0() As String
    Dim ar00() As String
    ar0 = Split(Application.KeyinArguments, "!")
    ar = Split(ar0(0), ";")

    Dim bar As New clsBar
    
    bar.posID = Val(ar(0))          ' posID
    bar.srtmID = Val(ar(1))         ' srtmID
    bar.diam = Val(ar(2))           ' диаметр
    iRM = Val(ar(3))                ' штуки / пог.м. / перем длина
    bar.iMain = Val(ar(4))          ' индекс начальной точки главного сегмента
    'Val (ar(5))                    ' прозрачность: 22 - внутр, 21 - внешний
    'bar.rad = Val(ar(6))           ' радиус главного сегмента, не исп. (0)
    bar.bend_rad = Val(ar(7))       ' радиус скругления загибов
    bar.termBegType = Val(ar(8))    ' тип начала стержня
    bar.termEndType = Val(ar(9))    ' тип конца стержня
    bar.numpos = Val(ar(10))        ' номер позиции
    
    'bar.base_qty = Val(ar(11))
    'bar.base_length = Val(ar(12))   ' 0
    bar.file_qty_p = Val(ar(13))
    bar.file_qty_rm = Val(ar(14))
    
    bar.file_ms_min = Val(ar(15))
    bar.file_ms_mid = Val(ar(16))
    bar.file_ms_max = Val(ar(17))
    
    bar.base_length = bar.file_ms_mid
    
    'bar.base_ms_min = Val(ar(18))
    'bar.base_ms_mid = Val(ar(19))
    'bar.base_ms_max = Val(ar(20))
    
    'bar.poslen = Val(ar(21))
    
    bar.termBegPar0 = Val(ar(22))
    bar.termEndPar0 = Val(ar(23))
    
    If bar.termBegPar0 = 0 Then bar.termBegPar0 = 180
    If bar.termEndPar0 = 0 Then bar.termEndPar0 = -180
    
    bar.termBegPar1 = Val(ar(24))
    bar.termEndPar1 = Val(ar(25))
    
    'bar.iArmLapQty = Val(ar(26)) ' количество нахлестов
    'bar.iArmMuftQty = Val(ar(28)) ' количество муфт
    
    bar.posdefID = Val(ar(27))
    
    bar.pcatID = Val(ar(29))
    
    
    
    If bar.srtmID = 0 Then
        If bar.diam > 0 Then bar.srtmID = srtm(bar.diam)
        If bar.diam = 0 Then iRM = 0
    End If
    
    If bar.posdefID <> 1 Then iRM = 0 ' ошибка если позиция не из базы
    
    If iRM = 1 Then
        bar.bRunMet = True
        bar.bCont = False
    ElseIf iRM = 2 Then
        bar.bRunMet = False
        bar.bCont = True
    Else ' == 0
        bar.bRunMet = False
        bar.bCont = False
    End If
    
    If bar.bRunMet Then
        bar.base_qty = bar.file_qty_rm
    Else
        bar.base_qty = bar.file_qty_p
    End If
    
    
    If bar.savePart(True, False) Then
        If bar.savePos(True) Then
        End If
    End If
    
    
    

End Sub


Public Sub addPos()

'    On Error GoTo err:
    
    Dim iRM As Integer
    
    If armCtl Is Nothing Then Exit Sub
    armCtl.Clear
    

    Dim ar00() As String
    Dim ar0() As String
    Dim ar() As String
    Dim i As Integer

    ar00 = Split(Application.KeyinArguments, "!")
    
    ar0 = Split(ar00(0), "|")
    
    ar = Split(ar0(0), ";")
    
    Dim bar As New clsBar
    
    bar.posID = Val(ar(0))
    bar.srtmID = Val(ar(1))
    bar.diam = Val(ar(2))
    iRM = Val(ar(3))
    bar.iMain = Val(ar(4))
'    bar.bLap = CBool(Val(ar(5)))
    bar.rad = Val(ar(6))
    bar.bend_rad = Val(ar(7))
    bar.termBegType = Val(ar(8))
    bar.termEndType = Val(ar(9))
    bar.numpos = Val(ar(10))
    bar.base_qty = Val(ar(11))
    bar.base_length = Val(ar(12))
    bar.file_qty_p = Val(ar(13))
    bar.file_qty_rm = Val(ar(14))
    
    bar.file_ms_min = Val(ar(15))
    bar.file_ms_mid = Val(ar(16))
    bar.file_ms_max = Val(ar(17))
    
    bar.base_ms_min = Val(ar(18))
    bar.base_ms_mid = Val(ar(19))
    bar.base_ms_max = Val(ar(20))
    
    bar.poslen = Val(ar(21))
    
    bar.termBegPar0 = Val(ar(22))
    bar.termEndPar0 = Val(ar(23))
    
    If bar.termBegPar0 = 0 Then bar.termBegPar0 = 180
    If bar.termEndPar0 = 0 Then bar.termEndPar0 = -180
    
    bar.termBegPar1 = Val(ar(24))
    bar.termEndPar1 = Val(ar(25))
'    Dim lp As Offtmisc.clsArmLap
'    Set lp = GetPOS_LAP(bar.diam)
'    bar.termBegPar1 = lp.getBendWork
'    bar.termEndPar1 = lp.getBendWork

    
    bar.iArmLapQty = Val(ar(26)) ' количество нахлестов
    bar.iArmMuftQty = Val(ar(28)) ' количество муфт
    
    bar.posdefID = Val(ar(27))
    
    If UBound(ar) >= 29 Then bar.pcatID = Val(ar(29))
    
    If bar.srtmID = 0 Then
        If bar.diam > 0 Then bar.srtmID = srtm(bar.diam)
        If bar.diam = 0 Then iRM = 0
    End If
    
    If bar.posdefID <> 1 Then iRM = 0 ' ошибка если позиция не из базы
    
    If iRM = 1 Then
    
        bar.bRunMet = True
        bar.bCont = False
        
    ElseIf iRM = 2 Then
    
        bar.bRunMet = False
        bar.bCont = True
        
    Else ' == 0
    
        bar.bRunMet = False
        bar.bCont = False
        
    End If
    
    
    Dim p As Point2d
    Dim p2 As Point2d
    Dim p3 As Point2d
    Dim ar1() As String
    
    For i = 1 To UBound(ar0)
    
        ar1 = Split(ar0(i), ";")
        
        p.X = ar1(0)
        p.Y = ar1(1)
        
        p2.X = ar1(2)
        p2.Y = ar1(3)
        
        p3.X = ar1(4)
        p3.Y = ar1(5)
        
        bar.pointsDraw.Add p
        
        bar.pointsComp.Add p2
        
        bar.pointsCompAlt.Add p3
        
        If UBound(ar1) > 5 Then bar.pointIsArc.Add CInt(ar1(6))
        
        armCtl.AddPoint p.X, p.Y, p.X, p.Y
        
    Next i
    
    armCtl.bCont = bar.bCont
    
    armCtl.RArc = bar.rad
    
    Dim ofms As New Offtmisc.Misc
    armCtl.dContMin = ofms.roundExt(bar.file_ms_min, -1, 5, Val(GetSetting("Offtake2", "RndShift", "iArmSegm", 0)))
    armCtl.dContMid = ofms.roundExt(bar.file_ms_mid, -1, 5, Val(GetSetting("Offtake2", "RndShift", "iArmSegm", 0)))
    armCtl.dContMax = ofms.roundExt(bar.file_ms_max, -1, 5, Val(GetSetting("Offtake2", "RndShift", "iArmSegm", 0)))
    
    
    If bar.termBegType > 0 Then armCtl.SetBegin bar.termBegType, bar.termBegPar0, bar.termBegPar1
    If bar.termEndType > 0 Then armCtl.SetEnd bar.termEndType, bar.termEndPar0, bar.termEndPar1
    
    
    armCtl.RArc = bar.rad
    armCtl.setR bar.bend_rad
    armCtl.setMainLine bar.iMain, False
    
    
    
    If bar.pointsDraw.Count > 2 Then
        bar.file_len_min = armCtl.getTotalMinLength
        bar.file_len_mid = armCtl.getTotalLength
        bar.file_len_max = armCtl.getTotalMaxLength
    Else
        bar.file_len_min = armCtl.dContMin
        bar.file_len_mid = armCtl.dContMid
        bar.file_len_max = armCtl.dContMax
    End If
    
    ' небольшой глюк - если контрол не инициализирован то он не учитывает длину загибов в getTotalLength
    If Not bFormLoaded Then ' поэтому прибавляем сами
        If bar.termBegType = 1 Then
            bar.file_len_min = bar.file_len_min + bar.termBegPar1
            bar.file_len_mid = bar.file_len_mid + bar.termBegPar1
            bar.file_len_max = bar.file_len_max + bar.termBegPar1
        End If
    
        If bar.termEndType = 1 Then
            bar.file_len_min = bar.file_len_min + bar.termEndPar1
            bar.file_len_mid = bar.file_len_mid + bar.termEndPar1
            bar.file_len_max = bar.file_len_max + bar.termEndPar1
        End If
    End If
    
    Dim bFound As Boolean
    
    ' референсы
    If UBound(ar00) > 0 Then
    
        Debug.Print bar.numpos, bar.pcatID, ar00(1)
    
        ar1 = Split(ar00(1), ";")
        
        For i = 0 To UBound(ar1)
        
            bar.refs.Add CLng(ar1(i))
            
            Dim J As Long
            bFound = False
            For J = 1 To refsAll.Count
                Dim refn As Long
                refn = refsAll(J)
                If refn = CLng(ar1(i)) Then
                    bFound = True
                    Exit For
                End If
            Next J
             
            If Not bFound Then refsAll.Add CLng(ar1(i))
            
        Next i
    
    End If
    
    
    
    
    '======================================
    
    bars.Add bar
    
    bar.arnum = bars.Count
    
    Set bar = Nothing
    
        
    armCtl.Clear
    
    

    
    Exit Sub
err:

    MessageCenter.AddMessage "addPos() - " & err.Description, , msdMessageCenterPriorityError, False

    armCtl.Clear


End Sub


Public Function getFileCatID() As Boolean ' NOT USING

    On Error GoTo err

    lngCurCatalogID = 0
    lngCurProjectID = 0
    strProjName = ""
    strBlockNumber = ""
    strBuildingCode = ""
    catName = ""
    getFileCatID = False

    Dim oScanCriteria As ElementScanCriteria
    Set oScanCriteria = New ElementScanCriteria
    
    oScanCriteria.ExcludeAllTypes
    oScanCriteria.IncludeType msdElementTypeMicroStation


    Dim oScanEnumerator As ElementEnumerator
    Set oScanEnumerator = ActiveModelReference.Scan(oScanCriteria)

    Dim ele As Element
    Dim clele As Element
    Dim ae As ApplicationElement


    Do While oScanEnumerator.MoveNext
        Set ele = oScanEnumerator.Current
        If ele.Subtype = msdElementSubtypeApplicationElement Then
            Set ae = ele.AsApplicationElement
            
            If ae.ApplicationID = appID Then
            
                Dim dbOut As DataBlock
                
                Set dbOut = ae.GetApplicationData
                
                dbOut.CopyLong lngCurCatalogID, False
                
            
            End If
        
        End If
        
    Loop

    If lngCurCatalogID > 0 Then
    
        Call getProjID(Nothing, lngCurCatalogID, "r_object_catalog", "catalogID")
    
    End If
    
    getFileCatID = True
    
    Exit Function
    
err:

    getFileCatID = False

End Function


Public Function getProjID(RS As ADODB.Recordset, ID As Long, sTableName As String, sFieldIDName As String) As Long

    Dim objID As Long
    Dim objectID As Long
    
    If RS Is Nothing Then
        Set RS = New ADODB.Recordset
    Else
        RS.NextRecordset
    End If
    
    RS.Open "select * from " & sTableName & " where " & sFieldIDName & " = " & ID, cn, adOpenForwardOnly, adLockReadOnly
    
    If Not RS.EOF Then
        RS.MoveFirst
        objID = RS.Fields("objID").Value
        objectID = RS.Fields("objectID").Value
        
        If sTableName = "view_object_building" Then
            strBuildingCode = RS.Fields("buildingCode").Value
        ElseIf sTableName = "r_object_catalog" Then
            RS.NextRecordset
            RS.Open "select catName from i_catalog where catID = " & ID, cn, adOpenForwardOnly, adLockReadOnly
            If Not RS.EOF Then
                RS.MoveFirst
                If Len(catName) > 0 Then
                    catName = RS.Fields("catName").Value & " - " & catName
                Else
                    catName = RS.Fields("catName").Value
                End If
            End If
        Else
        End If
        
    End If
    
    If objID = objs("catalog") Then
        objectID = getProjID(RS, objectID, "r_object_catalog", "catalogID")
    Else
    End If
    
    If objID = objs("building") Then
        objectID = getProjID(RS, objectID, "view_object_building", "buildingID")
    Else
    End If
    
    
    If objID = objs("block") Then
    
        RS.NextRecordset
        RS.Open "select * from i_block where blockID = " & objectID, cn, adOpenForwardOnly, adLockReadOnly
        If Not RS.EOF Then
            RS.MoveFirst
            objID = objs("project")
            objectID = RS.Fields("projectID").Value
            strBlockNumber = RS.Fields("blockNumber").Value
        End If
    Else
    End If
    
    If objID = objs("project") Then
        lngCurProjectID = objectID
        
        RS.NextRecordset
        
        RS.Open "select * from i_project where projectID = " & lngCurProjectID
        If Not RS.EOF Then
            RS.MoveFirst
            strProjName = RS.Fields("projectName").Value
        End If
        
    End If
    
    If Not RS Is Nothing Then
    RS.Close
    Set RS = Nothing
    End If
    
    



End Function


Sub wnd()

    On Error GoTo err


'    mdlGetCatID
    
    lngCurCatalogID = GetCExpressionValue("iOfftCatID", "rein")
    lngCurProjectID = GetCExpressionValue("iOfftProjID", "rein")

    Set f = New F1

    Set armCtl = f.Rein2d

    f.reloadDataAndGrid

    f.Show 0

    Exit Sub
err:
    MsgBox err.Description

End Sub

Public Function getSourceParams() As Boolean

    strDBName = Environ("AEP_SAVRD_BASE")
    strDBServer = Environ("AEP_SAVRD_SERVER")


    If Len(strDBServer) = 0 Then strDBServer = GetSetting("Offtake2", "Source", "Server", "10.22.66.190")
    If Len(strDBName) = 0 Then strDBName = GetSetting("Offtake2", "Source", "Database", "parts")
    strDBUser = GetSetting("Offtake2", "Source", "User", "so2user")
    strDBPass = GetSetting("Offtake2", "Source", "Pass", "so2user")
    
    
    
    getSourceParams = True


End Function


Public Function getDbl(s As String) As Double
    On Error GoTo err
    Dim d As Double
    d = s
    GoTo noerr
err:
    d = Val(s)
noerr:
    getDbl = d
End Function

Public Function tryToConnectDB() As Boolean

    tryToConnectDB = False
    
    On Error GoTo m2
    
    If getSourceParams Then
    
    
    '    If Not db.SimplePing(strDBServer) Then
    '        Exit Function
    '    End If
        
'        cn.Open "Provider=SQLNCLI.1;" &
        cn.Open "Provider=SQLOLEDB.1;" & _
            "Persist Security Info=False" & _
            ";User ID=" & strDBUser & _
            ";Initial Catalog=" & strDBName & _
            ";Data Source=" & strDBServer & _
            ";Net=dbmssocn", _
            strDBUser, strDBPass
        
        tryToConnectDB = True
        
        loadBaseData
        
        
        usrName = GetThreadUserName
        usrID = selectLongFromBase(cn, "usr", "usrID", "usrLogin", usrName)
        
        
    
    End If
    
    Exit Function

m2:
    If err.Number = 3705 Then ' уже открыто
        tryToConnectDB = True
    End If

End Function




Public Sub reloadAllData()

    srtm(6) = 408
    srtm(8) = 409
    srtm(10) = 410
    srtm(12) = 411
    srtm(14) = 412
    srtm(16) = 413
    srtm(18) = 414
    srtm(20) = 415
    srtm(22) = 416
    srtm(25) = 417
    srtm(28) = 418
    srtm(32) = 419
    srtm(36) = 420
    srtm(40) = 421
    srtm(45) = 422
    srtm(50) = 423
    srtm(55) = 424


    Set bars = New Collection
    Set refsAll = New Collection
    Set hides = New Collection
    
    CadInputQueue.SendMessageToApplication "rein", "reload"
    
    Set refsAll = SortCollection(refsAll)

End Sub



Public Function roundDis(v As Double, dis As Double) As Double


    v = v + dis / 2#
    v = v / dis
    v = Int(v)
    v = v * dis

    roundDis = v

End Function


'/////////////////////////////////////////////////////////////////////////////////
Public Function writeOperationS(operID As oper, strObjName As String, objectID As Long, Optional sWhat As String = "") As Long


    On Error GoTo writeOperationS_ERR


    Dim objID As Long
    
    objID = objs(strObjName)
    
    If objID > 0 Then
        writeOperationS = writeOperationL(operID, objID, objectID, sWhat)
    Else
        writeOperationS = 0
    End If

Exit Function

writeOperationS_ERR:
    writeOperationS = 0

End Function

'/////////////////////////////////////////////////////////////////////////////////
Public Function writeOperationL(operID As Long, objID As Long, objectID As Long, Optional sWhat As String = "") As Long


    On Error GoTo writeOperationL_ERR

    If usrID = 0 Then Exit Function


    Dim RS As New ADODB.Recordset
    
    Dim arFields(5) As Variant
    Dim arValues(5) As Variant
    Dim dat As Date
    
    RS.Open "select top 1 *, getdate() as tm from operationslog order by operID desc", cn, adOpenForwardOnly, adLockOptimistic
    
    If Not RS.EOF Then
        RS.MoveFirst
        dat = RS.Fields("tm").Value
    Else
        dat = Now
    End If
    
    arFields(0) = "oplogDate"
    arFields(1) = "operID"
    arFields(2) = "objID"
    arFields(3) = "objectID"
    arFields(4) = "usrID"
    arFields(5) = "what"
    
    arValues(0) = dat
    arValues(1) = operID
    arValues(2) = objID
    arValues(3) = objectID
    arValues(4) = usrID
    arValues(5) = sWhat
    
    
    RS.AddNew arFields, arValues
    
    RS.Update
    
    RS.Requery
    
    RS.MoveFirst
    
    writeOperationL = RS.Fields("operID").Value
    
    RS.Close
    Set RS = Nothing
    

Exit Function

writeOperationL_ERR:

    writeOperationL = 0

End Function


'/******************************************************************************
Public Function GetThreadUserName() As String
'/******************************************************************************
    
    ' Dimension variables
    Dim lpBuff As String * 25
    Dim Ret As Long
    
    ' Get the user name minus any trailing spaces found in the name.
    Ret = GetUserName(lpBuff, 25)
    GetThreadUserName = Left(lpBuff, InStr(lpBuff, Chr(0)) - 1)
    
End Function


'/******************************************************************************
Public Function selectLongFromBase(conn As ADODB.Connection, strTable As String, strFieldToReturn As String, _
                                   strWhereField As String, whereFieldValue As Variant, _
                                   Optional strWhereField2 As String = "", Optional whereFieldValue2 As Variant = Empty _
                                   ) As Long
'/******************************************************************************
    
    On Error GoTo m100
    
    Dim RS As New ADODB.Recordset
    
    Dim strSQL As String
    
    strSQL = "select " & strFieldToReturn & " from [" & strTable & "] where [" & strWhereField & "] = "
    
    If TypeName(whereFieldValue) = "String" Then
        strSQL = strSQL & "'" & Trim(whereFieldValue) & "'"
    Else
        strSQL = strSQL & whereFieldValue
    End If
    
    If Not IsEmpty(whereFieldValue2) Then
    
        strSQL = strSQL & " and [" & strWhereField2 & "] = "
        
        If TypeName(whereFieldValue2) = "String" Then
            strSQL = strSQL & "'" & Trim(whereFieldValue2) & "'"
        Else
            strSQL = strSQL & whereFieldValue2
        End If
    End If
    
    RS.Open strSQL, conn, adOpenForwardOnly, adLockReadOnly
    
    If RS.EOF Then GoTo m100
    
    RS.MoveFirst
    
    selectLongFromBase = RS.Fields(strFieldToReturn).Value
    
    
    
    Exit Function
m100:
    selectLongFromBase = 0
    
    
End Function

'/******************************************************************************
' функция должна соответствовать одноименной в Offtake (библиотека?)
Public Function armCalcPointsFromDraw(pos As clsBar, bAlt As Boolean) As Boolean
'/******************************************************************************

    On Error GoTo calcPoints_ERR

    Dim p1(0 To 1) As Point2d
    Dim p2(0 To 1) As Point2d
    
    Dim p As Point2d
    Dim pMain As Point2d
    
    
    Dim dAn As Double

    If pos Is Nothing Then Exit Function

    If pos.pointsDraw.Count < 2 Then
        Exit Function
    End If
    
    Dim pts As New Collection
    Dim pts_rev As New Collection
    Dim pts_rem As New Collection
    Dim pts_cmp As Collection ' ссылка для создания массива точек для сравнения
    
    If bAlt Then
        pMain = pos.pointsDraw(pos.pointsDraw.Count) ' конечная
        Set pos.pointsCompAlt = New Collection
        Set pts_cmp = pos.pointsCompAlt
    Else
        pMain = pos.pointsDraw(1) ' начальная
        Set pos.pointsComp = New Collection
        Set pts_cmp = pos.pointsComp
    End If
    
    
    
    ' получаем массив точек
    '===================================
    
    Dim i As Integer
    
    For i = 1 To pos.pointsDraw.Count
    
        p = pos.pointsDraw(i)
        
        p.X = p.X - pMain.X
        p.Y = p.Y - pMain.Y
        
        pts.Add p
    
    Next i
    
    If bAlt Then
    
        For i = pts.Count To 1 Step -1
            p = pts(i)
            
            pts_rev.Add p
        Next i
        
        Set pts = Nothing
        
        Set pts = pts_rev
    
    End If
    
    ' получаем угол наклона
    
    p1(0) = pts(1)
    p1(1) = pts(2)

    p2(0).X = 0
    p2(0).Y = 0
    p2(1).X = 1000
    p2(1).Y = 0
    
    dAn = getAngle(p1, p2)
    
    ' поворачиваем точки
    
    For i = 1 To pts.Count
    
        p.X = getDbl(FormatNumber(pts(i).X * Cos(dAn) - pts(i).Y * Sin(dAn), 0))
        p.Y = getDbl(FormatNumber(pts(i).X * Sin(dAn) + pts(i).Y * Cos(dAn), 0))
    
        pts_rem.Add p
        
    Next i
    
    
    
    Dim pRem As Point2d
    
    Dim pp(0 To 1) As Point2d
    pp(0) = pts_rem(pos.iMain + 2)
    pp(1) = pts_rem(pos.iMain + 1)
    
    pRem = Point2dSubtract(pp(0), pp(1))
    
    For i = 1 To pts_rem.Count
    
        Dim ppp As Point2d
        
        ppp = pts_rem(i)
        
        If pos.bCont And i > pos.iMain + 1 Then
            ppp = Point2dSubtract(ppp, pRem)
        End If
        
        pts_cmp.Add ppp
    
    Next i
        
    
    
    
    Set pts = Nothing
    Set pts_rem = Nothing
    
    
    armCalcPointsFromDraw = True

Exit Function

calcPoints_ERR:
'    MsgBox "[" & err.Number & "] " & err.Description, vbInformation, "calcPoints - Error"

End Function





'/******************************************************************************
Public Function armCalcPointsFromDraw_old(pos As clsBar) As Boolean
'/******************************************************************************

    On Error GoTo calcPoints_ERR

    Dim p1(0 To 1) As Point2d
    Dim p2(0 To 1) As Point2d
    
    Dim p As Point2d
    Dim pMain As Point2d
    
    Dim dAn As Double

    If pos Is Nothing Then Exit Function

    If pos.pointsDraw.Count < 2 Then
        Exit Function
    End If
    
    Dim pts As New Collection
    
    
    pMain = pos.pointsDraw(1)
    
    ' получаем массив точек
    '===================================
    
    Dim i As Integer
    
    For i = 1 To pos.pointsDraw.Count
    
        p = pos.pointsDraw(i)
        
        p.X = p.X - pMain.X
        p.Y = p.Y - pMain.Y
        
        pts.Add p
    
    Next i
    
    ' получаем угол наклона
    '===================================
    
    p1(0) = pts(1)
    p1(1) = pts(2)

    p2(0).X = 0
    p2(0).Y = 0
    p2(1).X = 1000
    p2(1).Y = 0
    
    dAn = getAngle(p1, p2)
    
    
    
    ' поворачиваем точки
    '===================================
    
    Set pos.pointsComp = New Collection
    
    For i = 1 To pts.Count
    
        p.X = getDbl(FormatNumber(pts(i).X * Cos(dAn) - pts(i).Y * Sin(dAn), 0))
        p.Y = getDbl(FormatNumber(pts(i).X * Sin(dAn) + pts(i).Y * Cos(dAn), 0))
    
        pos.pointsComp.Add p
        
    Next i

    armCalcPointsFromDraw = True

Exit Function

calcPoints_ERR:
'    MsgBox "[" & err.Number & "] " & err.Description, vbInformation, "calcPoints - Error"

End Function


Public Function getAngle(p1() As Point2d, p2() As Point2d)

    
    Dim cs, ss As Double
    Dim x1, x2, y1, y2 As Double
    
    x1 = p1(1).X - p1(0).X
    y1 = p1(1).Y - p1(0).Y
    
    x2 = p2(1).X - p2(0).X
    y2 = p2(1).Y - p2(0).Y
    
    cs = (x1 * x2 + y1 * y2) / Sqr((x1 * x1 + y1 * y1) * (x2 * x2 + y2 * y2))
    
    If cs > 0 And cs <= 1# Then
        cs = Atn(Sqr(1 - cs ^ 2) / cs)
    ElseIf cs < 0 And cs >= -1# Then
        cs = Pi + Atn(Sqr(1 - cs ^ 2) / cs)
    Else
        cs = 2 * Atn(1)
    End If
    
    
    ss = x1 * y2 - y1 * x2
    
    If ss < 0 Then cs = -1 * cs
    
    getAngle = cs

End Function



'/******************************************************************************
Public Function GetPOS_LAP(diam As Integer, Optional armclassID As Integer = 3) As Offtmisc.clsArmLap
'/******************************************************************************

    On Error GoTo getLap_ERR

    Dim lap As New Offtmisc.clsArmLap
    
    lap.projectID = lngCurProjectID
    lap.betonID = 0
    lap.classID = armclassID
    lap.diameter = diam
    
    Set GetPOS_LAP = globLaps(lap.Key)
    
    If GetPOS_LAP.Key = "000.000.000.000" Then
    
        lap.projectID = 0
        lap.betonID = 0
        lap.classID = armclassID
        lap.diameter = diam
        
        Set GetPOS_LAP = globLaps(lap.Key)
    
    End If
    
    Set lap = Nothing

Exit Function

getLap_ERR:
    Set GetPOS_LAP = New Offtmisc.clsArmLap

End Function



Public Sub loadBaseData()


    Dim RS As New ADODB.Recordset
    
    RS.Open "select * from object", cn, adOpenForwardOnly, adLockReadOnly
    If Not RS.EOF Then
        Set objs = New Collection
        RS.MoveFirst
        Do
            Dim objID As Long
            objID = RS.Fields("objID").Value
            objs.Add objID, Trim(RS.Fields("objName").Value)
            RS.MoveNext
        Loop Until RS.EOF
    End If




    RS.NextRecordset


    Set globLaps = New Offtmisc.colArmLap

    RS.Open "select * from rein_laps", cn, adOpenForwardOnly, adLockReadOnly
    If Not RS.EOF Then
        RS.MoveFirst
        Do
            
            Dim lap As New Offtmisc.clsArmLap
            
            If lap.loadLap(Nothing, RS) Then
                globLaps.addLap lap
            End If
            
            Set lap = Nothing
            
            RS.MoveNext
        Loop Until RS.EOF
    End If

    RS.Close
    Set RS = Nothing

End Sub


Public Sub mdlGetCatID() ' NOT USING


    lngCurCatalogID = 0
    lngCurProjectID = 0
    strProjName = ""
    strBlockNumber = ""
    strBuildingCode = ""
    catName = ""

    Dim catID As Long
    Dim oScanCriteria As ElementScanCriteria
    Set oScanCriteria = New ElementScanCriteria
    
    oScanCriteria.ExcludeAllTypes
    oScanCriteria.IncludeType msdElementTypeMicroStation


    Dim oScanEnumerator As ElementEnumerator
    Set oScanEnumerator = ActiveModelReference.Scan(oScanCriteria)

    Dim ele As Element
    Dim ae As ApplicationElement


    Do While oScanEnumerator.MoveNext
    
        Set ele = oScanEnumerator.Current
        
        If ele.Subtype = msdElementSubtypeApplicationElement Then
        
            Set ae = ele.AsApplicationElement
            
            If ae.ApplicationID = appID Then
            
                Dim dbOut As DataBlock
                
                Set dbOut = ae.GetApplicationData
                
                dbOut.CopyLong catID, False
                
                lngCurCatalogID = catID
                
                If tryToConnectDB() And lngCurCatalogID > 0 Then
                
                    Call getProjID(Nothing, lngCurCatalogID, "r_object_catalog", "catalogID")
                
                End If
                
                If selectLongFromBase(cn, "rein_laps", "lapID", "projectID", lngCurProjectID) > 0 Then
                    SetCExpressionValue "iOfftProjID", lngCurProjectID, "rein"
                Else
                    SetCExpressionValue "iOfftProjID", 0, "rein" ' use default lap settings
                End If

                SetCExpressionValue "iOfftCatID", catID, "rein"
                
                
'                Dim lp As clsArmLap
'                For Each lp In globLaps
'                    If lp.projectID = lngCurProjectID Then
'                        SetCExpressionValue "iLapMaxLen", lp.maxlen, "rein"
'                        Exit For
'                    End If
'                nexr lp
            
            End If
        
        End If
        
    Loop

End Sub


Public Sub mdlSelectPosRow()

    On Error GoTo err

    Dim pos_numb As Integer
    pos_numb = GetCExpressionValue("curPos_numb", "rein") ' zero based index in pos array
    
    If Not f Is Nothing Then
    
        f.selectPosRow pos_numb + 1 ' zero based index to arnum
        
    
    End If
    
    
    Exit Sub
err:


End Sub


Public Sub addMuftQty()


    Dim ar0() As String

    ar0 = Split(Application.KeyinArguments, ";")
    
    If UBound(ar0) <> 4 Then Exit Sub
    
    Dim iType As Integer
    Dim iDiam1 As Integer
    Dim iDiam2 As Integer
    Dim iMuftType As Integer
    Dim qty As Long
    Dim sType As String
    Dim sDiam As String
    
    iType = Val(ar0(0))
    iDiam1 = Val(ar0(1))
    iDiam2 = Val(ar0(2))
    qty = Val(ar0(3))
    iMuftType = Val(ar0(4))
    
    
    If iType = 3 Then sType = "муфта"
    If iType = 4 Then sType = "скоба"
    If iType = 0 Then sType = "накладка"
    
    If iDiam1 <> iDiam2 Then
        sType = sType & " пер."
        sDiam = iDiam1 & " / " & iDiam2
    Else
        sDiam = iDiam1
    End If
    
    If iMuftType = 1 Then sType = sType & " (п)"
    If iMuftType = 2 Then sType = sType & " (пс)"
        
    Dim R As Long
    
    fm.FG.AddItem sType & vbTab & sDiam & vbTab & qty
    fm.FG.IsSubtotal(fm.FG.Rows - 1) = True
    fm.FG.RowOutlineLevel(fm.FG.Rows - 1) = 1
    R = fm.FG.Rows - 1
    
    fm.FG.ColAlignment(1) = flexAlignLeftCenter
    
    Dim mft As clsMuft
    
    For Each mft In fm.colMufts
        If mft.iDiam1 = iDiam1 And mft.iDiam2 = iDiam2 And mft.iType = iType And mft.iMuftType = iMuftType Then
            fm.FG.AddItem vbTab & mft.pointX & vbTab & mft.pointY & vbTab & mft.pointZ
            fm.FG.IsSubtotal(fm.FG.Rows - 1) = True
            fm.FG.RowOutlineLevel(fm.FG.Rows - 1) = 2
            If mft.bByLap Then fm.FG.Cell(flexcpBackColor, fm.FG.Rows - 1, 0, fm.FG.Rows - 1, fm.FG.Cols - 1) = &HE0E0E0
        End If
    Next mft
    
    fm.FG.IsCollapsed(R) = flexOutlineCollapsed
    


End Sub

Public Sub showMuftQty()


    Dim R As Long
    Dim mft As clsMuft

    fm.FG.AddItem "ошибки"
    fm.FG.IsSubtotal(fm.FG.Rows - 1) = True
    fm.FG.RowOutlineLevel(fm.FG.Rows - 1) = 1
    R = fm.FG.Rows - 1
    
    For Each mft In fm.colMufts
        If mft.pmqty > 1 Or mft.errs > 0 Then
            fm.FG.AddItem vbTab & mft.pointX & vbTab & mft.pointY & vbTab & mft.pointZ
            fm.FG.IsSubtotal(fm.FG.Rows - 1) = True
            fm.FG.RowOutlineLevel(fm.FG.Rows - 1) = 2
        End If
    Next mft
    
    
    fm.FG.IsCollapsed(R) = flexOutlineCollapsed



    fm.FG.AutoSize 0, fm.FG.Cols - 1
    fm.Show 0

End Sub


Public Sub showMuftAll()

    Dim ar0() As String

    ar0 = Split(Application.KeyinArguments, ";")

    If UBound(ar0) <> 3 Then Exit Sub
    
    fm.lblErrs.Caption = "муфт: " & Val(ar0(0)) & _
                        " (" & lngMuftEndQty & "+" & lngMuftLapQty & "=" & _
                        lngMuftEndQty + lngMuftLapQty & ")" & vbNewLine & _
                        "скоб: " & Val(ar0(1)) & vbNewLine & _
                        "накладок: " & Val(ar0(2)) & vbNewLine & _
                        "ошибок: " & Val(ar0(3))
                        

End Sub
Public Sub showMuftInit()

    Set fm = New frmRep
    fm.FG.Rows = 1
    
    lngMuftEndQty = 0
    lngMuftLapQty = 0
    

End Sub


Public Sub addMuftUnit()

    Dim ar0() As String
    Dim sDiam As String

    ar0 = Split(Application.KeyinArguments, ";")

    If UBound(ar0) <> 9 Then Exit Sub
    
    Dim mft As New clsMuft
    
    mft.iDiam1 = Val(ar0(0))
    mft.iDiam2 = Val(ar0(1))
    
    mft.pmqty = Val(ar0(2))
    
    mft.iType = Val(ar0(3))
    mft.iMuftType = Val(ar0(4))
    
    mft.bByLap = CBool(Val(ar0(5)))
    
    
    mft.pointX = Val(ar0(6))
    mft.pointY = Val(ar0(7))
    mft.pointZ = Val(ar0(8))
    
    mft.errs = Val(ar0(9))
    
    '==============================
    
    If mft.iType = 3 Then
        mft.sType = "муфта"
        If mft.bByLap Then
            lngMuftLapQty = lngMuftLapQty + 1
        Else
            lngMuftEndQty = lngMuftEndQty + 1
        End If
    End If
    If mft.iType = 4 Then mft.sType = "скоба"
    If mft.iType = 0 Then mft.sType = "накладка"
    
    If mft.iDiam1 <> mft.iDiam2 Then
        mft.sType = mft.sType & " пер."
        mft.sDiam = mft.iDiam1 & " / " & mft.iDiam2
    Else
        mft.sDiam = mft.iDiam1
    End If
    
    If mft.iMuftType = 1 Then mft.sType = mft.sType & " (п)"
    If mft.iMuftType = 2 Then mft.sType = mft.sType & " (пс)"
    
    '==============================
    
    
    
    fm.colMufts.Add mft
    
    Set mft = Nothing


End Sub


'/******************************************************************************
Public Function correctPartName(strPartName As String) As String
'/******************************************************************************

    On Error GoTo correctPartName_ERR

    Dim strName As String
    
    strName = strPartName

    Dim alpE As String
    Dim alpR As String
    Dim i As Integer
    
    alpE = "ABCEHKMOPTXaceopx" ' english
    alpR = "АВСЕНКМОРТХасеорх" ' russian
    
    For i = 1 To Len(alpE)
        strName = Replace(strName, Mid(alpR, i, 1), Mid(alpE, i, 1), , , vbBinaryCompare)
    Next i
    
    correctPartName = Trim(strName)




Exit Function

correctPartName_ERR:
    correctPartName = strPartName


End Function



Public Function getTaskFile() As String

On Error GoTo m1

    Dim strExcelFile As String


    Dim OFN As OPENFILENAME
    OFN.lStructSize = Len(OFN)
    OFN.lpstrFilter = "Grid Files (*.grid)" + Chr$(0) + "*.grid" + Chr$(0) + "All Files (*.*)" + Chr$(0) + "*.*" + Chr$(0)
    OFN.lpstrFile = Space$(254)
    OFN.nMaxFile = 255
    OFN.lpstrFileTitle = Space$(254)
    OFN.nMaxFileTitle = 255
    OFN.lpstrInitialDir = CurDir
    OFN.lpstrTitle = "Открываем файл с муфтами"
    OFN.flags = 0
    Dim a As Long
    
    a = GetOpenFileName(OFN)
        
    If a > 0 Then
        strExcelFile = LCase(Trim$(OFN.lpstrFile))
        If Right(strExcelFile, 1) = Chr(0) Then strExcelFile = Left(strExcelFile, Len(strExcelFile) - 1)
    Else
        strExcelFile = ""
    End If
    
    getTaskFile = strExcelFile

Exit Function

m1:
MsgBox err.Description, vbCritical, err.Number

End Function


Public Function SortCollection(ByVal c As Collection) As Collection
   Dim n As Long: n = c.Count
   If n = 0 Then Set SortCollection = New Collection: Exit Function
   ReDim Index(0 To n - 1) As Long                    ' allocate index array
   Dim i As Long, m As Long
   For i = 0 To n - 1: Index(i) = i + 1: Next         ' fill index array
   For i = n \ 2 - 1 To 0 Step -1                     ' generate ordered heap
      Heapify c, Index, i, n
      Next
   For m = n To 2 Step -1                             ' sort the index array
      Exchange Index, 0, m - 1                        ' move highest element to top
      Heapify c, Index, 0, m - 1
      Next
   Dim c2 As New Collection
   For i = 0 To n - 1: c2.Add c.Item(Index(i)): Next  ' fill output collection
   Set SortCollection = c2
End Function

Private Sub Heapify(ByVal c As Collection, Index() As Long, ByVal i1 As Long, ByVal n As Long)
   ' Heap order rule: a[i] >= a[2*i+1] and a[i] >= a[2*i+2]
   Dim nDiv2 As Long: nDiv2 = n \ 2
   Dim i As Long: i = i1
   Do While i < nDiv2
      Dim k As Long: k = 2 * i + 1
      If k + 1 < n Then
         If c.Item(Index(k)) < c.Item(Index(k + 1)) Then k = k + 1
         End If
      If c.Item(Index(i)) >= c.Item(Index(k)) Then Exit Do
      Exchange Index, i, k
      i = k
      Loop
End Sub

Private Sub Exchange(Index() As Long, ByVal i As Long, ByVal J As Long)
   Dim Temp As Long: Temp = Index(i)
   Index(i) = Index(J)
   Index(J) = Temp
End Sub
