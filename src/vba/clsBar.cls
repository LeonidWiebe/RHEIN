VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END
Attribute VB_Name = "clsBar"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public partID As Long
Public posID As Long
Public partdefID As Long

Public pcatID As Long

Public poslen As Double

Public file_qty_rm As Double
Public file_qty_p As Long

Public numpos As Integer


Public file_ms_min As Double
Public file_ms_mid As Double
Public file_ms_max As Double

Public base_ms_min As Double
Public base_ms_mid As Double
Public base_ms_max As Double

Public diam As Integer
Public bend_rad As Integer
Public refnum As Long

Public srtmID As Long
Public posdefID As Long


Public bFromBase As Boolean

Public pointsComp As Collection
Public pointsCompAlt As Collection
Public pointsDraw As Collection
Public pointIsArc As Collection
Public iMain As Integer

Public IDs As Collection
Public FPs As Collection
Public refs As Collection


Public file_len_min As Double
Public file_len_mid As Double
Public file_len_max As Double

Public base_length As Double
Public base_qty As Double

Public bCont As Boolean ' при сравнении не учитывается длина основного сегмента
Public bRunMet As Boolean
Public bSketch As Boolean
'Public bLap As Boolean ' разбежка
Public iArmLapQty As Integer ' кол. нахлестов на позицию
Public iArmMuftQty As Integer ' кол. муфт на позицию

Public eltype As MsdElementType

Public rad As Integer

Public sName As String

Public dTol As Double

Public termBegType As Long
Public termBegPar0 As Long
Public termBegPar1 As Long

Public termEndType As Long
Public termEndPar0 As Long
Public termEndPar1 As Long

Public bHide As Boolean
Public bHide_V As Boolean
Public bHide_X As Boolean
Public bHide_O As Boolean
Public bHide_S As Boolean

Public arnum As Integer

Private Sub Class_Initialize()


Set pointsComp = New Collection
Set pointsCompAlt = New Collection
Set pointsDraw = New Collection
Set pointIsArc = New Collection

Set IDs = New Collection
Set FPs = New Collection
Set refs = New Collection

dTol = 5#


End Sub

Private Sub Class_Terminate()

Set pointsComp = Nothing
Set pointsCompAlt = Nothing
Set pointsDraw = Nothing
Set pointIsArc = Nothing

Set IDs = Nothing
Set FPs = Nothing

Set refs = Nothing

End Sub

'Public Sub addRefNum(iRefNum As Long)
'
'    Dim I As Integer
'
'    For I = 1 To refs.Count
'        If CLng(refs(I)) = iRefNum Then Exit Sub
'    Next I
'
'    refs.Add iRefNum
'
'End Sub
'
'
'Public Sub addID(sID As String, numref As Long) ' NU
'
'    Dim I As Integer
'
'    If Len(Trim(sID)) = 0 Then Exit Sub
'
'    Dim el As New clsElem
'    Dim ele As clsElem
'    Dim bExists As Boolean
'
'    el.ID = CLng(sID)
'    el.numref = numref
'
'    For I = 1 To IDs.Count
'        Set ele = IDs(I)
'        If ele.ID = el.ID And ele.numref = el.numref Then bExists = True: Exit For
'    Next I
'
'    If Not bExists Then IDs.Add el
'
'    Set el = Nothing
'
'End Sub
'
'
'Public Sub addFPs(sFP As String, numref As Long) ' NU
'
'    Dim I As Integer
'    Dim J As Integer
'    Dim arfp() As String
'
'    If Len(Trim(sFP)) = 0 Then Exit Sub
'
'
'    Dim ele As clsElem
'    Dim bExists As Boolean
'
'
'
'    arfp = Split(sFP, ",")
'
'    For J = LBound(arfp) To UBound(arfp)
'
'        Dim el As New clsElem
'        el.fp = CLng(arfp(J))
'        el.numref = numref
'
'        If el.fp > 0 Then
'
'            bExists = False
'            For I = 1 To FPs.Count
'                Set ele = FPs(I)
'                If ele.fp = el.fp And ele.numref = el.numref Then bExists = True: Exit For
'            Next I
'
'            If Not bExists Then FPs.Add el
'
'        End If
'
'        Set el = Nothing
'
'    Next J
'
'
'
'End Sub



