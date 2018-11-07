program TestSelectionSort;
 
type
  TItem = Integer;   

  TArray = array of TItem;          

procedure SelectionSort(var A: TArray);
var
  Item: TItem;
  I, J, M: Integer;
 
begin
  for I:= Low(A) to High(A) - 1 do begin
    M:= I;
    for J:= I + 1 to High(A) do
      if A[J] < A[M] then M:= J;
    Item:= A[M];
    A[M]:= A[I];
    A[I]:= Item;
  end;
end;
 
var
  A: TArray;
  I: Integer;
 
begin

  SetLength(A, 16);

  for I:= Low(A) to High(A) do
    A[I]:= Random(100);
  for I:= Low(A) to High(A) do
    Write(A[I]:3);
  Writeln;
  SelectionSort(A);
  for I:= Low(A) to High(A) do
    Write(A[I]:3);
  Writeln;
  Readln;
end.
