:loop
	data.exe
	p4977.exe
	p4977_std.exe
	fc 1.out 1.ans
	if %errorlevel%==0 goto loop
pause