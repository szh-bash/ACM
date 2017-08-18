#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int xx, yy, n, flag, x[510000], y[510000];
char s[510000][3];
int work(int i, int j){
	if (!i && !j) return 0;
	int tp1=2000000000, tp2=2000000000, f=0;
	for (int k=1;k<=n;k++){
		int tp=x[k]-xx;
		if (!tp) tp=y[k]-yy;
		if ((x[k]-xx)/tp==i && (y[k]-yy)/tp==j && (x[k]-xx)%tp==0 && (y[k]-yy)%tp==0){
			if (abs(x[k]-xx)<=tp1 && abs(y[k]-yy)<=tp2){
				tp1=abs(x[k]-xx);
				tp2=abs(y[k]-yy);
				if (i && j && (s[k][0]=='B' || s[k][0]=='Q')) f=1;
				else
					if((!j || !i) && (s[k][0]=='R' || s[k][0]=='Q')) f=1;
					else f=0;
			}
		}
	}
	return f;
}
int main(){
	cin>>n;
	cin>>xx>>yy;
	for (int i=1;i<=n;i++) scanf("%s%d%d", s[i], &x[i], &y[i]);
	for (int i=-1;i<=1;i++)
		for (int j=-1;j<=1;j++)
			flag|=work(i,j);
	if (flag) cout<<"YES"<<endl;else cout<<"NO"<<endl;
	return 0;
}
