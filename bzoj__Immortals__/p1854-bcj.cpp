#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define M 10009
using namespace std;
int n, fa[M], fm[M], f[M];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
inline int father(int x){return fa[x]==x?x:fa[x]=father(fa[x]);}
int main(){
	n=read();
	for (int i=1;i<=M;i++) fa[i]=fm[i]=i;
	for (int i=1;i<=n;i++){
		int x=read(), y=read();
		if (fa[x]==fa[y]) {f[fa[x]]=1;continue;}
		if (father(x)!=father(y)) fm[fa[y]]=max(fm[fa[y]], fm[fa[x]]), fa[fa[x]]=fa[y];
		else f[fa[x]]=1;
	}
	for (int i=1;i<=M;i++)
		if (!f[father(i)] && i==fm[fa[i]]){
			cout<<i-1<<endl;
			break;
		}
	return 0;
}
