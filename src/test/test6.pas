program a;

var
i:integer;
function ff(u:integer):integer;
var x:integer;
    function gg(v:integer):integer;
    var y:integer;
        function hh(w:integer):integer;
            var z:integer;
            begin
                z:=10;
                hh:=w;
                x:=11;
                y:=12;
            end;
        begin
            gg:=hh(v+1);
        end;
    begin
        ff:=gg(u+1);
    end;

begin

i:=ff(1);

end.