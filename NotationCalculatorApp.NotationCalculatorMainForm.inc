procedure InitializeComponent;
    begin
        self.resetButton := new System.Windows.Forms.Button();
        self.label1 := new System.Windows.Forms.Label();
        self.textBox1 := new System.Windows.Forms.TextBox();
        self.sourceNumberBaseInput := new System.Windows.Forms.ComboBox();
        self.resultNumberBaseInput := new System.Windows.Forms.ComboBox();
        self.resultLabel := new System.Windows.Forms.Label();
        self.SuspendLayout();
        // 
        // resetButton
        // 
        self.resetButton.Location := new System.Drawing.Point(197, 227);
        self.resetButton.Name := 'resetButton';
        self.resetButton.Size := new System.Drawing.Size(75, 23);
        self.resetButton.TabIndex := 2;
        self.resetButton.Text := 'Reset';
        self.resetButton.UseVisualStyleBackColor := true;
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(12, 9);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(100, 23);
        self.label1.TabIndex := 3;
        self.label1.Text := 'Исходное число';
        self.label1.Click += label1_Click;
        // 
        // textBox1
        // 
        self.textBox1.Location := new System.Drawing.Point(12, 35);
        self.textBox1.Name := 'textBox1';
        self.textBox1.Size := new System.Drawing.Size(192, 20);
        self.textBox1.TabIndex := 4;
        self.textBox1.TextChanged += textBox1_TextChanged;
        // 
        // sourceNumberBaseInput
        // 
        self.sourceNumberBaseInput.FormattingEnabled := true;
        self.sourceNumberBaseInput.Location := new System.Drawing.Point(210, 35);
        self.sourceNumberBaseInput.Name := 'sourceNumberBaseInput';
        self.sourceNumberBaseInput.Size := new System.Drawing.Size(62, 21);
        self.sourceNumberBaseInput.TabIndex := 5;
        self.sourceNumberBaseInput.SelectedIndexChanged += sourceNumberBaseInput_SelectedIndexChanged;
        // 
        // resultNumberBaseInput
        // 
        self.resultNumberBaseInput.FormattingEnabled := true;
        self.resultNumberBaseInput.Location := new System.Drawing.Point(210, 62);
        self.resultNumberBaseInput.Name := 'resultNumberBaseInput';
        self.resultNumberBaseInput.Size := new System.Drawing.Size(62, 21);
        self.resultNumberBaseInput.TabIndex := 6;
        self.resultNumberBaseInput.SelectedIndexChanged += comboBox2_SelectedIndexChanged;
        // 
        // resultLabel
        // 
        self.resultLabel.Location := new System.Drawing.Point(12, 62);
        self.resultLabel.Name := 'resultLabel';
        self.resultLabel.Size := new System.Drawing.Size(191, 23);
        self.resultLabel.TabIndex := 7;
        self.resultLabel.Text := '0';
        // 
        // NotationCalculatorMainForm
        // 
        self.ClientSize := new System.Drawing.Size(284, 262);
        self.Controls.Add(self.resultLabel);
        self.Controls.Add(self.resultNumberBaseInput);
        self.Controls.Add(self.sourceNumberBaseInput);
        self.Controls.Add(self.textBox1);
        self.Controls.Add(self.label1);
        self.Controls.Add(self.resetButton);
        self.Name := 'NotationCalculatorMainForm';
        self.Text := 'Notation calculator';
        self.Load += Form1_Load;
        self.ResumeLayout(false);
        self.PerformLayout();
    end;
