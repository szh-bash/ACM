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
#define N 100
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int m, ans, flag[N], x[N], y[N], ct, c[N], con[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int check(){
	int p=0;
	for (int i=1;i<=ct;i++)
		for (int j=i+1;j<=ct;j++){
			int u1=x[c[i]]-x[con[c[i]]], v1=y[c[i]]-y[con[c[i]]];
			int u2=x[c[j]]-x[con[c[j]]], v2=y[c[j]]-y[con[c[j]]];
			if (!u1 && !u2) {p++; continue;}
			if (!u1 || !u2) continue;
			if (v1*u2==u1*v2) {p++; continue;}			
		}
	return p;
}
void dfs(int t){
	if (t>m){
		//cout<<"lyk"<<' '<<ct<<' '<<check()<<endl;
		ans=max(ans,check());
		return;
	}
	if (flag[t]) { dfs(t+1);return;}
	flag[t]=1;
	c[++ct]=t;
	for (int i=t+1;i<=m;i++)
		if (!flag[i]){
			flag[i]=1;
			con[t]=i;
			dfs(t+1);
			flag[i]=0;
		}
	flag[t]=0;
	ct--;
}
int main(){
	m=read();
	for (int i=1;i<=m;i++) x[i]=read(), y[i]=read();
	dfs(1);
	cout<<ans<<endl;
    return 0;
}
