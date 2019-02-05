#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200000
#define M 500000
typedef long long ll;
using namespace std;
int n, m, cnt, ans[N], flag[N];
int nex[M], nu[M];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
priority_queue<int, vector<int>, greater<int> > q;
int main(){
	cnt=n=read();m=read();
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	flag[1]=1;
	q.push(1);
	for (int i=1;i<=n;i++){
		int x=q.top();
		q.pop();
		for (int j=nex[x];j;j=nex[j]){
			int v=nu[j];
			if (flag[v]) continue;
			flag[v]=1;
			q.push(v);
		}
		ans[++ans[0]]=x;
	}
	for (int i=1;i<=n;i++) printf("%d ", ans[i]);
	return 0;
}
