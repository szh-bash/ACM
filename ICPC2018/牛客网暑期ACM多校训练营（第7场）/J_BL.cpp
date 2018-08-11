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
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, tag[100], g[1005][1005], q[1005], w[1005];
ll ans;
short a[1005][1005];
char s[1005];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
bool check(int l1, int r1, int l2, int r2){
	for (int i=l1;i<=l2;i++){
		for (int j=1;j<=52;j++) tag[j]=0;
		for (int j=r1;j<=r2;j++)
			if (tag[a[i][j]]) return 0;
			else tag[a[i][j]]=1;
	}
	for (int j=r1;j<=r2;j++){
		for (int i=1;i<=52;i++) tag[i]=0;
		for (int i=l1;i<=l2;i++)
			if (tag[a[i][j]]) return 0;
			else tag[a[i][j]]=1;
	}
	return 1;
}
int main(){
	freopen("j.in","r",stdin);
	freopen("j.std","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++){
		scanf("%s", s+1);
		for (int j=1;j<=m;j++)
			if (s[j]>='a') a[i][j]=s[j]-'a'+27;
			else a[i][j]=s[j]-'A'+1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)	
			for (int p=i;p<=n;p++)
				for (int q=j;q<=m;q++)
					if (check(i,j,p,q)) ans++;
	cout<<ans<<endl;
	return 0;
}
