//ÉñÃØµÄË®¾®
#include<cstdio>
#include<iostream>
#include<algorithm>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define re(i,n) for(int i=0;i<n;i++)
#define db(x) cout<<#x<<"="<<(x)<<" "
#define el cout<<endl
using namespace std;
typedef long long ll;
const int MXN=100009,mxn=600009,inf=~0U>>1;

int x0,y0;
struct point{
	int x,y;
	void read(){scanf("%d%d",&x0,&y0);x=x0-y0,y=x0+y0;}
	bool operator <(const point&a)const{return x<a.x;}
}a[MXN],b[MXN];

int N,D;

void init(){
	scanf("%d%d",&N,&D);
	rep(i,1,N)a[i].read();
	rep(i,1,N)b[i].read();
	sort(a+1,a+N+1);
	sort(b+1,b+N+1);
}

namespace solve{

struct query{
	int x,y,val,id;
	bool operator <(const query&a)const{return x<a.x;}
}que[MXN*4];int Q;

int n=600000;
int c[mxn];
void ins(int x,int val){
	if (x>0)for(;x<=n;x+=x&-x)c[x]+=val;
}
int sel(int x){
	int S=0;
	if (x>0)for(;x;x-=x&-x)S+=c[x];
	return S;
}

ll ansa[MXN]={},ansb[MXN]={};

void dstr(point a[],point b[],ll ans[]){
	Q=0;
	int x,y;
	rep(i,1,N){
		x=a[i].x,y=a[i].y;
		que[++Q]=(query){x+D,y+D,1,i};
		que[++Q]=(query){x+D,y-D-1,-1,i};
		que[++Q]=(query){x-D-1,y+D,-1,i};
		que[++Q]=(query){x-D-1,y-D-1,1,i};
	}
	sort(que+1,que+Q+1);
	rep(i,1,n)c[i]=0;
	int p=1;
	rep(iq,1,Q){
		while (p<=N&&b[p].x<=que[iq].x){
			ins(b[p].y,1);
			p++;
		}
		ans[que[iq].id]+=sel(que[iq].y)*que[iq].val;
	}
}

ll tot1=0,tot0=0,totx=0,toty=0;
void solve(){
	dstr(a,b,ansa);
	dstr(b,a,ansb);
	rep(i,1,N) ansa[i]=N-ansa[i];
	sort(ansa+1,ansa+N+1);
	sort(ansb+1,ansb+N+1);
	//rep(i,1,N) db(ansa[i]);el;
	//rep(i,1,N) db(ansb[i]);el;
	tot0=(ll)N*N*(N-1);
	rep(i,1,N) tot1+=ansa[i]*(ansa[i]-1)/2+ansb[i]*(ansb[i]-1)/2;
	rep(i,1,N) totx+=ansa[i]*(i-1)+ansb[i]*(i-1);
	rep(i,1,N) toty+=ansa[i]*(N-i)+ansb[i]*(N-i);
	cout<<tot0-tot1-totx<<" "<<tot0-tot1-toty<<endl;
}

}

int cas;
int main(){
	init();
	solve::solve();
	return 0;
}

