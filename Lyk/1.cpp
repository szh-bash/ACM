#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200000
typedef long long LL; 
const LL INF=(LL)999999999*9999999;
using namespace std;
struct point{
	int x, y, px, py, n;
}l[N], q[N], p[N];
int n;
LL f[2][N], g[2][N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') q=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool cmpx(point a, point b){return a.x<b.x;}
bool cmpy(point a, point b){return a.y<b.y;}
int main(){
	while (~scanf("%d", &n)){
		for (int i=1;i<=n;i++){
			int x=read(), y=read();
			l[i].x=x;l[i].y=y;l[i].n=i;
			q[i].x=x;q[i].y=y;q[i].n=i;
			p[i].x=x;p[i].y=y;p[i].n=i;
		}
		sort(l+1,l+1+n,cmpy);
		sort(q+1,q+1+n,cmpx);
		for (int i=1;i<=n;i++)
			p[l[i].n].py=p[q[i].n].px=i;
		f[0][0]=g[0][0]=f[1][n+1]=g[1][n+1]=0;
		for (int i=1;i<=n;i++)
			f[0][i]+=f[0][i-1]+l[i].y-l[1].y,
			g[0][i]+=g[0][i-1]+q[i].x-q[1].x;
		for (int i=n;i;i--)
			f[1][i]+=f[1][i+1]-l[i].y+l[n].y,
			g[1][i]+=g[1][i+1]-q[i].x+q[n].x;
		LL ans=INF;
		for (int i=1;i<=n;i++){
			LL px=p[i].px, py=p[i].py;
			LL disx=0, disy=0;
			disy+=f[1][1]-f[1][py]+(py-1)*(p[i].y-l[n].y);
			disy+=f[0][n]-f[0][py]+(n-py)*(l[1].y-p[i].y);
			disx+=g[1][1]-g[1][px]+(px-1)*(p[i].x-q[n].x);
			disx+=g[0][n]-g[0][px]+(n-px)*(q[1].x-p[i].x);
			//if (ans>disx+disy) cout<<p[i].n<<' '<<disx<<' '<<disy<<endl;
			cout<<p[i].n<<' '<<p[i].x<<' '<<p[i].y<<' '<<disx<<' '<<disy<<endl;
			disx=disy=0;
			for (int j=1;j<=n;j++)
				disx+=abs(p[i].x-p[j].x), disy+=abs(p[i].y-p[j].y);
			cout<<disx<<' '<<disy<<endl;
			ans=min(ans,disx+disy);
		}
		cout<<ans<<endl;
	}
	return 0;
}
