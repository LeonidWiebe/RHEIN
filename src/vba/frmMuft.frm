VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} frmMuft 
   Caption         =   "Расчет муфт"
   ClientHeight    =   5820
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   5115
   OleObjectBlob   =   "frmMuft.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "frmMuft"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public Sub loadGrid()

    Me.FG.Cols = 4
    Me.FG.ExtendLastCol = True

    Dim at As Attachment
    
    For Each at In ActiveModelReference.AddElements
    
    Next at

End Sub



Private Sub UserForm_Activate()





End Sub

Private Sub UserForm_Click()

End Sub
