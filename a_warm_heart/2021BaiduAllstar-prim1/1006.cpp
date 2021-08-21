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
#define N 5000005
int n, fa[N], g[N], a[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int father(int x){return fa[x]==x?x:fa[x]=father(fa[x]);}
int main(){
	n=read();
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=n;i++){
		int op=read(), x=read();
		if (op==1){
			if (!a[x]){
				a[x]=g[x]=1;
				if (a[x-1]==1) g[fa[x]]+=g[father(x-1)], fa[father(x-1)]=father(x);
				if (a[x+1]==1) g[fa[x]]+=g[father(x+1)], fa[father(x+1)]=father(x);
			}
			// cout<<father(1)<<' '<<g[father(1)]<<' '<<x<<endl;
		}
		else{
			// cout<<father(1)<<' '<<g[father(1)]<<' '<<x<<endl;
			if (a[x] || (x>1 && g[father(1)]<x-1)){
				printf("%d\n", g[father(1)]+1);
				continue;
			}
			printf("%d\n", x+g[father(x+1)]+1);
		}
	}
    return 0;
}
