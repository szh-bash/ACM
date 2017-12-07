:loop
	data.exe
%time%
	p2258.exe
%time%
	std.exe
	fc 1.out std.out
	if %errorlevel%==0 goto loop
pause