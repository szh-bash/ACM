g++ data.cpp -o data -O2 -Wall -Wextra "-Wl,--stack=268435456" -std=c++17 -lwsock32 
g++ j.cpp -o j -O2 -Wall -Wextra "-Wl,--stack=268435456" -std=c++17 -lwsock32 
g++ bf.cpp -o bf -O2 -Wall -Wextra "-Wl,--stack=268435456" -std=c++17 -lwsock32 
:loop
	data.exe
	j.exe
	bf.exe
	fc std.out bf.out
	if %errorlevel%==0 goto loop
pause