procedure InitializeComponent;
    begin
        var resources: System.ComponentModel.ComponentResourceManager := new System.ComponentModel.ComponentResourceManager(typeof(NotationCalculatorMainForm));
        self.resetButton := new System.Windows.Forms.Button();
        self.sourceNumberInput := new System.Windows.Forms.TextBox();
        self.sourceNumberBaseInput := new System.Windows.Forms.ComboBox();
        self.resultNumberBaseInput := new System.Windows.Forms.ComboBox();
        self.resultNumberLabel := new System.Windows.Forms.Label();
        self.SuspendLayout();
        // 
        // resetButton
        // 
        self.resetButton.Location := new System.Drawing.Point(210, 66);
        self.resetButton.Name := 'resetButton';
        self.resetButton.Size := new System.Drawing.Size(62, 23);
        self.resetButton.TabIndex := 2;
        self.resetButton.Text := 'Reset';
        self.resetButton.UseVisualStyleBackColor := true;
        self.resetButton.Click += resetButton_Click;
        // 
        // sourceNumberInput
        // 
        self.sourceNumberInput.Location := new System.Drawing.Point(12, 12);
        self.sourceNumberInput.MaxLength := 8;
        self.sourceNumberInput.Name := 'sourceNumberInput';
        self.sourceNumberInput.Size := new System.Drawing.Size(192, 20);
        self.sourceNumberInput.TabIndex := 4;
        self.sourceNumberInput.TextChanged += sourceNumberInput_TextChanged;
        self.sourceNumberInput.KeyPress += sourceNumberInput_KeyPress;
        // 
        // sourceNumberBaseInput
        // 
        self.sourceNumberBaseInput.FormattingEnabled := true;
        self.sourceNumberBaseInput.Location := new System.Drawing.Point(210, 12);
        self.sourceNumberBaseInput.Name := 'sourceNumberBaseInput';
        self.sourceNumberBaseInput.Size := new System.Drawing.Size(62, 21);
        self.sourceNumberBaseInput.TabIndex := 5;
        self.sourceNumberBaseInput.Text := '10';
        self.sourceNumberBaseInput.SelectedIndexChanged += sourceNumberBaseInput_SelectedIndexChanged;
        // 
        // resultNumberBaseInput
        // 
        self.resultNumberBaseInput.FormattingEnabled := true;
        self.resultNumberBaseInput.Location := new System.Drawing.Point(210, 39);
        self.resultNumberBaseInput.Name := 'resultNumberBaseInput';
        self.resultNumberBaseInput.Size := new System.Drawing.Size(62, 21);
        self.resultNumberBaseInput.TabIndex := 6;
        self.resultNumberBaseInput.Text := '2';
        self.resultNumberBaseInput.SelectedIndexChanged += resultNumberBaseInput_SelectedIndexChanged;
        // 
        // resultNumberLabel
        // 
        self.resultNumberLabel.Location := new System.Drawing.Point(12, 39);
        self.resultNumberLabel.Name := 'resultNumberLabel';
        self.resultNumberLabel.Size := new System.Drawing.Size(191, 50);
        self.resultNumberLabel.TabIndex := 7;
        // 
        // NotationCalculatorMainForm
        // 
        self.AutoScaleMode := System.Windows.Forms.AutoScaleMode.Inherit;
        self.AutoSizeMode := System.Windows.Forms.AutoSizeMode.GrowAndShrink;
        self.ClientSize := new System.Drawing.Size(284, 101);
        self.Controls.Add(self.resultNumberLabel);
        self.Controls.Add(self.resultNumberBaseInput);
        self.Controls.Add(self.sourceNumberBaseInput);
        self.Controls.Add(self.sourceNumberInput);
        self.Controls.Add(self.resetButton);
        self.DoubleBuffered := true;
        self.Icon := (System.Drawing.Icon(resources.GetObject('$this.Icon')));
        self.Name := 'NotationCalculatorMainForm';
        self.Text := 'Notation calculator';
        self.ResumeLayout(false);
        self.PerformLayout();
    end;
