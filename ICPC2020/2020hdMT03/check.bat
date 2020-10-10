:loop
	c_data.exe
	c.exe
	c_std.exe
	fc c.ans c_std.ans
	if %errorlevel%==0 goto loop
pause