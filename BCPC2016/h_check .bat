:loop
	data_h.exe
	h.exe
	h2.exe
	fc h.out h.ans
	if %errorlevel%==0 goto loop
pause