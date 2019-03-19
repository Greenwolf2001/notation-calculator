unit NotationCalculatorUI;

interface

uses NotationCalculatorUtil;

uses System, System.Drawing, System.Windows.Forms;

type
  NotationCalculatorMainForm = class(Form)
    procedure Recalculate();
    procedure ResetMainInput();
    procedure Reset();
    procedure UpdateMaxInputLength();
    procedure resetButton_Click(sender: Object; e: EventArgs);
    procedure sourceNumberInput_TextChanged(sender: Object; e: EventArgs);
    procedure sourceNumberBaseInput_SelectedIndexChanged(sender: Object; e: EventArgs);
    procedure resultNumberBaseInput_SelectedIndexChanged(sender: Object; e: EventArgs);
    procedure sourceNumberInput_KeyPress(sender: Object; e: KeyPressEventArgs);
  {$region FormDesigner}
  private
    {$resource NotationCalculatorUI.NotationCalculatorMainForm.resources}
    resetButton: Button;
    sourceNumberBaseInput: ComboBox;
    resultNumberBaseInput: ComboBox;
    resultNumberLabel: &Label;
    components: System.ComponentModel.IContainer;
    sourceNumberInput: TextBox;
    {$include NotationCalculatorUI.NotationCalculatorMainForm.inc}
  {$endregion FormDesigner}
  public 
    constructor;
    begin
      InitializeComponent;
      
      // custom initialization
      for var i := 2 to MAX_BASE do 
      begin
        sourceNumberBaseInput.Items.Add(i);
        resultNumberBaseInput.Items.Add(i);
      end;
      
      Reset;
    end;
  end;

implementation

procedure NotationCalculatorMainForm
    .resetButton_Click(sender: Object; e: EventArgs);
begin
  Reset;
end;

procedure NotationCalculatorMainForm.Recalculate;
begin
  var number := sourceNumberInput.Text;
  
  if number.Length = 0 then begin
    resultNumberLabel.Text := '';
    exit;
  end;
  
  var negative := number[1] = '-';
  if negative then delete(number, 1, 1);
  
  try
    number := FromNToM(
        number,
        StrToInt(sourceNumberBaseInput.Text),
        StrToInt(resultNumberBaseInput.Text)
    );
    
    if (negative) and (number <> '0') then begin
      resultNumberLabel.Text := '-' + number;
    end else resultNumberLabel.Text := number;
  except
    on excpetion : IllegalInputException do begin
      resultNumberLabel.Text := 'Неверный формат введённого числа';
    end;
  end;
end;

procedure NotationCalculatorMainForm.ResetMainInput;
begin
  sourceNumberInput.Text := '';
  resultNumberLabel.Text := '';
end;

procedure NotationCalculatorMainForm.Reset;
begin
  ResetMainInput;
  sourceNumberBaseInput.Text := '10';
  resultNumberBaseInput.Text := '2';
  UpdateMaxInputLength;
end;

procedure NotationCalculatorMainForm.UpdateMaxInputLength;
begin
  sourceNumberInput.MaxLength
      := GetMaxStringLength(StrToInt(sourceNumberBaseInput.Text));
end;

procedure NotationCalculatorMainForm
    .sourceNumberInput_TextChanged(sender: Object; e: EventArgs);
begin
  Recalculate;
end;

procedure NotationCalculatorMainForm
    .sourceNumberBaseInput_SelectedIndexChanged(sender: Object; e: EventArgs);
begin
  ResetMainInput;
  UpdateMaxInputLength;
  Recalculate;
end;

procedure NotationCalculatorMainForm
    .resultNumberBaseInput_SelectedIndexChanged(sender: Object; e: EventArgs);
begin
  Recalculate;
end;

procedure NotationCalculatorMainForm
    .sourceNumberInput_KeyPress(sender: Object; e: KeyPressEventArgs);
begin
  var character := e.KeyChar;
  if not Char.IsControl(character) then begin
    if (character <> '-') then begin
      character := UpCase(character);
      if not IsValid(character, StrToInt(sourceNumberBaseInput.Text)) then e
        .Handled := true;
      e.KeyChar := character;
    end;
  end;
end;

end.