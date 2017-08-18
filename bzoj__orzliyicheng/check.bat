:loop
	data.exe
	1.exe
	1774.exe
	fc 1.out std.out
	if %errorlevel%==0 goto loop
pause