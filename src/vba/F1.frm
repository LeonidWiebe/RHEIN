VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} F1 
   Caption         =   "UserForm1"
   ClientHeight    =   9930
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   11640
   OleObjectBlob   =   "F1.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "F1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit




Private Sub btnFind_Click()

' осталось от кнопки " >>> Перейти на строку выделенного элемента"


    FG.Row = -1

    CadInputQueue.SendMessageToApplication "rein", "getelem"


End Sub

Private Sub btnReload_Click()

On Error GoTo err

    Dim tr As Long
    Dim R As Long
    tr = Me.FG.TopRow
    R = Me.FG.Row
    
    bFormLoaded = True

    reloadDataAndGrid

    If tr > Me.FG.Rows - 1 Then tr = Me.FG.Rows - 1
    If R > Me.FG.Rows - 1 Then R = Me.FG.Rows - 1

    Me.FG.TopRow = tr
    Me.FG.Row = R

err:

End Sub


Public Sub fillCombo()

    Dim bar As clsBar
    Dim str As String
    
    Me.cmbRefs.Clear
    
    cmbRefs.AddItem "все"
    
    Dim refn As Long
    
    Dim J As Long

    For J = 1 To refsAll.Count
    
        refn = refsAll(J)
        
        Dim mr As Attachment
        Set mr = getModelRefByRefNumber(refn)

        If refn = 0 Then
            cmbRefs.AddItem "активный"
        ElseIf Not mr Is Nothing Then
            cmbRefs.AddItem mr.LogicalName
        Else
            cmbRefs.AddItem CStr(refn)
        End If


    Next J


End Sub



Public Sub fillGrid(Optional iRefNum As Long = -1)


'    On Error GoTo err
    
    Dim i As Integer
    
    If armCtl Is Nothing Then Exit Sub

    Dim bar As clsBar
    
    FG.redraw = flexRDNone
    

    FG.Rows = 1
    
    Dim bFound As Boolean

    ' заполняем сетку
    For Each bar In bars

    
        
        If iRefNum >= 0 Then
            bFound = False
            Dim refn As Long
            Dim J As Long
            For J = 1 To bar.refs.Count
                refn = bar.refs(J)
                If refn = iRefNum Then
                    bFound = True
                    Exit For
                End If
            Next J
            If Not bFound Then GoTo continue
        End If
        
        If iRefNum > 0 Then
            If bar.file_qty_p = 0 Then GoTo continue
        End If
        

        FG.AddItem ""
        
        ' ====================================
        
        armCtl.Clear
        
        
        armCtl.setR bar.bend_rad
        armCtl.setRForEnds 30
        
        Dim p As Point2d
        For i = 1 To bar.pointsDraw.Count
    
            p = bar.pointsDraw(i)
    
            armCtl.AddPoint p.X, p.Y, p.X, p.Y
    
        Next i
        
        armCtl.bCont = bar.bCont
        
        armCtl.dContMin = bar.base_ms_min
        armCtl.dContMid = bar.base_ms_mid
        armCtl.dContMax = bar.base_ms_max
        armCtl.RArc = bar.rad
        
        armCtl.setMainLine bar.iMain, False ' это операция должна быть после всех!!!
                    
        ' ====================================
        
        If bar.numpos > 0 Then FG.TextMatrix(FG.Rows - 1, FG.ColIndex("numpos")) = bar.numpos
        FG.TextMatrix(FG.Rows - 1, FG.ColIndex("elems")) = bar.IDs.Count
        If bar.diam > 0 Then FG.TextMatrix(FG.Rows - 1, FG.ColIndex("diam")) = bar.diam
        
        If bar.rad > 0 Then
            Dim ofms As New Offtmisc.Misc
            If bar.base_ms_min > 0 Then FG.TextMatrix(FG.Rows - 1, FG.ColIndex("len_min")) = ofms.roundExt(bar.base_ms_min, -1, 5, Val(GetSetting("Offtake2", "RndShift", "iArmSegm", 0)))
            If bar.base_ms_mid > 0 Then FG.TextMatrix(FG.Rows - 1, FG.ColIndex("len_mid")) = ofms.roundExt(bar.base_ms_mid, -1, 5, Val(GetSetting("Offtake2", "RndShift", "iArmSegm", 0)))
            If bar.base_ms_max > 0 Then FG.TextMatrix(FG.Rows - 1, FG.ColIndex("len_max")) = ofms.roundExt(bar.base_ms_max, -1, 5, Val(GetSetting("Offtake2", "RndShift", "iArmSegm", 0)))
        
        Else
            If bar.base_ms_min > 0 Then FG.TextMatrix(FG.Rows - 1, FG.ColIndex("len_min")) = armCtl.getTotalMinLength
            If bar.base_ms_mid > 0 Then FG.TextMatrix(FG.Rows - 1, FG.ColIndex("len_mid")) = armCtl.getTotalLength
            If bar.base_ms_max > 0 Then FG.TextMatrix(FG.Rows - 1, FG.ColIndex("len_max")) = armCtl.getTotalMaxLength
        End If
        
'        If bar.file_qty_rm > 0 Then FG.TextMatrix(fg.Rows - 1, fg.ColIndex("qty_rm")) = bar.file_qty_rm
'        If bar.file_qty_p > 0 Then FG.TextMatrix(fg.Rows - 1, fg.ColIndex("qty_p")) = bar.file_qty_p
        If bar.rad > 0 Then FG.TextMatrix(FG.Rows - 1, FG.ColIndex("rad")) = bar.rad
        FG.TextMatrix(FG.Rows - 1, FG.ColIndex("arnum")) = bar.arnum
        
        
        
        If bar.bRunMet Then
            If bar.base_qty > 0 Then
                FG.TextMatrix(FG.Rows - 1, FG.ColIndex("qty_rm")) = bar.base_qty
                If bar.file_qty_rm > 0 And Round(bar.file_qty_rm, 1) <> Round(bar.base_qty, 1) Then
                    FG.Cell(flexcpForeColor, FG.Rows - 1, FG.ColIndex("qty_rm")) = &HFF&
                End If
            End If
        Else
            If bar.base_qty > 0 Then
                FG.TextMatrix(FG.Rows - 1, FG.ColIndex("qty_p")) = bar.base_qty
                If bar.file_qty_p > 0 And bar.base_qty <> bar.file_qty_p Then
                    FG.Cell(flexcpForeColor, FG.Rows - 1, FG.ColIndex("qty_p")) = &HFF&
                End If
            End If
        End If
        
        
        If bar.base_ms_min > 0 And bar.file_ms_min <> bar.base_ms_min Then
            FG.Cell(flexcpForeColor, FG.Rows - 1, FG.ColIndex("len_min")) = &HFF&
        End If
        If bar.base_ms_mid > 0 And bar.file_ms_mid <> bar.base_ms_mid Then
            FG.Cell(flexcpForeColor, FG.Rows - 1, FG.ColIndex("len_mid")) = &HFF&
        End If
        If bar.base_ms_max > 0 And bar.file_ms_max <> bar.base_ms_max Then
            FG.Cell(flexcpForeColor, FG.Rows - 1, FG.ColIndex("len_max")) = &HFF&
        End If
        
        If bar.base_length > 0 Then
            FG.TextMatrix(FG.Rows - 1, FG.ColIndex("barlen")) = bar.base_length
            If bar.base_length <> bar.file_len_mid Then
                FG.Cell(flexcpForeColor, FG.Rows - 1, FG.ColIndex("barlen")) = &HFF&
            End If
        End If
        
