:loop
	data.exe
	std.exe
	bruteforce.exe
	fc std.out bruteforce.out
	if %errorlevel%==0 goto loop
pause