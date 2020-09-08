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
typedef long long ll;
using namespace std;
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
#define M 200000
struct node{
	int a, b;
}l[M];
bool cmp(node a, node b){
	if (a.b>b.b) return 1;
	if (a.b<b.b) return 0;
	return a.a>=b.a;
}
bool cmp2(node a, node b){
	return a.a<=b.a;
}
int n, m;
void solve(){
	n=read();m=read();
	for (int i=1;i<=m;i++) l[i].a=read(), l[i].b=read();
	sort(l+1,l+1+m,cmp);
	sort(l+2,l+1+m,cmp2);
//	int ct=1;
//	for (int i=2;i<=m;i++){
//		if (l[i].a<=l[1].b) continue;
//		++ct;
//		l[ct].a=l[i].a;
//		l[ct].b=l[i].b;
//	}
//	m=ct;
	ll ans=0;
	int i=m, flag=1;
	for (;i>1 && n && l[i].a>=l[1].b;i--, n--)
		if (l[1].a>l[i].a && flag)
			flag=0,
			ans+=l[1].a,
			i++;
		else ans+=l[i].a;
	if (n){
		if (i==1) ans+=1ll*(n-flag)*l[1].b+l[1].a*flag;
		else{
			ll tmp0=1ll*(n-flag)*l[1].b+l[1].a*flag;
			ll tmp1=0;
			if (n<i)
				for (int j=i;j>1 && n;j--, n--) tmp1+=l[j].a;
			ans+=max(tmp0,tmp1);
		}
	}
	cout<<ans<<endl;
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
