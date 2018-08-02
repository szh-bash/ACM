#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mo 998244353
#define N 300000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
map <int, int> mp;
int n, cnt, ct, s, w[N], v[N];
ll ans=0;
struct qlz{
	int x, y;
}l[N];

int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
bool cmp(qlz a, qlz b) { return a.x<b.x;}
int sum(int x){
	int p=0;
	for (;x;x-=x&(-x)) p+=w[x];
	return p;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		v[++cnt]=l[i].x=read(),
		v[++cnt]=l[i].y=read();
	sort(v,v+1+cnt);
	sort(l+1,l+1+n,cmp);
	for (int i=1;i<=cnt;i++)
		if (v[i]!=v[i-1]) mp[v[i]]=++ct;
	for (int i=1;i<=n;i++)
		l[i].x=mp[l[i].x],
		l[i].y=mp[l[i].y];
	ans=n;
	for (ll i=n, j=n;i;i=j){
		for (;j && l[j-1].x==l[i].x;j--);
		//cout<<(i-j+1)*(i-j)/2<<endl;
		ans=(ans+(i-j+1)*(i-j)/2)%mo;
		for (;j<=i;j++){
			ll b=sum(l[j].y-1), c=s-sum(l[j].y);
			ans=(ans+b*c+b+c)%mo;
			//cout<<s<<' '<<b<<' '<<c<<' '<<l[j].y<<' '<<sum(l[j].y)<<endl;
		}
		for (j=i;j && l[i].x==l[j].x;j--)
			for (int k=l[j].y;k<=ct;k+=k&(-k)) w[k]++;
		s+=i-j;
	}
	cout<<ans<<endl;
    return 0;
}
