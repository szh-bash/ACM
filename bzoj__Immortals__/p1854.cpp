#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define M 10000 
using namespace std;
int n, ans, T, result[1200000], f[1200000], cnt, next[4000000], nu[4000000];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
bool flag(int x){
	for (int j=next[x];j;j=next[j]){
		int v=nu[j];
		if (f[v]==T) continue;
		f[v]=T;
		if (!result[v] || flag(result[v])){
			result[v]=x;
			return 1;
		}
	}
	return 0;
}
int main(){
	cin>>n;
	cnt=M;
	for (int i=1;i<=n;i++){
		int x=read(), y=read();
		add(x,i+M);
		add(y,i+M);
	}
	for (ans=1, T=1;ans<=10000 && flag(ans);T++, ans++);
	cout<<ans-1<<endl;
	return 0;
}
