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
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
#define N 300005
struct node{
	int x, y;
}l[N];
int f[N*9], n, m, k, cnt;
bool cmp(node a, node b){
	return a.y<b.y;
}
void upd(int t, int l, int r, int x, int y){
	if (l==r){
		f[t]+=y;
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) upd(t<<1, l, mid, x, y);
	else upd((t<<1)+1,mid+1,r,x,y);
	f[t]=max(f[t<<1],f[(t<<1)+1]);
}
int main(){
	n=read(), m=read(), k=read();
	for (int i=1;i<=k;i++)
		l[++cnt].x=read(),
		l[cnt].y=read(),
		upd(1,1,n,l[cnt].x,1);
	sort(l+1,l+1+cnt,cmp);
	int ans=f[1];
	for (int i=1, j=i;i<=cnt;){
		while (j<=cnt && l[j].y==l[i].y) upd(1,1,n,l[j++].x,-1);
		ans=max(ans,f[1]+j-i);
		while(i<j) upd(1,1,n,l[i++].x,1);
	}
	cout<<ans<<endl;
    return 0;
}
