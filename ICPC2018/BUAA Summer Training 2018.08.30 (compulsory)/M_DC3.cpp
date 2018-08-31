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
#define M 1500000
#define N 500000
#define S 400000*15*5
#define mo 1000000007
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int sa[10*N],rk[N];
int r[10*N],wa[10*N],wb[10*N],wv[10*N], a[N*10];
int wws[10*N];
int n, x, mm;
int fr[N], k[N], f[M+N*3];
char ss[S+10];
int read(){
	int p=0;
	while (ss[x]!='\0' && (ss[x]<'0' || ss[x]>'9')) x++;
	while (ss[x]>='0' && ss[x]<='9') p=p*10+ss[x++]-'0';
	return p;
}
/*int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}*/
void upd(int t, int l, int r, int x, int y){
	while (l<r){
		int mid=l+r>>1;
		if (x<=mid) r=mid, t<<=1;
		else l=mid+1, t=(t<<1)+1;
	}
	f[t]=y;
	while (t>1){
		t>>=1;
		f[t]=f[t<<1]|f[(t<<1)+1];
	}
}
int query(int t, int l, int r){
	while (l<r){
		int mid=l+r>>1;
		if (f[t<<1]) r=mid, t<<=1;
		else l=mid+1, t=(t<<1)+1;
	}
	f[t]=0;
	while (t>1){
		t>>=1;
		f[t]=f[t<<1]|f[(t<<1)+1];
	}
	return l;
}
void reset(int t, int l, int r){
	if (l==r) {f[t]=0;return;}
	reset(t<<1,l,l+r>>1);
	reset((t<<1)+1,((l+r)>>1)+1,r);
	f[t]=0;
}

void sort(int *r,int *a,int *b,int n,int m)
{
    int i;
    for(i=0;i<n;i++) wv[i]=r[a[i]];
    for(i=0;i<m;i++) wws[i]=0;
    for(i=0;i<n;i++) wws[wv[i]]++;
    for(i=1;i<m;i++) wws[i]+=wws[i-1];
    for(i=n-1;i>=0;i--) b[--wws[wv[i]]]=a[i];
    return;
}
int c0(int *r,int a,int b) {return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];}

int c12(int k,int *r,int a,int b)
{
    if(k==2) return r[a]<r[b]||(r[a]==r[b]&&c12(1,r,a+1,b+1));
    else     return r[a]<r[b]||(r[a]==r[b]&&wv[a+1]<wv[b+1]);
}


void dc3(int *r,int *sa,int n,int m)
{
    int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
    r[n]=r[n+1]=0;
    for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;
    sort(r+2,wa,wb,tbc,m);
    sort(r+1,wb,wa,tbc,m);
    sort(r,wa,wb,tbc,m);
    for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++) rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
    if(p<tbc) dc3(rn,san,tbc,p);
    else for(i=0;i<tbc;i++) san[rn[i]]=i;
    for(i=0;i<tbc;i++) if(san[i]<tb) wb[ta++]=san[i]*3;
    if(n%3==1) wb[ta++]=n-1;
    sort(r,wb,wa,ta,m);
    for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;
    for(i=0,j=0,p=0;i<ta && j<tbc;p++)
          sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(;i<ta;p++) sa[p]=wa[i++];
    for(;j<tbc;p++) sa[p]=wb[j++];
}
int main(){
	//freopen("M.in","r",stdin);
	fread(ss,1,S,stdin);
	while (mm=read()){
	//while (~scanf("%d", &mm)){
		int ls=0, sum=0;
		a[ls++]=301;
		for (int i=1;i<=mm;++i){
			fr[i]=ls;
			k[i]=read();
			for (int j=1;j<=k[i];j++) a[ls++]=read();
			a[ls++]=301;
			sum+=k[i];
		}
		n=ls; int m=355;                   //s从0开始   n长度  m字符集大小 
		for (int i=0;i<n;i++) r[i]=(int)a[i]; r[n]=0;
		dc3(r,sa,n+1,m+1);			              //dc3过程后r会被破坏  
		for (int i=1;i<=n;i++) rk[sa[i]]=i;
		for (int i=1;i<=n;i++) sa[i]++;
		for (int i=n;i>0;i--) rk[i]=rk[i-1];      //sa、rk均从下标1开始 
		reset(1,0,ls);
		for (int i=1;i<=mm;++i)
			upd(1,0,ls,rk[fr[i]+1],1);
		int ans=0;
		while (sum--){
			int v=query(1,0,ls);
			upd(1,0,ls,rk[sa[v]+1],1);
			ans=(1ll*ans*365+a[sa[v]-1])%mo;
			//cout<<v<<' '<<sa[v]<<' '<<a[sa[v]]<<endl;
		}
		//cout<<ans<<endl;
		ans=1ll*ans*365%mo;
		printf("%d\n", ans);
		//cout<<ans*365%mo<<endl;
	}
    return 0;
}