'        If bar.base_qty > 0 Then
'            FG.TextMatrix(fg.Rows - 1, fg.ColIndex("nu1")) = bar.base_qty
'            FG.Cell(flexcpForeColor, fg.Rows - 1, fg.ColIndex("nu1")) = &HFF0000
'        End If
        
        FG.TextMatrix(FG.Rows - 1, FG.ColIndex("srtmID")) = bar.srtmID
        FG.TextMatrix(FG.Rows - 1, FG.ColIndex("posdefID")) = bar.posdefID
        FG.TextMatrix(FG.Rows - 1, FG.ColIndex("points")) = bar.pointsComp.Count
        FG.TextMatrix(FG.Rows - 1, FG.ColIndex("runmet")) = bar.bRunMet
        
        If Not bar.bRunMet Then
            FG.TextMatrix(FG.Rows - 1, FG.ColIndex("sketch")) = bar.bSketch
        Else
            FG.TextMatrix(FG.Rows - 1, FG.ColIndex("sketch")) = False
        End If
        
'        FG.TextMatrix(fg.Rows - 1, fg.ColIndex("lap")) = bar.bLap

        FG.TextMatrix(FG.Rows - 1, FG.ColIndex("cont")) = bar.bCont
        
        FG.Cell(flexcpPictureAlignment, FG.Rows - 1, FG.ColIndex("qty_rm")) = flexPicAlignLeftCenter
        FG.Cell(flexcpPictureAlignment, FG.Rows - 1, FG.ColIndex("qty_p")) = flexPicAlignLeftCenter
        FG.Cell(flexcpPictureAlignment, FG.Rows - 1, FG.ColIndex("save")) = flexPicAlignCenterCenter
        FG.Cell(flexcpPictureAlignment, FG.Rows - 1, FG.ColIndex("infile")) = flexPicAlignCenterCenter
        FG.Cell(flexcpPictureAlignment, FG.Rows - 1, FG.ColIndex("runmet")) = flexPicAlignCenterCenter
        FG.Cell(flexcpPictureAlignment, FG.Rows - 1, FG.ColIndex("sketch")) = flexPicAlignCenterCenter
        
        If bar.bRunMet And bar.base_length > 0 Then
            FG.Cell(flexcpBackColor, FG.Rows - 1, FG.ColIndex("runmet")) = &HC0C0FF
            FG.Cell(flexcpBackColor, FG.Rows - 1, FG.ColIndex("sketch")) = &HC0C0FF
            FG.Cell(flexcpBackColor, FG.Rows - 1, FG.ColIndex("barlen")) = &HC0C0FF
        End If
        
        
        Dim iBeg, iEnd As Integer
        
        iBeg = bar.termBegType
        iEnd = bar.termEndType
        
        If bar.termBegType = 3 Then iBeg = 2 ' муфты не учитываем, оставляем резьбу
        If bar.termEndType = 3 Then iEnd = 2
        
        If bar.termBegType = 4 Then iBeg = 0 ' ванная сварка, накладки не учитываем
        If bar.termEndType = 4 Then iEnd = 0
        
        Dim strTermBeg As String
        Dim strTermEnd As String
        strTermBeg = "term" & iBeg
        strTermEnd = "term" & iEnd
        If iBeg = 1 Then strTermBeg = strTermBeg & "_left"
        If iEnd = 1 Then strTermEnd = strTermEnd & "_right"
        
        FG.Cell(flexcpPicture, FG.Rows - 1, FG.ColIndex("termbeg")) = ImageList1.ListImages(strTermBeg).ExtractIcon
        FG.Cell(flexcpPicture, FG.Rows - 1, FG.ColIndex("termend")) = ImageList1.ListImages(strTermEnd).ExtractIcon
        FG.Cell(flexcpPictureAlignment, FG.Rows - 1, FG.ColIndex("termbeg")) = flexPicAlignCenterCenter
        FG.Cell(flexcpPictureAlignment, FG.Rows - 1, FG.ColIndex("termend")) = flexPicAlignCenterCenter


        If bar.posdefID > 1 Then
            FG.Cell(flexcpForeColor, FG.Rows - 1, 0, , FG.Cols - 1) = &H8000000F
        End If
        
        FG.TextMatrix(FG.Rows - 1, FG.ColIndex("loc")) = 1
        
        FG.IsSubtotal(FG.Rows - 1) = True
        FG.RowOutlineLevel(FG.Rows - 1) = 0
        
            

        FG.Row = FG.Rows - 1
        FG.col = 0
        FG.RowSel = FG.Rows - 1
        FG.ColSel = FG.Cols - 1
        FG.CellBorder RGB(0, 0, 0), 0, 1, 0, 0, 0, 0
        
        FG.TextMatrix(FG.Rows - 1, FG.ColIndex("display")) = False
        FG.TextMatrix(FG.Rows - 1, FG.ColIndex("hide")) = False
        
        
        
        
        FG.Cell(flexcpPicture, FG.Rows - 1, FG.ColIndex("trm_v")) = ImageList1.ListImages("trm_v").ExtractIcon
        FG.Cell(flexcpPicture, FG.Rows - 1, FG.ColIndex("trm_x")) = ImageList1.ListImages("trm_x").ExtractIcon
        FG.Cell(flexcpPicture, FG.Rows - 1, FG.ColIndex("trm_o")) = ImageList1.ListImages("trm_o").ExtractIcon
        FG.Cell(flexcpPicture, FG.Rows - 1, FG.ColIndex("trm_s")) = ImageList1.ListImages("trm_s").ExtractIcon
        FG.TextMatrix(FG.Rows - 1, FG.ColIndex("trm_v")) = 0
        FG.TextMatrix(FG.Rows - 1, FG.ColIndex("trm_x")) = 0
        FG.TextMatrix(FG.Rows - 1, FG.ColIndex("trm_o")) = 0
        FG.TextMatrix(FG.Rows - 1, FG.ColIndex("trm_s")) = 0
        
        
        If getHidePosNum(CStr(bar.numpos) & "|" & getRefNum & "|" & CStr(bar.pcatID)) > 0 Then
        
            Dim br As clsBar
            Set br = getHidePos(CStr(bar.numpos) & "|" & getRefNum & "|" & CStr(bar.pcatID))
            
            FG.TextMatrix(FG.Rows - 1, FG.ColIndex("hide")) = br.bHide
            FG.TextMatrix(FG.Rows - 1, FG.ColIndex("trm_v")) = Abs(CInt(br.bHide_V))
            FG.TextMatrix(FG.Rows - 1, FG.ColIndex("trm_x")) = Abs(CInt(br.bHide_X))
            FG.TextMatrix(FG.Rows - 1, FG.ColIndex("trm_o")) = Abs(CInt(br.bHide_O))
            FG.TextMatrix(FG.Rows - 1, FG.ColIndex("trm_s")) = Abs(CInt(br.bHide_S))
            
            If br.bHide_V Then
            FG.Cell(flexcpPicture, FG.Rows - 1, FG.ColIndex("trm_v")) = ImageList1.ListImages("trn_v").ExtractIcon
            End If
            
            If br.bHide_X Then
            FG.Cell(flexcpPicture, FG.Rows - 1, FG.ColIndex("trm_x")) = ImageList1.ListImages("trn_x").ExtractIcon
            End If
            
            If br.bHide_O Then
            FG.Cell(flexcpPicture, FG.Rows - 1, FG.ColIndex("trm_o")) = ImageList1.ListImages("trn_o").ExtractIcon
            End If
            
            If br.bHide_S Then
            FG.Cell(flexcpPicture, FG.Rows - 1, FG.ColIndex("trm_s")) = ImageList1.ListImages("trn_s").ExtractIcon
            End If
            
        End If
        
        
