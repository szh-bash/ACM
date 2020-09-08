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
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
char ans[100][100];
void draw(){
	int a=read(), b=read(), c=read();
	int n=2*(b+c)+1, m=2*a+1+2*b;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) ans[i][j]='.';
	for (int i=n;(n-i)/2<c;i-=2){
		for (int j=1;j<=a*2;j+=2) 
			ans[i][j]='+',
			ans[i][j+1]='-',
			ans[i-1][j]='|';
		ans[i][a*2+1]='+';
		ans[i-1][a*2+1]='|';
	}
	for (int j=1;j<=a*2;j+=2) ans[n-2*c][j]='+', ans[n-2*c][j+1]='-';
	ans[n-2*c][a*2+1]='+';
	
	for (int i=1;i<2*b;i+=2){
		for (int j=1;j<2*a;j+=2)
			ans[i][m-j-i+2]='+',
			ans[i][m-j-i+1]='-',
			ans[i+1][m-j-i+1]='/';
		ans[i][m-2*a-i+1]='+';
		ans[i+1][m-2*a-i]='/';
	}
	
	for (int j=1;j<2*b;j+=2){
		for (int i=1;i<=2*c;i+=2)
			ans[n-j-i][2*a+1+j+1]='+',
			ans[n-j-i-1][2*a+1+j+1]='|',
			ans[n-j-i+1][2*a+j+1]='/';
		ans[n-j-1-2*c][2*a+1+j+1]='+';
		ans[n-j-2*c][2*a+j+1]='/';
	}
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) printf("%c", ans[i][j]);
		puts("");
	}
}
int main(){
	for (int _=read();_;_--) draw();
    return 0;
}
