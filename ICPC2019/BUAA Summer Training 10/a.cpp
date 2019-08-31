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
#define N 20
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
int a[]={1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
int c[N];
int f[9999];
int main(){
	cout<<0x3f3f3f3f<<endl;
	for (int _=read();_;_--){
		int p=read();
		int sum=0, sc=0;
		for (int i=0;i<10;i++) sum+=a[i]*(c[i]=read()), sc+=c[i];
		if (sum<p){
			puts("-1");
			continue;
		}
		if (sum==p){
			printf("%d\n", sc);
			continue;
		}
		int del=sum-p;
		int i=9;
		int tmp;
		for (;i>7;i--)
			tmp=del/a[i],
			sc-=min(c[i], tmp),
			del-=min(c[i], tmp)*a[i],
			c[i]-=min(c[i], tmp);
//		for (;i>=0;i--)
//			tmp=del/1000,
//			sc-=min(c[i]/(1000/a[i])*(1000/a[i]), tmp*(1000/a[i])),
//			del-=min(c[i]/(1000/a[i]), tmp)*1000,
//			c[i]-=min(c[i]/(1000/a[i])*(1000/a[i]), tmp*(1000/a[i]));
		cout<<del<<' '<<sc<<' '<<endl;
		for (int i=0;i<10;i++) cout<<c[i]<<' ';cout<<endl;
		for (int i=0;i<del+505;i++) f[i]=999999999;
		f[del]=0;
		for (int i=7;i>=0;i--){
			int T=min(c[i], del/a[i]);
			for (int j=1;j<=T;j++)
				for (int k=0;k<del;k++)
					f[k]=min(f[k], f[k+a[i]]+1);
		}
		sc-=f[0];
		if (sc<0) sc=-1;
		printf("%d\n", sc);
	}
    return 0;
}
