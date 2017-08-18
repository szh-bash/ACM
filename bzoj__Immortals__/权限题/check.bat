:loop
	data.exe
	p4017.exe
	p4017_tangjz.exe
	fc 1.ans 1.out
	if %errorlevel%==0 goto loop
pause