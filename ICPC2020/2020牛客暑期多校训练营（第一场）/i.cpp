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
#define N 2000
int nex[N], nu[N], cnt, n, m, t[N], d[N];
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void solve(){
	cnt=n;
	for (int i=1;i<=n;i++) d[i]=read(), nex[i]=0;
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
		t[u]++, t[v]++;
	}
	int flag=1;
	while (flag){
		flag=0;
		for (int i=1;i<=n;i++)
			if (t[i]==d[i] && t[i]){
				for (int j=nex[i];j;j=nex[j])
					if (t[nu[j]])
						t[nu[j]]--,
						d[nu[j]]--,
						t[i]--,
						d[i]--;
				flag=1; 
			}
			else if (t[i]<d[i]){
				flag=-1;
				puts("No");
				break;
			}
		if (flag<0) break;
	}
	if (flag>=0){
		puts("Yes");
	}
}
int main(){
	while (~scanf("%d%d", &n, &m)) solve();
    return 0;
}
