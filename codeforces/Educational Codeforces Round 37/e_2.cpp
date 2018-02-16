#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
#define N 300000
using namespace std;
typedef long long ll;
map <int, bool> mp[N];
vector <int> q, ans;
int n, m, l[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int bfs(int u){
	int le=0, ri=1, size=q.size();
	l[1]=u;
	while (le<ri){
		int v=l[++le];
		for (int j=0;j<size;j++)
			if (!mp[v][q[j]]){
				l[++ri]=q[j];
				q[j--]=q[--size];
				q.pop_back();
			}
	}
	return ri;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		mp[u][v]=1;
		mp[v][u]=1; 
	}
	for (int i=1;i<=n;i++) q.push_back(i);
	while (!q.empty()){
		int v=q.back();
		q.pop_back();
		ans.push_back(bfs(v));
	}
	int cnt=ans.size(); 
	sort(ans.begin(), ans.end());
	cout<<cnt<<endl;
	for (int i=0;i<cnt;i++) printf("%d ", ans[i]);cout<<endl;
	return 0;
}
