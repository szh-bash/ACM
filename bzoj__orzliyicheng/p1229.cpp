#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define inf 9999999999
using namespace std;
struct zsm{int a, b, c;};
int D, d[110000], n1, n2, c1, c2, tc, ans;
deque<zsm> l1,l2;
int f(int x){
	while (!l1.empty()) l1.pop_front();
	while (!l2.empty()) l2.pop_front();
	int tp,tmp=x*tc;
	zsm a;
	for (int i=1;i<=D;i++){
		int T=d[i];
		if (x){
			tp=min(T,x);
			a.a=i+n1, a.b=i+n2;
			a.c=tp;
			l1.push_back(a);
			x-=tp;
			T-=tp;
		}
		if (T){
			a.a=i+n1, a.b=i+n2, a.c=0;
			while (!l1.empty() && l1.front().b<=i){
				l2.push_back(l1.front());
				l1.pop_front();
			}
			while (!l2.empty() && T && l2.front().a<=i){
				tp=min(T,l2.front().c);
				tmp+=c1*tp;
				T-=tp;
				a.c+=tp;
				l2.front().c-=tp;
				if (!l2.front().c) l2.pop_front();
			}
			while (T && !l2.empty()){
				tp=min(T,l2.back().c);
				tmp+=c2*tp;
				T-=tp;
				a.c+=tp;
				l2.back().c-=tp;
				if (!l2.back().c) l2.pop_back();
			}
			if (a.c) l1.push_back(a);
			if (T) return inf;
		}
	}
	return tmp; 
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	cin>>D>>n1>>n2>>c1>>c2>>tc;
	if (n1<n2) swap(n1,n2), swap(c1,c2);
	if (c1>=c2) c1=c2, n1=n2;
	for (int i=1;i<=D;i++) scanf("%d", &d[i]);
	int l=1, r=D*60;
	while (l<r-2){
		int m1=l+(r-l)/3, m2=l+2*((r-l)/3);
		int x=f(m1), y=f(m2);
		if (x!=inf && x<=y) r=m2;else l=m1;
	}
	ans=inf;
	for (int i=l;i<=r;i++) ans=min(ans,f(i));
	printf("%d", ans);
	return 0;
}
