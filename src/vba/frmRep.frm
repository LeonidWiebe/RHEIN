VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} frmRep 
   Caption         =   "Отчет по количеству"
   ClientHeight    =   6225
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   4560
   OleObjectBlob   =   "frmRep.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "frmRep"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim tec1 As TransientElementContainer

Public colMufts As Collection

Private Sub btnLoad_Click()


    Dim strFile As String
    
    strFile = getTaskFile
    
    If Len(strFile) = 0 Then Exit Sub
    
    Me.FG.loadGrid strFile, flexFileAll


End Sub

Private Sub btnSave_Click()



    If cmbCatList.ListIndex >= 0 Then
    
        Dim clist As clsBar
        Dim ID As Long
        Dim qty As Double
        
        Set clist = Me.colMufts(cmbCatList.ListIndex + 1)
    
        Dim RS As New ADODB.Recordset
        
        Dim i As Long
        For i = 1 To Me.FG.Rows
            ID = Val(Me.FG.TextMatrix(i, 0))
            qty = getDbl(Me.FG.TextMatrix(i, 2))
            
            If ID > 0 Then
                RS.Open "select * from r_catlist_part where catlistID = " & clist.partID & " and objID = 7 and partID = " & ID, cn, adOpenForwardOnly, adLockOptimistic
                
                If Not RS.EOF Then
                    RS.MoveFirst
                Else
                    RS.AddNew
                    RS.Fields("catlistID").Value = clist.partID
                    RS.Fields("objID").Value = 7
                    RS.Fields("partID").Value = ID
                End If
                
                RS.Fields("partQty").Value = qty
                
                RS.Update
                
                RS.Close
                
            End If
        Next i
        
        Exit Sub
    End If









    Dim sFileName As String
    
    Dim OFN As OPENFILENAME
    OFN.lStructSize = Len(OFN)
    OFN.lpstrFilter = "Excel Files (*.xls)" + Chr$(0) + "*.xls" + Chr$(0) + "All Files (*.*)" + Chr$(0) + "*.*" + Chr$(0)
    OFN.lpstrFile = Space$(254)
    OFN.nMaxFile = 255
    OFN.lpstrFileTitle = Space$(254)
    OFN.nMaxFileTitle = 255
    OFN.lpstrInitialDir = CurDir
    OFN.lpstrTitle = "Сохранить в файл Excel"
    OFN.flags = 0
    Dim a
    a = GetSaveFileName(OFN)
    If (a) Then
        sFileName = LCase(Trim$(OFN.lpstrFile))
    Else
        Exit Sub
    End If
    
    If Asc(Right(sFileName, 1)) = 0 Then sFileName = Left(sFileName, Len(sFileName) - 1)
    
    If Not Right(LCase(sFileName), 4) = ".xls" Then
        sFileName = sFileName & ".xls"
    End If
    

    Me.FG.SaveGrid sFileName, flexFileExcel
    Me.FG.SaveGrid sFileName & ".grid", flexFileAll


End Sub

Private Sub cmbCatList_Change()


    If Len(cmbCatList.Text) > 0 Then
        Me.btnSave.Enabled = True
        Me.btnSave.Caption = "Обновить список"
    End If

End Sub



Private Sub FG_Click()

End Sub

Private Sub FG_DblClick()

    Dim R As Long
    R = Me.FG.Row
    
    If R < 1 Then Exit Sub
    If Len(Me.FG.TextMatrix(R, 0)) > 0 Then Exit Sub
    
    Dim p As Point3d
    
    p.X = Val(Me.FG.TextMatrix(R, 1))
    p.Y = Val(Me.FG.TextMatrix(R, 2))
    p.Z = Val(Me.FG.TextMatrix(R, 3))
    
    Dim el As EllipseElement
    
    Set el = CreateEllipseElement2(Nothing, p, 200, 200, Matrix3dInverse(CommandState.LastView.Rotation), msdFillModeNotFilled)
    
    Dim flags As MsdTransientFlags
    flags = msdTransientFlagsOverlay + msdTransientFlagsSnappable
    
    Set tec1 = CreateTransientElementContainer1(el, flags, msdViewAll, msdDrawingModeHilite)

    
    
    
    Dim pB As Point3d
    Dim pF As Point3d
    
    Dim dst As Double
    
    If CommandState.LastView.IsBack Or _
        CommandState.LastView.IsFront Or _
        CommandState.LastView.IsTop Or _
        CommandState.LastView.IsBottom Or _
        CommandState.LastView.IsLeft Or _
        CommandState.LastView.IsRight Then
        
        dst = 200
    Else
        dst = 1000
        
    End If
    
    pB.X = p.X - dst
    pB.Y = p.Y - dst
    pB.Z = p.Z - dst
    
    pF.X = p.X + dst
    pF.Y = p.Y + dst
    pF.Z = p.Z + dst
    
    CommandState.LastView.SetClippingDistanceByPoints pB, pF
        
    
    CommandState.LastView.SetActiveDepthByPoint p
    
    CommandState.LastView.ZoomAboutPoint p, 1#
    CommandState.LastView.redraw

    

End Sub

Private Sub lblErrs_Click()

End Sub

Private Sub UserForm_Click()

End Sub

Private Sub UserForm_Initialize()

    Me.FG.TextMatrix(0, 0) = "Тип"
    Me.FG.TextMatrix(0, 1) = "Диаметр"
    Me.FG.TextMatrix(0, 2) = "Количество"
    
    Me.btnSave.Caption = "Сохранить" & vbNewLine & "в таблицу" & vbNewLine & "Excel"
    
    Set colMufts = New Collection

End Sub
