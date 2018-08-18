:loop
	f_data.exe
	f_bl.exe
	f.exe
	fc f.out f.std
	if %errorlevel%==0 goto loop
pause