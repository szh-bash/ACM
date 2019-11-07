:loop
	data.exe
	p3772.exe
	std.exe
	fc std.out my.out 
	if %errorlevel%==0 goto loop
pause