'        If bar.IDs.Count Then
        If bar.file_qty_p Then
        
            FG.AddItem ""
            FG.Cell(flexcpBackColor, FG.Rows - 1, 0, FG.Rows - 1, FG.Cols - 1) = &HE0E0E0
            FG.Cell(flexcpPicture, FG.Rows - 2, FG.ColIndex("infile")) = ImageList1.ListImages("galka").ExtractIcon
            FG.IsSubtotal(FG.Rows - 1) = True
            FG.RowOutlineLevel(FG.Rows - 1) = 1
            FG.IsCollapsed(FG.Rows - 2) = flexOutlineCollapsed
            
            If bar.file_qty_rm > 0 Then FG.TextMatrix(FG.Rows - 1, FG.ColIndex("qty_rm")) = bar.file_qty_rm
            If bar.file_qty_p > 0 Then FG.TextMatrix(FG.Rows - 1, FG.ColIndex("qty_p")) = bar.file_qty_p
'            FG.TextMatrix(FG.Rows - 1, FG.ColIndex("lap")) = bar.bLap
            FG.TextMatrix(FG.Rows - 1, FG.ColIndex("arnum")) = bar.arnum
            FG.TextMatrix(FG.Rows - 1, FG.ColIndex("loc")) = 2
            
            If bar.iArmLapQty > 0 Then FG.TextMatrix(FG.Rows - 2, FG.ColIndex("qty_lap")) = bar.iArmLapQty
            If bar.iArmMuftQty > 0 Then FG.TextMatrix(FG.Rows - 2, FG.ColIndex("qty_muft")) = bar.iArmMuftQty
            
            If bar.iArmLapQty > 0 Then
                FG.Cell(flexcpFontUnderline, FG.Rows - 2, FG.ColIndex("qty_rm")) = True
                FG.Cell(flexcpFontUnderline, FG.Rows - 1, FG.ColIndex("qty_rm")) = True
            End If
            
            If bar.file_len_min > 0 Then FG.TextMatrix(FG.Rows - 1, FG.ColIndex("len_min")) = bar.file_len_min
            If bar.file_len_mid > 0 Then FG.TextMatrix(FG.Rows - 1, FG.ColIndex("len_mid")) = bar.file_len_mid
            If bar.file_len_max > 0 Then FG.TextMatrix(FG.Rows - 1, FG.ColIndex("len_max")) = bar.file_len_max
            
            If Not bar.bRunMet And bar.file_len_mid > 0 Then
                FG.TextMatrix(FG.Rows - 1, FG.ColIndex("barlen")) = bar.file_len_mid
            End If
            
            
            
'            FG.IsCollapsed(fg.Rows - 2) = flexOutlineCollapsed

            
        
        End If

continue:

    Next bar

    FG.AutoSize 0, FG.Cols - 1
    
    FG.redraw = flexRDBuffered

    
    If FG.Rows < 2 Then Exit Sub

'    FG.Row = 1
'    FG.Col = FG.ColIndex("numpos")
'    FG.RowSel = FG.Rows - 1
'    FG.ColSel = FG.ColIndex("numpos")
'    FG.CellBorder RGB(0, 0, 0), 1, 1, 1, 1, 1, 1
'
'    FG.Row = 1
'    FG.Col = FG.ColIndex("display")
'    FG.RowSel = FG.Rows - 1
'    FG.ColSel = FG.ColIndex("display")
'    FG.CellBorder RGB(0, 0, 0), 1, 1, 1, 1, 1, 1
'
'    FG.Row = 1
'    FG.Col = FG.ColIndex("nu1")
'    FG.RowSel = FG.Rows - 1
'    FG.ColSel = FG.ColIndex("nu1")
'    FG.CellBorder RGB(0, 0, 0), 1, 1, 1, 1, 1, 1
'
'    FG.Row = 1
'    FG.Col = FG.ColIndex("barlen")
'    FG.RowSel = FG.Rows - 1
'    FG.ColSel = FG.ColIndex("barlen")
'    FG.CellBorder RGB(0, 0, 0), 1, 1, 0, 1, 1, 1
    
    
    FG.ColWidth(FG.ColIndex("barlen")) = 1200

    FG.ColWidth(FG.ColIndex("runmet")) = 400
    FG.ColWidth(FG.ColIndex("sketch")) = 400
    FG.ColWidth(FG.ColIndex("lap")) = 400
    FG.ColWidth(FG.ColIndex("cont")) = 400
    FG.ColWidth(FG.ColIndex("display")) = 250
    FG.ColWidth(FG.ColIndex("hide")) = 250
    FG.ColWidth(FG.ColIndex("trm_v")) = 250
    FG.ColWidth(FG.ColIndex("trm_x")) = 250
    FG.ColWidth(FG.ColIndex("trm_o")) = 250
    FG.ColWidth(FG.ColIndex("trm_s")) = 250
    
    FG.ColWidth(FG.ColIndex("termbeg")) = 300
    FG.ColWidth(FG.ColIndex("termend")) = 300
    
    FG.Row = 1
    FG.RowSel = 1
    
    Dim iMuftQty As Long
    
    For i = 1 To FG.Rows - 1
        iMuftQty = iMuftQty + Val(FG.TextMatrix(i, FG.ColIndex("qty_muft")))
    Next i
    
    Me.lblInfo.Caption = "Всего муфт: " & iMuftQty
    
    
'    updateIgnores
    
    Exit Sub
err:
    FG.redraw = flexRDBuffered



End Sub




Public Sub reloadDataAndGrid()

    
    ' загружаем данные из базы и файла
    reloadAllData
    
    If lngCurCatalogID = 0 Then
        Me.Caption = "Нет привязанного каталога базы данных"
    Else
        If lngCurProjectID > 0 Then
            Me.Caption = "(" & strDBServer & ":" & strDBName & ") "
            Me.Caption = Me.Caption & strProjName
            If Len(strBlockNumber) > 0 Then Me.Caption = Me.Caption & " - Блок " & strBlockNumber
            If Len(strBuildingCode) > 0 Then Me.Caption = Me.Caption & " - Здание " & strBuildingCode
            If Len(catName) > 0 Then Me.Caption = Me.Caption & " - " & catName
        Else
            Me.Caption = "Каталог " & Chr(34) & catName & Chr(34)
        End If
    End If


    fillCombo
    fillGrid
    


    Exit Sub

err:
    MsgBox "reloadDataAndGrid() - " & err.Description

End Sub





Private Sub btnSave_Click()





End Sub

Private Sub CommandButton1_Click()

' осталось от кнопки " <<< Выделить элемент, соответствующий строке"

'    showElemRow Me.FG.Row
'    selectElemRow Me.FG.Row

End Sub

Private Function getElemFromCache(fp As Long) As Element

On Error GoTo err

    Set getElemFromCache = ActiveModelReference.GraphicalElementCache.GetElement(ActiveModelReference.GraphicalElementCache.IndexFromFilePosition(fp))

    Exit Function
err:

Set getElemFromCache = Nothing

End Function


Private Sub cmbRefs_Change()

    
    fillGrid getRefNum


End Sub

'Public Sub updateIgnores() ' NOT USING
'
'
'    Dim R As Long
'    Dim I As Long
'    Dim bar As clsBar
'    Dim elm As clsElem
'    Dim el As Element
'
'
'    CadInputQueue.SendMessageToApplication "rein", "dispid;0"
'
'    For R = 1 To FG.Rows - 1
'
'        Set bar = bars(Val(FG.TextMatrix(R, fg.ColIndex("arnum"))))
'
'        If bar.IDs.Count > 0 Then
'
'            For I = 1 To bar.IDs.Count
'
'                Set elm = bar.IDs(I)
'
'                If elm.numref = 0 Then
'
'                    If CBool(Val(fg.TextMatrix(R, fg.ColIndex("display")))) Then
'                        CadInputQueue.SendMessageToApplication "rein", "dispid;" & elm.ID
'                    End If
'
'                End If
'
'            Next I
'
'        End If
'
'
'        If bar.FPs.Count > 0 Then
'
'            For I = 1 To bar.FPs.Count
'
'                Set elm = bar.FPs(I)
'
'                If elm.numref = 0 Then
'
'                    If CBool(Val(fg.TextMatrix(R, fg.ColIndex("display")))) Then
'                        CadInputQueue.SendMessageToApplication "rein", "dispfp;" & elm.fp
'                    End If
'
'                End If
'
'            Next I
'
'        End If
'
'    Next R
'
'
'End Sub

