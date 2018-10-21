program arraytest;

type
    a = array[1..10] of integer;
var
    i:a;

begin
    i[1]:=1;
    i[2]:=10;
    i[3]:=100;
end
.