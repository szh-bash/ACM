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
#define N 900000
#define M 900000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
#define lowbit(x) ((x)&(-x))
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n;
int cnt, ct, a1, b1, c1, a2, b2, c2, m1, m2;
int x[N], y[N], l[N], r[N];
int a[M], trans[M], b[M];
ll c[M];
map <int, int> mp;
void addb(int x, int y){
	for (int i=x;i<=ct;i+=lowbit(i)) b[i]+=y;
}
void addc(int x, int y){
	for (int i=x;i<=ct;i+=lowbit(i)) c[i]+=(trans[x]-1)*y;
}
ll calcb(int x){
	ll p=0;
	for (;x;x-=lowbit(x)) p+=b[x];
	return p;
}
ll calcc(int x){
	ll p=0;
	for (;x;x-=lowbit(x)) p+=c[x];
	return p;
}
ll calc(int x){
	return 1LL*trans[x]*calcb(x)-calcc(x);
}
int main(){
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	cin>>n;
	scanf("%d%d%d%d%d%d", &x[1], &x[2], &a1, &b1, &c1, &m1);
	scanf("%d%d%d%d%d%d", &y[1], &y[2], &a2, &b2, &c2, &m2);
	for (int i=3;i<=n;i++)
		x[i]=(1LL*a1*x[i-1]+1LL*b1*x[i-2]+c1)%m1,
		y[i]=(1LL*a2*y[i-1]+1LL*b2*y[i-2]+c2)%m2;
	for (int i=1;i<=n;i++){
		l[i]=min(x[i],y[i])+1;
		r[i]=max(x[i],y[i])+1+1;
		a[++cnt]=l[i];
		a[++cnt]=r[i];
	}
	sort(a+1,a+1+cnt);
	a[cnt+1]=a[cnt]+1;
	++cnt;
	for (int i=1;i<=cnt;i++)
		if (a[i]!=a[i-1]) trans[mp[a[i]]=++ct]=a[i];
	
	for (int i=1;i<=n;i++){
		int le=mp[l[i]], ri=mp[r[i]];
		addb(le,1);addb(ri,-1);
		addc(le,1);addc(ri,-1);
		ll target=calc(ct);
//		cout<<l[i]<<' '<<r[i]<<' '<<target<<endl;
		if (target&1) target=target/2+1;else target/=2;
		int l=1, r=ct;
		while (l<r-1){
			int mid=l+r>>1;
			ll sum=calc(mid);
//			cout<<l<<' '<<r<<' '<<mid<<' '<<sum<<endl;
			if (sum>=target) r=mid;
			else l=mid;
		}
//		cout<<l<<' '<<r<<endl;
		ll p=calcb(r);
		ll sum=calc(r)-p;
//		cout<<sum<<endl;
		ll ans;
		if (sum<target) ans=trans[r];
		else{
			p=calcb(l);
			sum=calc(l)-p;
			ans=trans[l]+(target-sum-1)/p;
		}
		printf("%lld\n", ans);
	}
    return 0;
}