Public Function getRefNum() As Long


    If cmbRefs.ListIndex <= 0 Then getRefNum = -1: Exit Function

    Dim refnum As Long
    refnum = refsAll(cmbRefs.ListIndex)

    getRefNum = refnum
    
End Function



Private Sub FG_AfterEdit(ByVal Row As Long, ByVal col As Long)

    Dim bEx As Boolean


    Dim i As Long
    Dim el As Element

    If Row < 1 Then Exit Sub

    Dim bar As clsBar
    Set bar = bars(Val(FG.TextMatrix(Row, FG.ColIndex("arnum"))))
        
    If col = FG.ColIndex("numpos") Then
    
        If Val(FG.TextMatrix(Row, FG.ColIndex("srtmID"))) > 0 And Len(Trim(FG.TextMatrix(Row, FG.ColIndex("numpos")))) > 0 Then
            
            bar.numpos = Val(FG.TextMatrix(Row, FG.ColIndex("numpos")))
            
            ' если длина не введена ранее и если не погонные метры
            If Len(Trim(FG.TextMatrix(Row, FG.ColIndex("barlen")))) = 0 And Not bar.bRunMet Then
                If bar.rad > 0 Then
                    FG.TextMatrix(Row, FG.ColIndex("barlen")) = bar.file_len_mid
                    bar.base_length = bar.file_len_mid
                Else
                    FG.TextMatrix(Row, FG.ColIndex("barlen")) = Rein2d.getTotalLength
                    bar.base_length = Rein2d.getTotalLength
                End If
            End If
            
            ' если количество не введено ранее
            If bar.bRunMet Then
                If Len(Trim(FG.TextMatrix(Row, FG.ColIndex("qty_rm")))) = 0 Then
                    bar.base_qty = Format(bar.file_qty_rm, "0.0")
                    FG.TextMatrix(Row, FG.ColIndex("qty_rm")) = bar.base_qty
                End If
            Else
                If Len(Trim(FG.TextMatrix(Row, FG.ColIndex("qty_p")))) = 0 Then
                    bar.base_qty = bar.file_qty_p
                    FG.TextMatrix(Row, FG.ColIndex("qty_p")) = bar.base_qty
                End If
            End If
            
            If bar.bCont Then
                If Len(Trim(FG.TextMatrix(Row, FG.ColIndex("len_min")))) = 0 Then
                    bar.base_ms_min = bar.file_ms_min
                    FG.TextMatrix(Row, FG.ColIndex("len_min")) = bar.file_len_min
                End If
                
                If Len(Trim(FG.TextMatrix(Row, FG.ColIndex("len_mid")))) = 0 Then
                    bar.base_ms_mid = bar.file_ms_mid
                    FG.TextMatrix(Row, FG.ColIndex("len_mid")) = bar.file_len_mid
                End If
                
                If Len(Trim(FG.TextMatrix(Row, FG.ColIndex("len_max")))) = 0 Then
                    bar.base_ms_max = bar.file_ms_max
                    FG.TextMatrix(Row, FG.ColIndex("len_max")) = bar.file_len_max
                End If
            End If
            

            FG.Cell(flexcpPicture, Row, FG.ColIndex("save")) = ImageList1.ListImages("save").ExtractIcon
            
        End If
        
    ElseIf col = FG.ColIndex("barlen") Then
        
        If bar.posID > 0 And bar.pointsComp.Count > 0 Then
            bar.base_length = getDbl(FG.TextMatrix(Row, FG.ColIndex("barlen")))
            If bar.base_length <= 0 Then bar.base_length = Rein2d.getTotalLength ' правка/обновление
            FG.TextMatrix(Row, FG.ColIndex("barlen")) = bar.base_length
            FG.Cell(flexcpPicture, Row, FG.ColIndex("save")) = ImageList1.ListImages("save").ExtractIcon
        End If
        
    ElseIf col = FG.ColIndex("hide") Then
    
        If FG.Rows < 2 Then Exit Sub
        
        
        
'        For i = 1 To FG.Rows - 1
'
'            If Val(FG.TextMatrix(i, FG.ColIndex("loc"))) = 1 Then
'
'                If FG.TextMatrix(i, FG.ColIndex("hide")) Then
'
'                    bEx = True
'                    Exit For
'                End If
'            End If
'
'        Next i
    
        bar.bHide = CBool(FG.TextMatrix(Row, FG.ColIndex("hide")))
        bar.bHide_V = CBool(Val(FG.TextMatrix(Row, FG.ColIndex("trm_v"))))
        bar.bHide_X = CBool(Val(FG.TextMatrix(Row, FG.ColIndex("trm_x"))))
        bar.bHide_O = CBool(Val(FG.TextMatrix(Row, FG.ColIndex("trm_o"))))
        bar.bHide_S = CBool(Val(FG.TextMatrix(Row, FG.ColIndex("trm_s"))))
    
        sendPos "hidepos", Row


        Dim br As New clsBar
        
        br.numpos = bar.numpos
        br.refnum = getRefNum
        br.pcatID = bar.pcatID
        br.bHide = bar.bHide
        br.bHide_V = bar.bHide_V
        br.bHide_X = bar.bHide_X
        br.bHide_O = bar.bHide_O
        br.bHide_S = bar.bHide_S

        syncHides br
        
        
        
    ElseIf col = FG.ColIndex("display") Then
    
        'expos0 - выкл поз
        'expos1 - вкл поз
        'expos2 - очистить все
        
        If FG.Rows < 2 Then Exit Sub
        
        
        For i = 1 To FG.Rows - 1
        
            If Val(FG.TextMatrix(i, FG.ColIndex("loc"))) = 1 Then
                If FG.TextMatrix(i, FG.ColIndex("display")) Then
                    bEx = True
                    Exit For
                End If
            End If
        
        Next i
    
    
        If bEx Then ' если есть хоть одна галка
            sendPos "expos" & Abs(CInt(CBool(FG.TextMatrix(Row, FG.ColIndex("display"))))), Row
        Else
            sendPos "expos2", Row
        End If

    
'        updateIgnores
    
    Else
    End If

    

End Sub

