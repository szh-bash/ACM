#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200000
typedef long long ll;
using namespace std;
struct qlz{
	int l, r;
}a[N];
int n, m, ans, c[N];
inline int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
inline bool cmp(qlz a, qlz b){return a.l<b.l;}
inline int sum(int x){
	int p=0;
	for (int j=x;j;j-=j&(-j)) p+=c[j];
	return p;
}
int main(){
	m=(n=read())*2;
	for (int i=1;i<=m;i++){
		int x=read();
		if (!a[x].l) a[x].l=i;
		else a[x].r=i;
	}
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++){
		ans+=sum(a[i].r)-sum(a[i].l);
		for (int j=a[i].r;j<=m;j+=j&(-j)) c[j]++;
	}
	cout<<ans<<endl;
	return 0;
}
