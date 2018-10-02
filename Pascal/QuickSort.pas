program QuickSort;

const
    n = 10-1;

var
    A: array[0..n] of integer;
    i: integer;

procedure print();
var
    i: integer;
begin
    for i := 0 to n do
        Write(A[i], ' ');
    Writeln();
end;

function partition(start: integer; _end: integer):integer; 
var
    pivot, i, j, temp: integer;
begin
    pivot := A[(start + _end) div 2];
    i := start;
    j := _end;
    
    while i <= j do
    begin
        while A[i] < pivot do
            inc(i);
        while A[j] > pivot do
            dec(j);
        if i <= j then
        begin
            temp := A[i];
            A[i] := A[j];
            A[j] := temp;
            
            inc(i);
            dec(j);
        end;      
    end;
    
    partition := i;
end;

procedure qSort(start: integer; _end: integer);
var
    temp: integer;
begin
    if start < _end then
    begin
        temp := partition(start, _end);
        
        qSort(start, temp - 1);
        qSort(temp, _end);
    end;

end;

begin
    for i := 0 to n do
        A[i] := random(10);
    
    print();
    qSort(0, n);
    print();
end.