Public Function savePart(bNewIfNotExists As Boolean, bSavePoints As Boolean) As Boolean


    If numpos = 0 Then Exit Function

    Dim RSpart As New ADODB.Recordset
    Dim bNew As Boolean
    

'    RSpart.Open "select * from part where partID = " & partID, cn, adOpenForwardOnly, adLockOptimistic
    RSpart.Open "select * from part where partName = " & Me.numpos & _
                                " and catID = " & lngCurCatalogID & _
                                " and deleted = 0", _
                                cn, adOpenForwardOnly, adLockOptimistic
    
    If RSpart.EOF Then
        If bNewIfNotExists Then RSpart.AddNew Else GoTo out
        bNew = True
        RSpart.Fields("partName").Value = numpos
        RSpart.Fields("catID").Value = lngCurCatalogID
    Else
        RSpart.MoveFirst
        partID = RSpart.Fields("partID").Value
    End If
    
    RSpart.Fields("partdefID").Value = Me.partdefID
    RSpart.Fields("partSortNumber").Value = Format(numpos, "00000")
    
    RSpart.Update
    
    
    
    If partID = 0 Then
    
        RSpart.NextRecordset
        RSpart.Open "select top 1 * from part order by partID desc", cn, adOpenForwardOnly, adLockOptimistic
        RSpart.Requery
        RSpart.MoveFirst
        partID = RSpart.Fields("partID").Value
        
    End If
    
'    If posID = 0 Then
        
        ' точки
        If bSavePoints And pointsComp.Count > 0 Then
        
            Dim cmd As New ADODB.Command
            cmd.ActiveConnection = cn
            cmd.CommandText = "delete from r_part_reinpoints where partID = " & partID
            cmd.CommandType = adCmdText
            cmd.Execute
        
        
        
            RSpart.NextRecordset
            RSpart.Open "select * from r_part_reinpoints where partID = " & partID, cn, adOpenForwardOnly, adLockOptimistic
        
            Dim pt As Point2d
            Dim pta As Point2d
            Dim ptd As Point2d
            Dim i As Integer
            
            For i = 1 To pointsComp.Count
                pt = pointsComp(i)
                pta = pointsCompAlt(i)
                ptd = pointsDraw(i)
                RSpart.AddNew
                RSpart.Fields("partID").Value = partID
                RSpart.Fields("x").Value = pt.X
                RSpart.Fields("y").Value = pt.Y
                RSpart.Fields("xa").Value = pta.X
                RSpart.Fields("ya").Value = pta.Y
                RSpart.Fields("xd").Value = ptd.X
                RSpart.Fields("yd").Value = ptd.Y
                RSpart.Fields("isOk").Value = True
                If Me.iMain = i - 1 Then
                    RSpart.Fields("isMain").Value = True
                    RSpart.Fields("isCont").Value = Me.bCont
                End If
                RSpart.Fields("onArc").Value = CBool(pointIsArc(i))
                RSpart.Update
            Next i
            
            
'            Dim lp As Offtmisc.clsArmLap
'            Set lp = GetPOS_LAP(Me.diam)
            
            RSpart.NextRecordset
            RSpart.Open "select * from r_part_reinsketch where partID = " & partID, cn, adOpenForwardOnly, adLockOptimistic
            If RSpart.EOF Then
                RSpart.AddNew
            Else
                RSpart.MoveFirst
            End If
            
            If Me.termBegType = 1 Then
                RSpart.Fields("sketchStartAngle").Value = Me.termBegPar0
                RSpart.Fields("sketchStartLength").Value = Me.termBegPar1
'                    RSpart.Fields("sketchStartLength").Value = lp.getBendWork
            End If
            If Me.termEndType = 1 Then
                RSpart.Fields("sketchEndAngle").Value = Me.termEndPar0
                RSpart.Fields("sketchEndLength").Value = Me.termEndPar1
