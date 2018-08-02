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
#define N 200000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
map<int, int> mp;
int n, m, cnt, a[N];
struct qlz{
	int n, v, pre, nex;
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
bool cmp(qlz a, qlz b){ return a.n>b.n;}
int main(){
	for (int _=read();_;_--){
		for (int i=0;i<=cnt+1;i++) l[i].n=l[i].v=l[i].pre=l[i].nex=0;
		cnt=0;
		mp.clear();
		n=read();m=read();
		
		for (int i=1;i<=n;i++){
			if (!mp[a[i]=read()]) l[mp[a[i]]=++cnt].v=a[i];
			l[mp[a[i]]].n++;
		}
		sort(l+1,l+1+cnt,cmp);
		for (int i=1, j=0;i<=cnt;i++){
			if (l[i-1].n!=l[i].n) j=1;else j++;
			l[i].pre=j;
		}
		for (int i=cnt, j=0;i;i--){
			if (l[i+1].n!=l[i].n) j=1;else j++;
			l[i].nex=j;
		}
		int ans=-1, sum=0;
		l[0].n=l[1].n;
		for (int i=1, w=0;i<=cnt;i++){
			if (l[i-1].n!=l[i].n){
				w+=(i-1)*(l[i-1].n-l[i].n)+l[i-1].pre;
			}
			int k=l[i].pre+l[i].nex-2+w;
			if (k<=m) ans=max(ans,l[i].v);
			//cout<<i<<' '<<l[i].v<<' '<<l[i].n<<' '<<w<<' '<<k<<endl;
		}
		printf("%d\n", ans);
	}
    return 0;
}
