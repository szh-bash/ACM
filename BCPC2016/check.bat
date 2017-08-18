:loop
	data.exe
	i2.exe
	i3.exe
	fc 1.out 1.std
	if %errorlevel%==0 goto loop
pause