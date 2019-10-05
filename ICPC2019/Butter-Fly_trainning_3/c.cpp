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
#define N 3000
unordered_map <int, int> mp;
int n, m, ct, a[N], b[N], c[N];
int f[N][2];
void add_(int &a, int b){
	a+=b;
	if (a>=mo) a-=mo;
}
int calc(int x){
	int sum=0;
	for (int j=x;j;j-=j&(-j)) add_(sum,c[j]);
	return sum;
}
void add(int x, int y){
	for (int j=x;j<=ct;j+=j&(-j)) add_(c[j], y);
}
int main(){
	for (int _=read(), O=1;_;_--, O++){
		n=read();m=read();
		int cnt=0;
		for (int i=1;i<=n;i++) b[++cnt]=a[i]=read(), b[++cnt]=a[i]-1;
		sort(b+1,b+1+cnt);
		b[0]=-1;
		ct=0;
		for (int i=1;i<=cnt;i++) if (b[i]!=b[i-1]) mp[b[i]]=++ct;
		for (int i=1;i<=n;i++) f[i][0]=1;
		for (int j=2, o=1;j<=m;j++, o^=1){
			for (int i=1;i<=n;i++){
				f[i][o]=calc(mp[a[i]-1]);
				add(mp[a[i]],f[i][o^1]);
//				cout<<i<<' ';for (int k=1;k<=ct;k++) cout<<c[k]<<' ';cout<<endl;
			}
			for (int i=1;i<=ct;i++) c[i]=0;
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			add_(ans,f[i][!(m&1)]);
//			cout<<i<<' '<<f[i][!(m&1)]<<endl;
		}
		printf("Case #%d: %d\n", O, ans);
	}
    return 0;
}
