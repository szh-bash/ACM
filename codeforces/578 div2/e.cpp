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
#define mo 572089397
typedef long long ll;
using namespace std;
const int seed=177;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) scanf("%s", ss[i]+1), len[i]=strlen(ss[i]+1);
	bit[0]=1;
	for (int i=1;i<N;i++) bit[i]=bit[i-1]*seed%mo;
	for (int i=1;i<=n;i++){
		for (int j=len[i];j;j--)
			suf[j]=(suf[i+1]*seed+s[i][j])%mo;
		for (int j=1;j<=len[i];j++)
			pre[j]=(pre[i-1]+s[i][j]*bit[j])%mo;
	}
	for (int i=1;i<n;i++){
		suff[len[i]+1]=0;
		for (int j=len[i];j;j--)
			suff[j]=(suf[i+1]*seed+s[i][j])%mo;
		for (int j=1;j<=len[i];j++)
			pree[j]=(pre[i-1]+s[i][j]*bit[j])%mo;
		int j=1;
		for (;j<=len[i+1] && j<=ls;j++)
			if (same()) p=j;
		for (;j<=len[i+1];j++) suf[++ls]=suf
	}
	return 0;
}