Public Sub updateSketch(Row As Long)

    On Error GoTo err

    Dim i As Integer
    Dim bar As clsBar
    
    If Row < 1 Then Exit Sub
    
    Set bar = bars(Val(FG.TextMatrix(Row, FG.ColIndex("arnum"))))

    Rein2d.Clear
    
    If bar.pointsDraw.Count < 2 Then Exit Sub


    Dim p As Point2d

    Rein2d.setR bar.bend_rad
    Rein2d.setRForEnds bar.diam * 2.25

    For i = 1 To bar.pointsDraw.Count

        p = bar.pointsDraw(i)

        Rein2d.AddPoint p.X, p.Y, p.X, p.Y

    Next i

    
    
    If bar.iMain > 0 Then Rein2d.setMainLine CLng(bar.iMain)

    Rein2d.bCont = bar.bCont
    
    Dim ofms As New Offtmisc.Misc
    Rein2d.dContMin = ofms.roundExt(bar.file_ms_min, -1, 5, Val(GetSetting("Offtake2", "RndShift", "iArmSegm", 0)))
    Rein2d.dContMid = ofms.roundExt(bar.file_ms_mid, -1, 5, Val(GetSetting("Offtake2", "RndShift", "iArmSegm", 0)))
    Rein2d.dContMax = ofms.roundExt(bar.file_ms_max, -1, 5, Val(GetSetting("Offtake2", "RndShift", "iArmSegm", 0)))

    ' 1
    If bar.termBegType > 0 Then Rein2d.SetBegin bar.termBegType, bar.termBegPar0, bar.termBegPar1
    If bar.termEndType > 0 Then Rein2d.SetEnd bar.termEndType, bar.termEndPar0, bar.termEndPar1
    
    ' 2
    If bar.rad Then Rein2d.RArc = bar.rad

    ' замена 1 и 2 не помогает - глюк при муфтах/резьбе на стержне по радиусу

    Rein2d.bNoLens = bar.bRunMet
    
    Rein2d.Fit 1.5


    Exit Sub
err:
    MsgBox "updateSketch - " & err.Description

End Sub


Public Function getElemByID(mr As ModelReference, sID As Long)

On Error GoTo err

    Set getElemByID = mr.GetElementByID(DLongFromLong(sID))

Exit Function
err:
    Set getElemByID = Nothing

End Function


'Public Sub selectElemRow(NewRow As Long)
'
'    Dim str As String
'    Dim I As Integer
'    Dim J As Integer
'    Dim a As Integer
'    Dim mref As Long
'    Dim refnum As Long
'    Dim att As Attachment
'    Dim lngSlotNumber As Long
'    Dim mrAtt As ModelReference
'    Dim elm As clsElem
'    Dim mr As ModelReference
'
'    Dim bar As clsBar
'    If NewRow < 1 Then Exit Sub
'    If bars Is Nothing Then Exit Sub
'    If bars.Count = 0 Then Exit Sub
'
'    Set bar = bars(Val(FG.TextMatrix(NewRow, FG.ColIndex("arnum"))))
'
'    If bar.IDs Is Nothing Then Exit Sub
'    If bar.IDs.Count = 0 Then Exit Sub
'
'    mdlLocate_clearHilited 1
'
'
'    For J = 1 To bar.refs.Count
'        refnum = bar.refs(J)
'
'        Set mrAtt = getModelRefByRefNumber(refnum)
'
'        If Not mrAtt Is Nothing Then
'
'            mref = mrAtt.MdlModelRefP
'
'            Dim eref As Long
'
''            If bar.FPs.Count > 0 Then
''                For I = 1 To bar.FPs.Count
''
''
''                    Set elm = bar.FPs(I)
''
''                    Set mr = getModelRefByRefNumber(refnum)
''
''                    If Not mr Is Nothing Then
''                        eref = mdlModelRef_getElementRef(mr.MdlModelRefP, elm.fp)
''                        If eref > 0 Then Call mdlLocate_hiliteElement(eref, mr.MdlModelRefP)
''                    End If
''
''
''                Next I
''            End If
'
'
'            If bar.IDs.Count > 0 Then
'                For I = 1 To bar.IDs.Count
'
'                    Dim ele As Element
'
'                    Set elm = bar.IDs(I)
'
'                    Set mr = getModelRefByRefNumber(refnum)
'
'                    If Not mr Is Nothing Then
'
'                        Set ele = getElemByID(mr, elm.ID)
'
'                        If Not ele Is Nothing Then
'
'                            ActiveModelReference.SelectElement ele, True
'
''                            eref = mdlModelRef_getElementRef(mr.MdlModelRefP, ele.FilePosition)
''
''                            If eref > 0 Then Call mdlLocate_hiliteElement(eref, mr.MdlModelRefP)
'
'                        End If
'                    End If
'
'                Next I
'            End If
'
'
'        End If
'
'    Next J
'
'
'
'
'
'End Sub

Public Sub sendPos(strCmd As String, Row As Long)


    If Row > 0 Then

        Dim bar As clsBar
        Set bar = bars(Val(FG.TextMatrix(Row, FG.ColIndex("arnum"))))
        
        Dim iRM As Integer
        
        If bar.bCont Then iRM = 2
        If bar.bRunMet Then iRM = 1
        
        
    '     "curPos_diam", &curPos.diam);
    '     "curPos_runmet", &curPos.runmet);
    '     "curPos_rad", &curPos.rad[0]);
    '     "curPos_numpts", &curPos.numpts);
    '     "curPos_term_beg", &curPos.term[0]);
    '     "curPos_term_end", &curPos.term[0]);
    '     "curPos_numpts", &curPos.numpts);
    '     "curPos_length", &curPos.length);
        
        Dim iRefN As Long
        iRefN = getRefNum

        SetCExpressionValue "curPos_refnum", iRefN, "rein"
        
        SetCExpressionValue "curPos_numb", bar.numpos, "rein"
        
        SetCExpressionValue "curPos_pcatid", CLng(bar.pcatID), "rein"
        SetCExpressionValue "curPos_diam", CLng(bar.diam), "rein"
        SetCExpressionValue "curPos_runmet", CLng(iRM), "rein"
        SetCExpressionValue "curPos_rad", CLng(bar.rad), "rein"
        SetCExpressionValue "curPos_numpts", CLng(bar.pointsComp.Count), "rein"
        SetCExpressionValue "curPos_length", CDbl(bar.poslen), "rein"
        SetCExpressionValue "curPos_term_beg", CLng(bar.termBegType), "rein"
        SetCExpressionValue "curPos_term_end", CLng(bar.termEndType), "rein"
        SetCExpressionValue "curPos_term_par0_beg", CLng(bar.termBegPar0), "rein"
        SetCExpressionValue "curPos_term_par1_beg", CLng(bar.termBegPar1), "rein"
        SetCExpressionValue "curPos_term_par0_end", CLng(bar.termEndPar0), "rein"
        SetCExpressionValue "curPos_term_par1_end", CLng(bar.termEndPar1), "rein"
        SetCExpressionValue "curPos_hide", Abs(CLng(bar.bHide)), "rein"
        SetCExpressionValue "curPos_trm_v", Abs(CLng(bar.bHide_V)), "rein"
        SetCExpressionValue "curPos_trm_x", Abs(CLng(bar.bHide_X)), "rein"
        SetCExpressionValue "curPos_trm_o", Abs(CLng(bar.bHide_O)), "rein"
        SetCExpressionValue "curPos_trm_s", Abs(CLng(bar.bHide_S)), "rein"
        
        Dim strArPts As String
        
        Dim i As Integer
        Dim p As Point2d
        
        strArPts = "c"
        For i = 1 To bar.pointsComp.Count
            p = bar.pointsComp(i)
            strArPts = strArPts & ";" & p.X & ";" & p.Y
        Next i
        
        SetCExpressionValue "curPos_ptsc", strArPts, "rein"
    
        strArPts = "a"
        For i = 1 To bar.pointsCompAlt.Count
            p = bar.pointsCompAlt(i)
            strArPts = strArPts & ";" & p.X & ";" & p.Y
        Next i
        
        SetCExpressionValue "curPos_ptsa", strArPts, "rein"

        
    
    End If
    

    CadInputQueue.SendMessageToApplication "rein", strCmd
    


End Sub

