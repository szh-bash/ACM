:loop
	e_data.exe
	e_baoli.exe
	e.exe
	fc e.ans e.out
	if %errorlevel%==0 goto loop
pause