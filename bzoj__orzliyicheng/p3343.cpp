#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, q, block, p[1100000], b[1100000];
struct zsm{
	int a[2100], w, le, ri;
	void Clear(){
		for (int i=1;i<=ri-le+1;i++) a[i]=b[i+le-1];
		sort(a+1,a+1+ri-le+1);
	}
	int Query(int x){
		x-=w;
		return ri-le+1-(lower_bound(a+1,a+1+ri-le+1,x)-a)+1;
	}
}blocks[2100];
void Solve(int l, int r, int w){
	int le=p[l], ri=p[r], ans=0;
	if (le==ri){
		for (int i=l;i<=r;i++)
			if (w<=blocks[p[i]].w+b[i]) ans++;
	}
	else{
		for (int i=l;i<=n && i<=p[l]*block;i++)
			if (b[i]+blocks[p[i]].w>=w) ans++;
		for (int i=r;i && i>(p[r]-1)*block;i--)
			if (b[i]+blocks[p[i]].w>=w) ans++;
		for (int i=p[l]+1;i<p[r];i++) ans+=blocks[i].Query(w);
	}
	printf("%d\n", ans);
}
void Modify(int l, int r, int w){
	int le=p[l], ri=p[r];
	if (le==ri){
		for (int i=l;i<=r;i++) b[i]+=w;
	}
	else{
		for (int i=l;i<=n && i<=p[l]*block;i++) b[i]+=w;
		for (int i=r;i && i>(p[r]-1)*block;i--) b[i]+=w;
		for (int i=p[l]+1;i<p[r];i++) blocks[i].w+=w;
	}
	blocks[p[l]].Clear();
	blocks[p[r]].Clear();
}
int read(){
	char ch=getchar();
	int p=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	cin>>n>>q;
	block=sqrt(n);
	for (int i=1;i<=n;i++)
		b[i]=read(),
		p[i]=(i-1)/block+1,
		blocks[p[i]].le?1:blocks[p[i]].le=i,
		blocks[p[i]].ri=i;
	for (int i=1;i<=p[n];i++) blocks[i].Clear();
	for (int i=1;i<=q;i++){
		int l, r, w;
		char s[5];
		scanf("%s%d%d%d", s, &l, &r, &w);
		switch(s[0]){
			case 'A':
				Solve(l,r,w);
				break;
			case 'M':
				Modify(l,r,w);
				break;
		}
	}
	return 0;
}