'Public Sub showElemRow(NewRow As Long)
'
'    Dim str As String
'    Dim I As Integer
'    Dim J As Integer
'    Dim a As Integer
'    Dim mref As Long
'    Dim refnum As Long
'    Dim att As Attachment
'    Dim lngSlotNumber As Long
'    Dim mrAtt As ModelReference
'    Dim elm As clsElem
'    Dim mr As ModelReference
'
'    Dim bar As clsBar
'    If NewRow < 1 Then Exit Sub
'    If bars Is Nothing Then Exit Sub
'    If bars.Count = 0 Then Exit Sub
'
'    Set bar = bars(Val(FG.TextMatrix(NewRow, FG.ColIndex("arnum"))))
'
'
'    If bar.IDs Is Nothing Then Exit Sub
'    If bar.IDs.Count = 0 Then Exit Sub
'
'    mdlLocate_clearHilited 1
'
'
'    For J = 1 To bar.refs.Count
'        refnum = bar.refs(J)
'
'        Set mrAtt = getModelRefByRefNumber(refnum)
'
'        If Not mrAtt Is Nothing Then
'
'            mref = mrAtt.MdlModelRefP
'
'            Dim eref As Long
'
'            If bar.FPs.Count > 0 Then
'                For I = 1 To bar.FPs.Count
'
'
'                    Set elm = bar.FPs(I)
'
'                    Set mr = getModelRefByRefNumber(refnum)
'
'                    If Not mr Is Nothing Then
'                        eref = mdlModelRef_getElementRef(mr.MdlModelRefP, elm.fp)
'                        If eref > 0 Then Call mdlLocate_hiliteElement(eref, mr.MdlModelRefP)
'                    End If
'
'
'                Next I
'            End If
'
'
'            If bar.IDs.Count > 0 Then
'                For I = 1 To bar.IDs.Count
'
'                    Dim ele As Element
'
'                    Set elm = bar.IDs(I)
'
'                    Set mr = getModelRefByRefNumber(refnum)
'
'                    If Not mr Is Nothing Then
'
'                        Set ele = getElemByID(mr, elm.ID)
'
'                        If Not ele Is Nothing Then
'
'                            eref = mdlModelRef_getElementRef(mr.MdlModelRefP, ele.FilePosition)
'
'                            If eref > 0 Then Call mdlLocate_hiliteElement(eref, mr.MdlModelRefP)
'
'                        End If
'                    End If
'
'                Next I
'            End If
'
'
'        End If
'
'    Next J
'
'
'
'
'
'End Sub


Private Sub FG_AfterRowColChange(ByVal OldRow As Long, ByVal OldCol As Long, ByVal NewRow As Long, ByVal NewCol As Long)

    On Error GoTo err

    If bBrys Then Exit Sub

    updateSketch NewRow
    
    Exit Sub
    
err:
    


End Sub

Private Sub FG_AfterSelChange(ByVal OldRowSel As Long, ByVal OldColSel As Long, ByVal NewRowSel As Long, ByVal NewColSel As Long)

End Sub

Private Sub FG_BeforeDataRefresh(Cancel As Boolean)

End Sub

Private Sub FG_BeforeEdit(ByVal Row As Long, ByVal col As Long, Cancel As Boolean)

    Dim bar As clsBar
    
'    If lngCurCatalogID = 0 Then Cancel = True
    
    If Val(FG.TextMatrix(Row, FG.ColIndex("loc"))) = 2 Then Cancel = True: Exit Sub

    Set bar = bars(Val(FG.TextMatrix(Row, FG.ColIndex("arnum"))))



    If col = FG.ColIndex("numpos") Then
        If lngCurCatalogID = 0 Then Cancel = True
'    ElseIf Col = FG.ColIndex("barlen") Then
'        If bar.bRunMet Then Cancel = True
'        If bar.posID > 0 And bar.pointsComp.Count = 0 Then Cancel = True
'    ElseIf Col = FG.ColIndex("nu1") Then
'        If bar.posID > 0 And bar.pointsComp.Count = 0 Then Cancel = True
    ElseIf col = FG.ColIndex("hide") Then
        If bar.numpos = 0 Then Cancel = True
    ElseIf col = FG.ColIndex("trm_v") Then
        If bar.numpos = 0 Then Cancel = True
    ElseIf col = FG.ColIndex("trm_x") Then
        If bar.numpos = 0 Then Cancel = True
    ElseIf col = FG.ColIndex("trm_o") Then
        If bar.numpos = 0 Then Cancel = True
    ElseIf col = FG.ColIndex("trm_s") Then
        If bar.numpos = 0 Then Cancel = True
    ElseIf col = FG.ColIndex("display") Then
        If FG.Cell(flexcpPicture, Row, FG.ColIndex("infile")) Is Nothing Then Cancel = True
    Else
        Cancel = True
    End If

End Sub





Private Sub FG_BeforeMouseDown(ByVal Button As Integer, ByVal Shift As Integer, ByVal X As Single, ByVal Y As Single, Cancel As Boolean)

End Sub

Private Sub FG_Click()

    Dim i As Long

    If FG.Row <= 0 Then Exit Sub
    
    Dim bRunMet As Boolean
    Dim bHide As Boolean
    
    Dim dQty As Double
    
    Dim bar As clsBar
    
    Dim iToRemove As Long
    
    
    
    
    Set bar = bars(Val(FG.TextMatrix(FG.Row, FG.ColIndex("arnum"))))
    
    bar.partdefID = 5 ' детали
    If optIzd.Value Then
        bar.partdefID = 13 ' арм. изделия
    End If

    Dim bTrans As Boolean
    Dim bSyncHides As Boolean
    Dim strColNameOn As String
    Dim strColNameOff As String

    If Not FG.Cell(flexcpPicture, FG.Row, FG.col) Is Nothing Then
    


        If FG.col = FG.ColIndex("save") Then ' >>> SAVE >>>
        
            If bar.savePart(True, True) Then
                If bar.savePos(True) Then
    
                    FG.Cell(flexcpPicture, FG.Row, FG.ColIndex("save")) = Nothing
                    
                    CadInputQueue.SendMessageToApplication "rein", "relact" ' reload active
                
                End If
            End If
        
        ElseIf FG.col = FG.ColIndex("trm_v") And bar.numpos > 0 Then
        
            bSyncHides = True
            strColNameOn = "trm_v"
            strColNameOff = "trn_v"
            bar.bHide_V = Not CBool(Val(FG.TextMatrix(FG.Row, FG.col)))
        
        ElseIf FG.col = FG.ColIndex("trm_x") And bar.numpos > 0 Then
        
            bSyncHides = True
            strColNameOn = "trm_x"
            strColNameOff = "trn_x"
            bar.bHide_X = Not CBool(Val(FG.TextMatrix(FG.Row, FG.col)))
        
        ElseIf FG.col = FG.ColIndex("trm_o") And bar.numpos > 0 Then
        
            bSyncHides = True
            strColNameOn = "trm_o"
            strColNameOff = "trn_o"
            bar.bHide_O = Not CBool(Val(FG.TextMatrix(FG.Row, FG.col)))
            
        ElseIf FG.col = FG.ColIndex("trm_s") And bar.numpos > 0 Then
        
            bSyncHides = True
            strColNameOn = "trm_s"
            strColNameOff = "trn_s"
            bar.bHide_S = Not CBool(Val(FG.TextMatrix(FG.Row, FG.col)))
            
        End If
        
        
        If bSyncHides Then
        
        
            bHide = Not CBool(Val(FG.TextMatrix(FG.Row, FG.col)))
            
            If bHide Then
                FG.Cell(flexcpPicture, FG.Row, FG.col) = ImageList1.ListImages(strColNameOff).ExtractIcon
            Else
                FG.Cell(flexcpPicture, FG.Row, FG.col) = ImageList1.ListImages(strColNameOn).ExtractIcon
            End If
            
            FG.TextMatrix(FG.Row, FG.col) = CInt(bHide)
        
            Dim br As New clsBar
            
            br.numpos = bar.numpos
            br.refnum = getRefNum
            br.pcatID = bar.pcatID
            br.bHide = bar.bHide
            br.bHide_V = bar.bHide_V
            br.bHide_X = bar.bHide_X
            br.bHide_O = bar.bHide_O
            br.bHide_S = bar.bHide_S
    
            syncHides br
            
            sendPos "hidepos", FG.Row
            
        End If
        
    
    ElseIf Val(FG.TextMatrix(FG.Row, FG.ColIndex("loc"))) = 2 And FG.col = FG.ColIndex("save") Then
        'sync
        
        If lngCurCatalogID = 0 Then Exit Sub
        
        If Not bar.bRunMet Then
        
            bar.base_length = bar.file_len_mid
            FG.TextMatrix(FG.Row - 1, FG.ColIndex("barlen")) = bar.base_length
            FG.Cell(flexcpForeColor, FG.Row - 1, FG.ColIndex("barlen")) = &H80000008
            
            bar.base_qty = bar.file_qty_p
            FG.TextMatrix(FG.Row - 1, FG.ColIndex("qty_p")) = bar.base_qty
            FG.Cell(flexcpForeColor, FG.Row - 1, FG.ColIndex("qty_p")) = &H80000008
            
        End If
        
        
        
        If bar.bRunMet Then
        
            bar.base_qty = bar.file_qty_rm
            FG.TextMatrix(FG.Row - 1, FG.ColIndex("qty_rm")) = bar.base_qty
            FG.Cell(flexcpForeColor, FG.Row - 1, FG.ColIndex("qty_rm")) = &H80000008
            
        ElseIf bar.bCont Then
        
            bar.base_ms_min = bar.file_ms_min
            FG.TextMatrix(FG.Row - 1, FG.ColIndex("len_min")) = FG.TextMatrix(FG.Row, FG.ColIndex("len_min"))
            FG.Cell(flexcpForeColor, FG.Row - 1, FG.ColIndex("len_min")) = &H80000008
            
            bar.base_ms_mid = bar.file_ms_mid
            FG.TextMatrix(FG.Row - 1, FG.ColIndex("len_mid")) = FG.TextMatrix(FG.Row, FG.ColIndex("len_mid"))
            FG.Cell(flexcpForeColor, FG.Row - 1, FG.ColIndex("len_mid")) = &H80000008
            
            bar.base_ms_max = bar.file_ms_max
            FG.TextMatrix(FG.Row - 1, FG.ColIndex("len_max")) = FG.TextMatrix(FG.Row, FG.ColIndex("len_max"))
            FG.Cell(flexcpForeColor, FG.Row - 1, FG.ColIndex("len_max")) = &H80000008
        
        End If
        
        FG.Cell(flexcpPicture, FG.Row - 1, FG.ColIndex("save")) = ImageList1.ListImages("save").ExtractIcon
        
        
    Else
    End If
    
    
    ' так как двойные строчки, доработать
