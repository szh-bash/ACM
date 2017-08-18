#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m, cnt, l[10000], next[10000], nu[10000], a[10000], b[10000], f[10000], flag[10000];
char ans[2000];
void insert(int t, int u, char v){
	a[t]=u;b[t]=v=='Y';
}
void add(int u, int v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
int check(int x){
	int f1=1, f2=1, le=0, ri=0;
	memset(f,0,sizeof(f));
	memset(flag,-1,sizeof(flag));
	flag[x]=1;
	for (int i=2;i<=m*2+1;i++)
		if (!f[i^1] && a[i]==x && !b[i]){
			f[i^1]=1;
			l[++ri]=i^1;
			while (le<ri){
				int u=l[++le], j=next[u];
				if (flag[a[u]]==-1)
					flag[a[u]]=b[u];
				else
					if (b[u]!=flag[a[u]]){
						f1=0;
						break;
					}
				while (j){
					int v=nu[j];
					if (!f[v]){
						f[v]=1;
						l[++ri]=v;
					}
					j=next[j];
				}
			}
			if (!f1) break;
		}
	le=ri=0;
	memset(f,0,sizeof(f));
	memset(flag,-1,sizeof(flag));
	flag[x]=0;
	for (int i=2;i<=m*2+1;i++)
		if (!f[i^1] && a[i]==x && b[i]){
			//cout<<le<<' '<<ri<<endl;
			//cout<<x<<' '<<i<<' '<<a[i]<<' '<<b[i]<<endl; 
			//cout<<i<<endl;
			f[i^1]=1;
			l[++ri]=i^1;
			//cout<<le<<' '<<ri<<endl;
			while (le<ri){
				int u=l[++le], j=next[u];
				//cout<<i<<' '<<a[i]<<' '<<x<<' '<<a[u]<<' '<<b[u]<<' '<<flag[x]<<' '<<"n"<<endl;
				if (flag[a[u]]==-1)
					flag[a[u]]=b[u];
				else
					if (b[u]!=flag[a[u]]){
						f2=0;
						break;
					}
				while (j){
					int v=nu[j];
					if (!f[v]){
						f[v]=1;
						l[++ri]=v;
					}
					j=next[j];
				}
			}
			if (!f2) break;
		}
	//for (int i=2;i<=2*m+1;i++) cout<<i<<' '<<f[i]<<endl;
	if (f1 && f2) return 0;
	if (f1) return 1;
	if (f2) return -1;
	return -2;
}
int main(){
	cin>>n>>m;
	cnt=m*2;
	for (int i=1;i<=m;i++){
		char s1[10], s2[10];
		int aa, bb, u=i*2, v=i*2+1;
		scanf("%d%s%d%s", &aa, s1, &bb, s2);
		insert(u, aa, s1[0]);
		insert(v, bb, s2[0]);
		for (int j=2;j<i*2;j++){
			if (a[j]==a[u] && b[j]!=b[u]){
				add(u,j^1);
				add(j,v);
			}
			
			if (a[j]==a[v] && b[j]!=b[v]){
				add(v,j^1);
				add(j,u);
			}
		}
	}
	//for (int i=2;i<=2*m+1;i++) cout<<i<<' '<<a[i]<<' '<<b[i]<<endl;
	for (int i=1;i<=n;i++){
		int ff=check(i);
		if (ff==-2){
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
		if (!ff) ans[i]='?';
		if (ff==1) ans[i]='Y';
		if (ff==-1) ans[i]='N';
	}
	for (int i=1;i<=n;i++)
		printf("%c", ans[i]);
	return 0;
}
