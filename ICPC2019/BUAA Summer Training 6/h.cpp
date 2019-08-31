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
#define N 100
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int nex[N], nu[N], d[N], cnt;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
int main(){
	int n=6;
	for (int _=read();_;_--){
		cnt=n;
		for (int i=1;i<=n;i++) nex[i]=d[i]=0;
		int p=0, tmp=0;
		for (int i=1;i<n;i++){
			int u=read(), v=read();
			add(u, v);
			add(v, u);
			d[u]++;
			d[v]++;
		}
		for (int i=1;i<=n;i++)
			if (d[i]>p) p=d[i], tmp=1;
			else if (d[i]==p) tmp++;
		if (p==2){
			puts("n-hexane");
		}
		else if (p==3 && tmp==1){
			int id=1;
			int tmp=0;
			for (;id<=n;id++)
				if (d[id]==3) break;
			for (int j=nex[id];j;j=nex[j])
				if (d[nu[j]]==2) tmp++;
			if (tmp==1) puts("2-methylpentane");
			else puts("3-methylpentane");
		}
		else if (p==3 && tmp==2){
			puts("2,3-dimethylbutane");
		}
		else if (p==4){
			puts("2,2-dimethylbutane");
		}
	}
    return 0;
}