'    If iToRemove > 0 Then
'        bars.Remove iToRemove
'        Me.FG.RemoveItem iToRemove
'    End If


End Sub



Private Sub FG_DblClick()

    
    sendPos "hilpos", Me.FG.Row
    


End Sub

Private Sub FG_ValidateEdit(ByVal Row As Long, ByVal col As Long, Cancel As Boolean)

    If Row < 1 Then Exit Sub
    
    Dim br As clsBar
    Dim brExist As clsBar
    Dim brToSave As clsBar
    
    Dim pnum As Long
    
    Set brToSave = bars(Val(FG.TextMatrix(Row, FG.ColIndex("arnum"))))
    



    If col = FG.ColIndex("numpos") Then

        pnum = Val(FG.EditText)
    
        If pnum > 0 Then
        
        For Each br In bars
            If br.numpos = pnum And br.srtmID > 0 Then Cancel = True: Exit Sub
        Next br
        
        Else
            Cancel = True: Exit Sub
        End If
        
        
'        If Val(FG.EditText) <= 0 Then Cancel = True: Exit Sub
'
'        Dim I As Long
'        For I = 1 To FG.Rows - 1
'
'            Set brExist = bars(Val(FG.TextMatrix(I, FG.ColIndex("arnum"))))
'
'            If I <> Row And Val(FG.TextMatrix(I, FG.ColIndex("numpos"))) = Val(FG.EditText) And brExist.partID > 0 And brExist.posID > 0 Then
'                Cancel = True
'                Exit Sub
'            ElseIf I <> Row And Val(FG.TextMatrix(I, FG.ColIndex("numpos"))) = Val(FG.EditText) And brExist.partID > 0 And brExist.posID = 0 Then
'                brToSave.partID = brExist.partID
'            Else
'            End If
'
'        Next I

    Else
    End If


End Sub









