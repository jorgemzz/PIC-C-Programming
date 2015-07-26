<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class FormPrincipal
    Inherits System.Windows.Forms.Form

    'Form reemplaza a Dispose para limpiar la lista de componentes.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Requerido por el Diseñador de Windows Forms
    Private components As System.ComponentModel.IContainer

    'NOTA: el Diseñador de Windows Forms necesita el siguiente procedimiento
    'Se puede modificar usando el Diseñador de Windows Forms.  
    'No lo modifique con el editor de código.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.btnt = New System.Windows.Forms.Button()
        Me.btnb = New System.Windows.Forms.Button()
        Me.btna = New System.Windows.Forms.Button()
        Me.btnl = New System.Windows.Forms.Button()
        Me.btnespacio = New System.Windows.Forms.Button()
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.StatusStrip1 = New System.Windows.Forms.StatusStrip()
        Me.ToolStripStatusLabel1 = New System.Windows.Forms.ToolStripStatusLabel()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.txtEnviar = New System.Windows.Forms.TextBox()
        Me.btnEnviar = New System.Windows.Forms.Button()
        Me.btnBorrar = New System.Windows.Forms.Button()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.StatusStrip1.SuspendLayout()
        Me.SuspendLayout()
        '
        'btnt
        '
        Me.btnt.Location = New System.Drawing.Point(109, 38)
        Me.btnt.Name = "btnt"
        Me.btnt.Size = New System.Drawing.Size(75, 23)
        Me.btnt.TabIndex = 0
        Me.btnt.Text = "t"
        Me.btnt.UseVisualStyleBackColor = True
        '
        'btnb
        '
        Me.btnb.Location = New System.Drawing.Point(109, 67)
        Me.btnb.Name = "btnb"
        Me.btnb.Size = New System.Drawing.Size(75, 23)
        Me.btnb.TabIndex = 1
        Me.btnb.Text = "b"
        Me.btnb.UseVisualStyleBackColor = True
        '
        'btna
        '
        Me.btna.Location = New System.Drawing.Point(28, 67)
        Me.btna.Name = "btna"
        Me.btna.Size = New System.Drawing.Size(75, 23)
        Me.btna.TabIndex = 2
        Me.btna.Text = "a"
        Me.btna.UseVisualStyleBackColor = True
        '
        'btnl
        '
        Me.btnl.Location = New System.Drawing.Point(190, 67)
        Me.btnl.Name = "btnl"
        Me.btnl.Size = New System.Drawing.Size(75, 23)
        Me.btnl.TabIndex = 3
        Me.btnl.Text = "l"
        Me.btnl.UseVisualStyleBackColor = True
        '
        'btnespacio
        '
        Me.btnespacio.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.btnespacio.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnespacio.Location = New System.Drawing.Point(190, 96)
        Me.btnespacio.Name = "btnespacio"
        Me.btnespacio.Size = New System.Drawing.Size(75, 23)
        Me.btnespacio.TabIndex = 4
        Me.btnespacio.Text = "Espacio"
        Me.btnespacio.UseVisualStyleBackColor = False
        '
        'SerialPort1
        '
        Me.SerialPort1.PortName = "COM8"
        Me.SerialPort1.StopBits = System.IO.Ports.StopBits.Two
        '
        'StatusStrip1
        '
        Me.StatusStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.ToolStripStatusLabel1})
        Me.StatusStrip1.Location = New System.Drawing.Point(0, 244)
        Me.StatusStrip1.Name = "StatusStrip1"
        Me.StatusStrip1.Size = New System.Drawing.Size(292, 22)
        Me.StatusStrip1.TabIndex = 5
        Me.StatusStrip1.Text = "StatusStrip1"
        '
        'ToolStripStatusLabel1
        '
        Me.ToolStripStatusLabel1.Name = "ToolStripStatusLabel1"
        Me.ToolStripStatusLabel1.Size = New System.Drawing.Size(65, 17)
        Me.ToolStripStatusLabel1.Text = "HH:MM:SS"
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        '
        'txtEnviar
        '
        Me.txtEnviar.Location = New System.Drawing.Point(75, 149)
        Me.txtEnviar.Name = "txtEnviar"
        Me.txtEnviar.Size = New System.Drawing.Size(100, 20)
        Me.txtEnviar.TabIndex = 7
        '
        'btnEnviar
        '
        Me.btnEnviar.Location = New System.Drawing.Point(190, 146)
        Me.btnEnviar.Name = "btnEnviar"
        Me.btnEnviar.Size = New System.Drawing.Size(75, 23)
        Me.btnEnviar.TabIndex = 8
        Me.btnEnviar.Text = "Enviar"
        Me.btnEnviar.UseVisualStyleBackColor = True
        '
        'btnBorrar
        '
        Me.btnBorrar.Location = New System.Drawing.Point(100, 195)
        Me.btnBorrar.Name = "btnBorrar"
        Me.btnBorrar.Size = New System.Drawing.Size(75, 23)
        Me.btnBorrar.TabIndex = 9
        Me.btnBorrar.Text = "Borrar LCD"
        Me.btnBorrar.UseVisualStyleBackColor = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(19, 156)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(34, 13)
        Me.Label1.TabIndex = 10
        Me.Label1.Text = "Texto"
        '
        'FormPrincipal
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(292, 266)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.btnBorrar)
        Me.Controls.Add(Me.btnEnviar)
        Me.Controls.Add(Me.txtEnviar)
        Me.Controls.Add(Me.StatusStrip1)
        Me.Controls.Add(Me.btnespacio)
        Me.Controls.Add(Me.btnl)
        Me.Controls.Add(Me.btna)
        Me.Controls.Add(Me.btnb)
        Me.Controls.Add(Me.btnt)
        Me.Name = "FormPrincipal"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "PicRS232vb"
        Me.StatusStrip1.ResumeLayout(False)
        Me.StatusStrip1.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents btnt As System.Windows.Forms.Button
    Friend WithEvents btnb As System.Windows.Forms.Button
    Friend WithEvents btna As System.Windows.Forms.Button
    Friend WithEvents btnl As System.Windows.Forms.Button
    Friend WithEvents btnespacio As System.Windows.Forms.Button
    Friend WithEvents SerialPort1 As System.IO.Ports.SerialPort
    Friend WithEvents StatusStrip1 As System.Windows.Forms.StatusStrip
    Friend WithEvents ToolStripStatusLabel1 As System.Windows.Forms.ToolStripStatusLabel
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents txtEnviar As System.Windows.Forms.TextBox
    Friend WithEvents btnEnviar As System.Windows.Forms.Button
    Friend WithEvents btnBorrar As System.Windows.Forms.Button
    Friend WithEvents Label1 As System.Windows.Forms.Label

End Class
