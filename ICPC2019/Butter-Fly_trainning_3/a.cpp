#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int a[5][5], b[5][5];
int check(){
	for (int i=1;i<=2;i++)
		for (int j=1;j<=2;j++) if (a[i][j]!=b[i][j]) return 0;
	return 1;
}
void rot(){
	swap(a[1][1], a[1][2]);
	swap(a[1][2], a[2][2]);
	swap(a[2][2], a[2][1]);
}
int main(){
	for (int _=read(), o=1;_;_--, o++){
		int ans=0;
		for (int i=1;i<=2;i++)
			for (int j=1;j<=2;j++) a[i][j]=read();
		for (int i=1;i<=2;i++)
			for (int j=1;j<=2;j++) b[i][j]=read();
		for (int i=1;i<=4;i++){
			if (check()) ans=1;
			rot();
		}
		printf("Case #%d: %s\n", o, (ans==1?"POSSIBLE":"IMPOSSIBLE"));
	}
    return 0;
}