Private Sub UserForm_Initialize()

    tryToConnectDB

    FG.Cols = 33
    
    FG.ColKey(0) = "infile"
    FG.ColKey(1) = "loc"
    FG.ColKey(2) = "numpos"
    FG.ColKey(3) = "display"
    FG.ColKey(4) = "hide"
    FG.ColKey(5) = "trm_v"
    FG.ColKey(6) = "trm_x"
    FG.ColKey(7) = "trm_o"
    FG.ColKey(8) = "trm_s"
    FG.ColKey(9) = "elems"
    FG.ColKey(10) = "diam"
    FG.ColKey(11) = "rad"
    FG.ColKey(12) = "termbeg"
    FG.ColKey(13) = "termend"
    FG.ColKey(14) = "runmet"
    FG.ColKey(15) = "sketch"
    FG.ColKey(16) = "cont"
    FG.ColKey(17) = "lap"
    FG.ColKey(18) = "len_min"
    FG.ColKey(19) = "len_mid"
    FG.ColKey(20) = "len_max"
    FG.ColKey(21) = "barlen"
    FG.ColKey(22) = "qty_rm"
    FG.ColKey(23) = "qty_p"
    FG.ColKey(24) = "qty_lap"
    FG.ColKey(25) = "qty_muft"
    FG.ColKey(26) = "nu1"
    FG.ColKey(27) = "save"
    FG.ColKey(28) = "srtmID"
    FG.ColKey(29) = "posdefID"
    FG.ColKey(30) = "points"
    FG.ColKey(31) = "arnum"
    FG.ColKey(32) = "reserved"
    
    
    FG.ColAlignment(FG.ColIndex("loc")) = flexAlignCenterCenter
    FG.ColAlignment(FG.ColIndex("runmet")) = flexAlignCenterCenter
    FG.ColAlignment(FG.ColIndex("sketch")) = flexAlignCenterCenter
    FG.ColAlignment(FG.ColIndex("lap")) = flexAlignCenterCenter
    FG.ColAlignment(FG.ColIndex("cont")) = flexAlignCenterCenter
    FG.ColAlignment(FG.ColIndex("display")) = flexAlignCenterCenter
    FG.ColAlignment(FG.ColIndex("hide")) = flexAlignCenterCenter
    FG.ColAlignment(FG.ColIndex("trm_v")) = flexAlignCenterCenter
    FG.ColAlignment(FG.ColIndex("trm_x")) = flexAlignCenterCenter
    FG.ColAlignment(FG.ColIndex("trm_o")) = flexAlignCenterCenter
    FG.ColAlignment(FG.ColIndex("trm_s")) = flexAlignCenterCenter
    FG.ColAlignment(FG.ColIndex("termbeg")) = flexAlignCenterCenter
    FG.ColAlignment(FG.ColIndex("termend")) = flexAlignCenterCenter
    
    
    
    FG.ColAlignment(FG.ColIndex("elems")) = flexAlignRightCenter
    FG.ColAlignment(FG.ColIndex("diam")) = flexAlignRightCenter
    FG.ColAlignment(FG.ColIndex("len_min")) = flexAlignRightCenter
    FG.ColAlignment(FG.ColIndex("len_mid")) = flexAlignRightCenter
    FG.ColAlignment(FG.ColIndex("len_max")) = flexAlignRightCenter
    FG.ColAlignment(FG.ColIndex("qty_rm")) = flexAlignRightCenter
    FG.ColAlignment(FG.ColIndex("qty_p")) = flexAlignRightCenter
    FG.ColAlignment(FG.ColIndex("qty_lap")) = flexAlignRightCenter
    FG.ColAlignment(FG.ColIndex("qty_muft")) = flexAlignRightCenter
    FG.ColAlignment(FG.ColIndex("rad")) = flexAlignRightCenter
    FG.ColAlignment(FG.ColIndex("barlen")) = flexAlignRightCenter
    FG.ColAlignment(FG.ColIndex("nu1")) = flexAlignRightCenter
    
    

    FG.TextMatrix(0, FG.ColIndex("infile")) = "есть"
    FG.TextMatrix(0, FG.ColIndex("loc")) = "нал"
    FG.TextMatrix(0, FG.ColIndex("numpos")) = "поз"
    FG.TextMatrix(0, FG.ColIndex("elems")) = "элем"
    FG.TextMatrix(0, FG.ColIndex("termbeg")) = "|-"
    FG.TextMatrix(0, FG.ColIndex("termend")) = "-|"
    FG.TextMatrix(0, FG.ColIndex("diam")) = "диам"
    FG.TextMatrix(0, FG.ColIndex("runmet")) = "пог"
    FG.TextMatrix(0, FG.ColIndex("sketch")) = "эск"
    FG.TextMatrix(0, FG.ColIndex("lap")) = "раз"
    FG.TextMatrix(0, FG.ColIndex("cont")) = "пер"
    FG.TextMatrix(0, FG.ColIndex("display")) = "@"
    FG.TextMatrix(0, FG.ColIndex("hide")) = "х"
    FG.TextMatrix(0, FG.ColIndex("len_min")) = "L мин."
    FG.TextMatrix(0, FG.ColIndex("len_mid")) = "L ср."
    FG.TextMatrix(0, FG.ColIndex("len_max")) = "L макс."
    FG.TextMatrix(0, FG.ColIndex("qty_rm")) = "Кол. п.м."
    FG.TextMatrix(0, FG.ColIndex("qty_p")) = "Кол. шт."
    FG.TextMatrix(0, FG.ColIndex("qty_lap")) = "нхл"
    FG.TextMatrix(0, FG.ColIndex("qty_muft")) = "мфт"
    FG.TextMatrix(0, FG.ColIndex("rad")) = "Радиус"
    FG.TextMatrix(0, FG.ColIndex("barlen")) = "Длина"
    FG.TextMatrix(0, FG.ColIndex("nu1")) = ""
    FG.TextMatrix(0, FG.ColIndex("save")) = "v"
    FG.TextMatrix(0, FG.ColIndex("srtmID")) = "srtm"
    FG.TextMatrix(0, FG.ColIndex("posdefID")) = "posdef"
    FG.TextMatrix(0, FG.ColIndex("points")) = "вершин"
    FG.TextMatrix(0, FG.ColIndex("arnum")) = "arnum"
    
'    If usrName <> "l_vibe" Then
    FG.ColHidden(FG.ColIndex("elems")) = True
    FG.ColHidden(FG.ColIndex("srtmID")) = True
    FG.ColHidden(FG.ColIndex("posdefID")) = True
    FG.ColHidden(FG.ColIndex("points")) = True
    FG.ColHidden(FG.ColIndex("loc")) = True
    FG.ColHidden(FG.ColIndex("arnum")) = True
    FG.ColHidden(FG.ColIndex("sketch")) = True
'    End If
    FG.ColHidden(FG.ColIndex("nu1")) = True ' not using
    FG.ColHidden(FG.ColIndex("lap")) = True ' not using
    
    FG.ColDataType(FG.ColIndex("len_min")) = flexDTDouble
    FG.ColDataType(FG.ColIndex("len_mid")) = flexDTDouble
    FG.ColDataType(FG.ColIndex("len_max")) = flexDTDouble
    FG.ColDataType(FG.ColIndex("qty_rm")) = flexDTDouble
    FG.ColDataType(FG.ColIndex("runmet")) = flexDTBoolean
    FG.ColDataType(FG.ColIndex("sketch")) = flexDTBoolean
    FG.ColDataType(FG.ColIndex("lap")) = flexDTBoolean
    FG.ColDataType(FG.ColIndex("cont")) = flexDTBoolean
    FG.ColDataType(FG.ColIndex("display")) = flexDTBoolean
    FG.ColDataType(FG.ColIndex("hide")) = flexDTBoolean
    
'    FG.ColComboList(FG.ColIndex("display")) = "#1;да|#2;нет"


    FG.ColFormat(FG.ColIndex("len_min")) = "0"
    FG.ColFormat(FG.ColIndex("len_mid")) = "0"
    FG.ColFormat(FG.ColIndex("len_max")) = "0"
    FG.ColFormat(FG.ColIndex("qty_rm")) = "0.0"
    
    
    CadInputQueue.SendMessageToApplication "rein", "show 0"
    
    bGridFormLoaded = True
    
'    Rein2d.SetRoundExtParams 0, 10, -1, 5
'    Rein2d.iShift = -3
'    Rein2d.iShift2 = 0
    
    Rein2d.setAngleRound 0, 10, 0
    Rein2d.setArcRound -1, 10, -2
    Rein2d.setLineRound -1, 5, 0
    ' величины должны быть одинаковы у всех пользователей
'    Rein2d.setArcRound -1, 10, Val(GetSetting("Offtake2", "RndShift", "iArmArc", -3))
'    Rein2d.setLineRound -1, 5, Val(GetSetting("Offtake2", "RndShift", "iArmSegm", 0))

    Me.optDet.Value = GetSetting("Offtake2", "Rein", "optDet", True)
    Me.optIzd.Value = GetSetting("Offtake2", "Rein", "optIzd", False)



End Sub



Private Sub UserForm_Terminate()

    Set cn = Nothing
    
    CadInputQueue.SendMessageToApplication "rein", "show 0"
    CadInputQueue.SendMessageToApplication "rein", "dispid;0" ' отображать все
    
    sendPos "expos2", 0 ' отображение всех
    
    bGridFormLoaded = False
    

    Call SaveSetting("Offtake2", "Rein", "optDet", Me.optDet.Value)
    Call SaveSetting("Offtake2", "Rein", "optIzd", Me.optIzd.Value)


End Sub


Public Sub selectPosRow(numb As Integer)


    On Error GoTo err

    Dim i As Long
    
    If FG.Rows <= 1 Then Exit Sub

    For i = 1 To FG.Rows - 1
        If Not FG.Cell(flexcpPicture, i, FG.ColIndex("infile")) Is Nothing Then
            FG.Cell(flexcpPicture, i, FG.ColIndex("infile")) = ImageList1.ListImages("galka").ExtractIcon
        End If
    Next i


    For i = 1 To FG.Rows - 1
    
        If numb = Val(FG.TextMatrix(i, FG.ColIndex("arnum"))) Then
        
            FG.Row = i
            FG.col = FG.ColIndex("numpos")
            FG.ShowCell i, FG.ColIndex("numpos")
            FG.Cell(flexcpPicture, i, FG.ColIndex("infile")) = ImageList1.ListImages("right").ExtractIcon
            Exit For
        
        End If


    Next i

    Exit Sub
err:
    

End Sub
