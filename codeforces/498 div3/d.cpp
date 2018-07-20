#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200000
typedef long long ll;
using namespace std;
int n, f[N], g[200], ans;
char s1[N], s2[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	scanf("%s%s", s1+1, s2+1);
	for (int i=1;i<=n;i++)
		if (!f[i]){
			if ((n&1) && (i==n/2+1)){
				ans+=s1[i]!=s2[i];
				break;
			}
			int t=0;
			f[i]=f[n-i+1]=1;
			if (!g[s1[i]]) t++;g[s1[i]]++;
			if (!g[s2[i]]) t++;g[s2[i]]++;
			if (!g[s1[n-i+1]]) t++;g[s1[n-i+1]]++;
			if (!g[s2[n-i+1]]) t++;g[s2[n-i+1]]++;
			if (t==4) ans+=2;
			if (t==3)
				if (s1[i]==s1[n-i+1]) ans+=2;else ans+=1;
			if (t==2 && g[s1[i]]!=2) ans+=1;
			g[s1[i]]=0;
			g[s2[i]]=0;
			g[s1[n-i+1]]=0;
			g[s2[n-i+1]]=0;
		}
	cout<<ans<<endl;
	return 0;
}
