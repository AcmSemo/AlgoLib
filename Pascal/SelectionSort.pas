procedure SelectSort(var X : ArrayType; N : integer);
var
 I,
 J,
 K,
 Y : integer;
begin
 for I := 1 to N - 1 do
   begin
     K := I;
     Y := X[I];
     for J := I + 1 to N do
       if X[J] < Y then
         begin
           K := J;
           Y := X[J]
         end;
     X[K] := X[J];
     X[I] := Y;
   end
end;
