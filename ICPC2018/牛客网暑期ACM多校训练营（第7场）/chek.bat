:loop
	j_data.exe
	j_bl.exe
	j.exe
	fc j.std j.out
	if %errorlevel%==0 goto loop
pause