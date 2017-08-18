#include <cstdio>
	#include <cstring>
	#include <cstdlib>
	#include <iostream>
	using namespace std;
	int main(){
		char a, b;
		a=getchar();
		b=getchar();
		int ans=8, f1=0, f2=0;
		if (a=='a' || a=='h') ans-=3, f1=1;
		if (b=='1' || b=='8') ans-=3, f2=1;
		if (f1 && f2) ans+=1;
		cout<<ans<<endl;
		return 0;
	}
