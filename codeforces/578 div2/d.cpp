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
#define N 2006
typedef long long ll;
using namespace std;
int n, k, hl, hr, tl, tr;
int q[N];
int nex[N], pre[N], le[N], ri[N];
int ql[N], qr[N];
int idl[N], idr[N];
char s[N][N];
int ans, anscol[N][N], presum[N];
int sum[N][N];
int col[N];
int head[N], tail[N];
int prec[N], nexc[N];
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
	n=read();k=read();
	for (int i=1;i<=n;i++){
		scanf("%s", s[i]+1);
		le[i]=n+1, ri[i]=0;
		for (int j=1;j<=n;j++){
			if (s[i][j]=='B')
				le[i]=min(le[i], j),
				ri[i]=max(ri[i], j);
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]=='B');
		}
		if (le[i]>ri[i]) q[i]=1;
		pre[i]=pre[i-1]+q[i];
	}
	for (int i=n;i;i--) nex[i]=nex[i+1]+q[i];
	for (int j=1;j<=n;j++){
		col[j]=1;
		head[j]=n+1;
		tail[j]=0;
		for (int i=1;i<=n;i++)
			if (s[i][j]=='B')
				col[j]=0,
				head[j]=min(head[j],i),
				tail[j]=max(tail[j],i);
		prec[j]=prec[j-1]+col[j];
	}
	for (int j=n;j;j--) nexc[j]=nexc[j+1]+col[j];
	
	for (int i=1;i<=n;i++){
		int hc=max(1,i-k+1), tc=i;
		for (int j=1;j<=n;j++)
			presum[j]=presum[j-1]+(head[j]>=hc && tail[j]<=tc);
		for (int j=1;j<=n;j++){
			int le=max(1,j-k+1), ri=j;
			anscol[i][j]=max(anscol[i][j],prec[le-1]+nexc[ri+1]+presum[ri]-presum[le-1]);
		}
	}
	for (int j=1;j<=n;j++){
		int hr=max(1,j-k+1), tr=j;
		for (int i=1;i<=n;i++)		
			presum[i]=presum[i-1]+(le[i]>=hr && ri[i]<=tr);
		for (int i=1;i<=n;i++){
			int head=max(1,i-k+1), tail=i;
			ans=max(ans,anscol[i][j]+pre[head-1]+nex[tail+1]+presum[tail]-presum[head-1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
