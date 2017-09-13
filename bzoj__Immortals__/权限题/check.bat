:loop
	data.exe
	p1146.exe
	p1146_整体二分.exe
	fc 1.ans 1.out
	if %errorlevel%==0 goto loop
pause