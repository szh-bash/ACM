#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 100000
#define INF 99999999
using namespace std;
int n, cnt, son[N], f[N][2], nu[N*3], next[N*3], sug[N];
int read(){
	char ch=getchar();
	int p=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0',ch=getchar();
	return p;
}
void add(int u, int v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
bool cmp(int a, int b){return f[a][0]-f[a][1]<f[b][0]-f[b][1];}
void dfs(int t, int fa){
	son[t]=0;
	int tot=0,k=0;
	f[t][0]=f[t][1]=INF;
	for (int j=next[t];j;j=next[j])
		if (nu[j]!=fa){
			dfs(nu[j],t);
			son[t]++;
			tot+=f[nu[j]][1];
		}
	if (!son[t]){
		f[t][0]=f[t][1]=0;
		return;	
	}
	for (int j=next[t];j;j=next[j])
		if (nu[j]!=fa){
			f[t][0]=min(f[t][0],f[nu[j]][0]+tot-f[nu[j]][1]+son[t]-1);
			sug[++k]=nu[j];
		}
	sort(sug+1,sug+1+k,cmp);
	f[t][1]=f[t][0];
	if (k>1) 
		f[t][1]=min(f[t][1],
			tot+f[sug[1]][0]-f[sug[1]][1]+f[sug[2]][0]-f[sug[2]][1]+son[t]-2);
}
int main(){
	cnt=n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	dfs(1,-1);
	cout<<f[1][1]+1<<endl;
	return 0;
}
