program Loop;
var
   a: integer;
   S: integer;
begin
   a := 10;
   repeat
      a := a + 1
   until a = 20;

   For a := 1 to 100 do
   Begin
       S := S+a;
   End;

   while  a > 0  do
   Begin
       S := 1;
       a := 1;
   End;
end.