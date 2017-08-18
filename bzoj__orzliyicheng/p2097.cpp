#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int mid, s, tot, v, f[110000], cnt, next[400000], nu[400000], q[110000];
void add(int u, int v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
bool cmp(int a, int b){return a>b;}
void dfs(int t, int fa){
	int j=next[t], ct=0;
	while (j){
		int v=nu[j];
		if (v!=fa) dfs(v,t);
		j=next[j];
	}
	j=next[t];
	while (j){
		if (nu[j]!=fa) q[++ct]=f[nu[j]];
		j=next[j];
	}
	q[ct+1]=0;
	sort(q+1,q+1+ct,cmp);
	for (int i=1;i<=ct;i++)
		if (q[i]+q[i+1]>mid) tot++;
			else{
				f[t]=q[i]+1;
				break;
			}
	if (!f[t]) f[t]=1;
}
int main(){
	cin>>v>>s;
	cnt=v;
	for (int i=1;i<v;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		add(x,y);
		add(y,x);
	}
	int l=-1, r=v-1;
	while (l<r-1){
		mid=l+r>>1;
		memset(f,0,sizeof(f));
		tot=0;
		dfs(1,1);
		if (tot>s) l=mid;else r=mid;
	}
	cout<<r<<endl;
	return 0;
}
