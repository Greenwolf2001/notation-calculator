unit NotationCalculatorUtil;

const MAX_BASE = 36;

var DICTIONARY : Array[0 .. MAX_BASE - 1] of Char;

// Types
type IllegalInputException = Class(Exception);

{ Преобразует код (букву)в значение (число) }
function GetValueOfCode(code : Char) : Integer;
begin
  code := UpCase(code);
  for var i := 0 to MAX_BASE - 1 do begin
    if DICTIONARY[i] = code then begin
      result := i;
      exit;
    end;
  end;
  // символ не найден в словаре
  
  raise IllegalInputException.Create(
      'Символ ' + code + ' не найден в словаре'
  );
end;

{ Преобразует значение (число) в код (букву) }
function GetCodeOfValue(value : Integer) : Char;
begin
  if (0 <= value) and (value < MAX_BASE) then begin
    result := DICTIONARY[value];
    
    exit;
  end;
  
  raise IllegalInputException.Create(
      'Число ' + value + ' не удовлетворяет промежутку [0; ' + MAX_BASE + ')'
  );
end;

{ Преобразует число <number> из системы <base> ва десятичную }
function FromNTo10(number : String; base : Integer) : Int64;
begin
    var multiplier : Int64;
    multiplier := 1;
    for var i := Length(number) downto 1 do begin
      result := result + GetValueOfCode(number[i]) * multiplier;
      multiplier := multiplier * base;
    end;
end;

{ Преобразует число <number> из десятичной системы в систему <base> }
function From10ToN(number : Int64; base : Integer) : String;
begin
  if number = 0 then begin
    result := '0';
    exit;
  end;

  while number <> 0 do begin
    result := GetCodeOfValue(number mod base) + result;
    number := number div base;
  end;
end;

{ Преобразует число <number> из десятичной системы в систему <base> }
function FromNToM(number : String; base1, base2 : Integer) : String;
begin
  if base1 = base2 then begin
    result := number;
  end else result := From10ToN(FromNTo10(number, base1), base2);
end;

function IsValid(number : String) : Boolean;
begin
  number := UpperCase(number);
  for var i := 1 to length(number) do if not(number[i] in DICTIONARY) then begin
    result := false;
    exit;
  end;
  
  result := true;
end;

function IsValid(digit : Char; base : Integer) : Boolean;
begin
    result := false;
    
    for var k := 0 to MAX_BASE - 1 do begin
      if DICTIONARY[k] = digit then begin
        if k < base then result := true;
        break;
      end;
    end;
end;

function GetMaxStringLength(const base : Integer) : Integer;
begin
  var maxDigitValue := base - 1;
  
  var multiplier, maxNumber : Int64;
  multiplier := 1;
  while maxNumber >= 0 do begin
    maxNumber := maxNumber + maxDigitValue * multiplier;
    multiplier := multiplier * base;
    result := result + 1;
  end;
  result := result - 1;
end;

// Бизнес-логика

begin
  var c := '0';
  for var i := 0 to 9 do begin
    DICTIONARY[i] := c;
    Inc(c);
  end;
  c := 'A';
  for var i := 10 to MAX_BASE - 1 do begin
    DICTIONARY[i] := c;
    Inc(c);
  end;
end.