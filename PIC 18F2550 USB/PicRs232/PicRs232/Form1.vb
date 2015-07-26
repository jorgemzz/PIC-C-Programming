Imports System.IO.Ports

Public Class FormPrincipal

    Public Sub New()
        InitializeComponent()
        'abrir puerto mientras se ejecute la aplicacion
        If Not SerialPort1.IsOpen() Then
            Try
                SerialPort1.Open()
            Catch ex As System.Exception
                MessageBox.Show(ex.ToString())
            End Try
        End If
    End Sub

    Private Sub btnt_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnt.Click
        Dim mBufer As Byte() = New Byte(0) {}
        mBufer(0) = &H74 'ascii letra t
        SerialPort1.Write(mBufer, 0, mBufer.Length)
    End Sub

    Private Sub btnb_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnb.Click
        Dim mBuffer As Byte() = New Byte(0) {}
        mBuffer(0) = &H62 'ASCII letra "b".
        SerialPort1.Write(mBuffer, 0, mBuffer.Length)
    End Sub

    Private Sub btna_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btna.Click
        Dim mBuffer As Byte() = New Byte(0) {}
        mBuffer(0) = &H61 'ASCII letra "a".
        SerialPort1.Write(mBuffer, 0, mBuffer.Length)
    End Sub

    Private Sub btnl_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnl.Click
        Dim mBuffer As Byte() = New Byte(0) {}
        mBuffer(0) = &H6C 'ASCII letra "l".
        SerialPort1.Write(mBuffer, 0, mBuffer.Length)
    End Sub

    Private Sub btnespacio_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnespacio.Click
        Dim mBuffer As Byte() = New Byte(0) {}
        mBuffer(0) = &H20 'ASCII letra "Espacio".
        SerialPort1.Write(mBuffer, 0, mBuffer.Length)
    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        StatusStrip1.Items(0).Text = DateTime.Now.ToLongTimeString()
    End Sub

    Private Sub FormPrincipal_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub btnEnviar_Click(sender As Object, e As EventArgs) Handles btnEnviar.Click
        Dim mBuffer As Byte() = New Byte(0) {}

        'SerialPort1.Write(txtEnviar.Text)
        Dim NumChar As Integer
        Dim i As Integer
        NumChar = txtEnviar.Text.Length - 1
        For i = 0 To NumChar
            SerialPort1.Write(txtEnviar.Text.Chars(i))

        Next
    End Sub

    Private Sub btnBorrar_Click(sender As Object, e As EventArgs) Handles btnBorrar.Click
        SerialPort1.Write("z")
    End Sub

    Private Sub TextBox1_TextChanged(sender As Object, e As EventArgs)

    End Sub
End Class


