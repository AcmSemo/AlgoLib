const number = maxint;
var 
a, 
b, 
c : array [1..1000] of integer;

procedure generovanie (n : integer);
var i : integer;

begin
  randomize;
  for i := 1 to n 
  do a[i] := random (20000);
end;

procedure vypis (n : integer);
var i : integer;

begin
  for i := 1 to n 
  do write (a[i], ' '); 
  writeln;
end;

procedure merge (l, m, r : integer);
    var i, j, k : integer;
        begin
            for i := l to m do b[i] := a[i];
                i := l; b[m+1] := number;
            for j := m+1 to r do c[j] := a[j];
                j := m+1; c[r+1] := number; k := l;
            while (b[i]<number) or (c[j]<number) do
                if b[i]<c[j] then 
                    begin a[k] := b[i]; inc (i); inc(k); 
                    end
                    else 
                    begin a[k] := c[j]; inc (j); inc(k); 
                    end;
        end;



procedure mergesort (l, r : integer);

    var m : integer;
        begin
            if l < r then 
                begin
                m := (l+r) div 2;
                mergesort (l, m);
                mergesort (m+1, r);
                merge (l, m, r);
                end;
        end;



begin
  generovanie (1000);
  mergesort (1,1000);
  vypis (1000);
end.
