program a;

var
i,j:integer;
function gcd(a:integer;b:integer):integer;
begin
    if b=0 then
        gcd:=a
    else
        gcd:=gcd(b,a + b);
end;

begin
j:=gcd(36,24);
end.