'                    RSpart.Fields("sketchEndLength").Value = lp.getBendWork
            End If
            
            RSpart.Fields("sketchStartType").Value = Me.termBegType
            RSpart.Fields("sketchEndType").Value = Me.termEndType
            RSpart.Fields("partID") = partID
            
            RSpart.Update
            
            
            
        End If
'    End If
    
    If bNew Then
        writeOperationS operCreate, "part", partID, "создание позиции " & numpos
    Else
        writeOperationS operModify, "part", partID, "изменение позиции " & numpos
    End If
    
    savePart = True
    RSpart.Close
    
out:
    
    

    Set RSpart = Nothing


End Function

Public Function savePos(bNewIfNotExists As Boolean) As Boolean




    If srtmID = 0 Then Exit Function
    Dim dQty As Double
    
    Dim RSpos As New ADODB.Recordset
    
    RSpos.Open "select * from position where posID = " & posID, cn, adOpenForwardOnly, adLockOptimistic
        
    If RSpos.EOF Then
        If bNewIfNotExists Then RSpos.AddNew Else RSpos.Close: GoTo out
    Else
        RSpos.MoveFirst
    End If
    
    If Me.diam >= 12 Then
        RSpos.Fields("matID").Value = 12 ' временно
    Else
        RSpos.Fields("matID").Value = 11 ' временно
    End If
        
    RSpos.Fields("partID").Value = partID
    RSpos.Fields("srtmID").Value = srtmID
    RSpos.Fields("posQuantity").Value = Round(Me.base_qty, 1)
    If RSpos.Fields("posUMCalc").Value Then RSpos.Fields("posUnitMass").Value = 0
    If RSpos.Fields("posCMCalc").Value Then RSpos.Fields("posCommonMass").Value = 0
    RSpos.Update
        
        
    If posID = 0 Then
        RSpos.NextRecordset
        RSpos.Open "select top 1 * from position order by posID desc", cn, adOpenForwardOnly, adLockOptimistic
        RSpos.Requery
        RSpos.MoveFirst
        posID = RSpos.Fields("posID").Value
        writeOperationS operCreate, "position", posID, "создание позиции из MicroStation"
    End If
        
        
    writeOperationS operModify, "position", posID, "назначение диаметра " & diam & " и количества " & Me.base_qty
        
        
    ' длина
    '================================
    RSpos.NextRecordset
    
    RSpos.Open "select * from r_position_property where posID = " & posID, cn, adOpenForwardOnly, adLockOptimistic
    
    
    Dim bUpd As Boolean
        
    If Not RSpos.EOF Then
        RSpos.MoveFirst
        If bRunMet Then
            RSpos.Fields("length").Value = Null
            writeOperationS operModify, "position", posID, "обнуление длины (п.м.)"
            bUpd = True
        Else
            RSpos.Fields("length").Value = Me.base_length
            writeOperationS operModify, "position", posID, "назначение длины " & Me.base_length
            bUpd = True
        End If
    Else
        If bRunMet Then
            ' нет и добавлять не нужно
        Else
            RSpos.AddNew
            RSpos.Fields("length").Value = Me.base_length
            RSpos.Fields("posID").Value = posID
            writeOperationS operModify, "position", posID, "назначение длины " & Me.base_length
            bUpd = True
        End If
    End If
    
    
    If rad > 0 Then
        If RSpos.EOF Then RSpos.AddNew
        RSpos.Fields("radiusinn").Value = rad
        RSpos.Fields("posID").Value = posID
        writeOperationS operModify, "position", posID, "назначение радиуса изгиба арматуры " & rad
        bUpd = True
    End If
    
    
    If Me.bCont And Me.base_ms_min > 0 And Me.base_ms_max > 0 Then
        If RSpos.EOF Then RSpos.AddNew
        RSpos.Fields("lenmin").Value = Me.base_ms_min
        RSpos.Fields("lenmid").Value = Me.base_ms_mid
        RSpos.Fields("lenmax").Value = Me.base_ms_max
        writeOperationS operModify, "position", posID, "установка диапазона длин главного сегмента"
        bUpd = True
    End If
    

    '================================
            
    If bUpd Then RSpos.Update
            
        
    savePos = True
    RSpos.Close

out:
    Set RSpos = Nothing

End Function






