#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 1000005
typedef long long ll;
using namespace std;
int n, w, index;
struct njh{
	int x;
	int le, ri;
}l[N];
ll tag[N];
char s[1<<26];
int reads(){
	int p=0, q=1;
	while (s[index]<'0' || s[index]>'9') if (s[index++]=='-') q=-1;
	while (s[index]>='0' && s[index]<='9') p=p*10+s[index++]-'0';
	return p*q;
}
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
//	fread(s,1,1<<25,stdin);
	n=read();w=read();
	for (int i=1;i<=n;i++){
		int m=read();
		int ct=1;
		l[1].x=0;
		l[1].le=0;
		l[1].ri=w-m;
		for (int j=1;j<=m;j++){
			int x=read(); 
			while (ct && l[ct].x<x && l[ct].le>=j) ct--; 
			l[++ct].x=x;
			if (l[ct].x<=l[ct-1].x)
				l[ct].le=l[ct-1].ri+1;
			else{
				l[ct-1].ri=j-1;
				l[ct].le=j;
			}
			l[ct].ri=j+w-m;
		}
		while (ct && l[ct].x<0 && l[ct].le>m) ct--;
		if (l[ct].x<0) l[ct].ri=m;
		for (int k=2;k<=ct;k++)
			tag[l[k].le]+=l[k].x,
			tag[l[k].ri+1]-=l[k].x; 
	}
	ll ans=0;
	for (int i=1;i<=w;i++) printf("%I64d ", ans+=tag[i]);
	return 0;
}
