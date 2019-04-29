:loop
	b_data.exe
	b.exe
	b_baoli.exe
	fc b.ans b.out
	if %errorlevel%==0 goto loop
pause