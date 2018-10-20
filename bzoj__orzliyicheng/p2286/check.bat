:loop
	data.exe
	std.exe
	p2286.exe
	fc std.out emm.out
	if %errorlevel%==0 goto loop
pause