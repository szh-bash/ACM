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
#define N 300000
int n, sum;
int p[N][2], g[2], bit[N], ans[N];
char s[N];
void solve(int x){
	int v=s[x]=='1'?1:-1;
	if (sum==1 && v>0) return;
	ans[x]++;
	int k=(g[v>0]-(v>0)*p[n-x-1][1]+(v<0)*p[n-x-1][0])%(sum-v);
	k=(k+sum-v)%(sum-v);
	while (k){
		k=k%bit[k];
		ans[x]++;
	}
}
int get(int mo){
	int p=0;
	for (int i=0;i<n;i++){
		p=(p<<1)+(s[i]=='1');
		if (p>=mo) p-=mo;
	}
	return p;
}
int main(){
	n=read();
	scanf("%s", s);
	for (int i=0;i<n;i++) sum+=s[i]=='1';
	if (sum>1){
		g[1]=get(sum-1);
		p[0][1]=1%(sum-1);
		for (int i=1;i<n;i++) p[i][1]=(p[i-1][1]<<1)%(sum-1);
	}
	g[0]=get(sum+1);
	p[0][0]=1%(sum+1);
	for (int i=1;i<n;i++) p[i][0]=(p[i-1][0]<<1)%(sum+1);
	for (int i=1;i<n;i++) bit[i]=bit[i>>1]+(i&1);
	for (int i=0;i<n;i++) solve(i);
	for (int i=0;i<n;i++) printf("%d\n", ans[i]);
    return 0;
}
