#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 30100
using namespace std;
int n, m, ans, cnt1, cnt2, cnt, block,
	fa[N<<1], a[N<<1], belong[N<<1],
	next[N<<3], nextt[N<<3], nu[N<<3],nuu[N<<3];
struct zsm{
	int a[210],size;
	void Insert(int x){
		int i;
		++size;
		for (i=size;i>1 && a[i-1]>x;i--)
			a[i]=a[i-1];
		a[i]=x;
	}
	int Modify(int x, int y){
		int temp=lower_bound(a+1,a+1+size,x)-a;
		for (;temp<size && a[temp+1]<y;temp++)
			a[temp]=a[temp+1];
		for (;temp>1 && a[temp-1]>y;temp--)
			a[temp]=a[temp-1];
		a[temp]=y;
	}
	int Query(int y){
		int temp=upper_bound(a+1,a+size+1,y)-a;  
        return size-temp+1;  
	}
}blocks[10100];
void add1(int u, int v){
	next[++cnt1]=next[u];next[u]=cnt1;nu[cnt1]=v;
}
void add2(int u, int v){
	nextt[++cnt2]=nextt[u];nextt[u]=cnt2;nuu[cnt2]=v;
}
void DFS(int x){
	int i;
	if (blocks[belong[fa[x]]].size==block)
		blocks[belong[x]=++cnt].Insert(a[x]),
		add2(belong[fa[x]],cnt);
	else
		blocks[belong[x]=belong[fa[x]]].Insert(a[x]);
	for (i=next[x];i;i=next[i])
		if (nu[i]!=fa[x])
			fa[nu[i]]=x,DFS(nu[i]);
}
void Blocks_DFS(int x, int y){
	int i;
	ans+=blocks[x].Query(y);
	for (i=nextt[x];i;i=nextt[i])
		Blocks_DFS(nuu[i],y);
}
void DFS(int x,int y){
	int i;
	if (a[x]>y)++ans;
	for (i=next[x];i;i=next[i])
		if (nu[i]!=fa[x])
			if (belong[nu[i]]==belong[x])
				DFS(nu[i],y);
			else
				Blocks_DFS(belong[nu[i]],y);
}
int main(){
	cin>>n;
	cnt1=cnt2=N<<1;
	for (int i=1;i<n;i++){
		int u, v;
		scanf("%d%d", &u, &v);
		add1(u,v);add1(v,u);
	}
	for (int i=1;i<=n;i++) scanf("%d", &a[i]);
	block=sqrt(n);//*&!@#@#$#$^
	DFS(1);
	cin>>m;
	for (int i=1;i<=m;i++){
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		x^=ans;y^=ans;
		switch(op){
			case 0:
				ans=0;
				DFS(x,y);
				printf("%d\n",ans);
				break;
			case 1:
				blocks[belong[x]].Modify(a[x],y);
				a[x]=y;
				break;
			case 2:
				fa[++n]=x;
				a[n]=y;
				add1(x,n);
                if(blocks[belong[x]].size==block)  
                    blocks[belong[n]=++cnt].Insert(y),
					add2(belong[x],cnt);  
                else  
                    blocks[belong[n]=belong[x]].Insert(y);   
				break;
		}
	}
	return 0;
}
