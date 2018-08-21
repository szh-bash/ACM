:loop
	f_data.exe
echo %time%
	f_jiry_2.exe
echo %time%
	f_2.exe
echo %time%
	fc f.out f_jiry_2.out
	if %errorlevel%==0 goto loop
pause