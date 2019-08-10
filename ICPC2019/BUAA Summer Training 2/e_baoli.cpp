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
#define lowbit(x) ((x)&(-x))
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n;
int cnt, ct, a1, b1, c1, a2, b2, c2, m1, m2;
int x[N], y[N], l[N], r[N];
int f[M];
int main(){
	freopen("e.in","r",stdin);
	freopen("e.ans","w",stdout);
	cin>>n;
	scanf("%d%d%d%d%d%d", &x[1], &x[2], &a1, &b1, &c1, &m1);
	scanf("%d%d%d%d%d%d", &y[1], &y[2], &a2, &b2, &c2, &m2);
	for (int i=3;i<=n;i++)
		x[i]=(1LL*a1*x[i-1]+1LL*b1*x[i-2]+c1)%m1,
		y[i]=(1LL*a2*y[i-1]+1LL*b2*y[i-2]+c2)%m2;
	for (int i=1;i<=n;i++){
		l[i]=min(x[i],y[i])+1;
		r[i]=max(x[i],y[i])+1+1;
	}
	ll sum=0;
	int ma=0;
	for (int i=1;i<=n;i++){
		int le=l[i], ri=r[i], ans;
		sum+=ri-le;
		ma=max(ma,ri);
		for (int j=le;j<ri;j++) f[j]++;
		ll tmp=0;
		for (int j=1;j<ma;j++)
			if (tmp+f[j]>=(sum+1)/2){
				ans=j;
				break;
			}
			else tmp+=f[j]; 
		printf("%d\n", ans);
	}
    return 0;
}
