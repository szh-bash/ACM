#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200010
typedef long long ll;
using namespace std;
int n, m, ans;
struct qlz{
	int l, r;
}l[N];
multiset<int> s;
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
bool cmp(qlz a, qlz b){
	if (a.r<b.r) return 1;
	if (a.r>b.r) return 0;
	return a.l<b.l;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) s.insert(read());		
	for (int i=1;i<=m;i++)
		l[i].l=read(),
		l[i].r=read();
	sort(l+1,l+1+m,cmp);
	int j=1;
	for (int i=1;i<=m;i++){
		multiset<int>::iterator it=s.lower_bound(l[i].l);
		if (it!=s.end() && *it<=l[i].r){
			ans++;
			s.erase(it);
		}
	}
	cout<<ans<<endl;
	return 0;
}
