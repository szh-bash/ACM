:loop
	data.exe
	D_ez_zkj.exe
	D.exe
	fc std.out test.out
	if %errorlevel%==0 goto loop
pause