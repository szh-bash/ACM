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
typedef long long ll;
using namespace std;
int n, k, top, cnt, ans[N], stack[N], pre[N], nex[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();k=read();
	int y=1;
	for (int i=1;i<=n;i++)
		pre[i]=i-1,
		nex[i]=i+1;
	for (int i=1;i<=k;i++){
		int x=read();
		ans[++cnt]=x;
		if (top && x>stack[top]){
			cout<<-1<<endl;
			return 0;
		}
		stack[++top]=x; 
		while (top && stack[top]==y){
			int v=stack[top--];
			nex[pre[v]]=nex[v];
			pre[nex[v]]=pre[v];
			y++;
		}
	}
	//cout<<cnt<<' '<<y<<' '<<top<<endl;
	//cout<<"lyk"<<endl;
	while (y<=n){
		//cout<<y<<' '<<top<<endl;
		if (!top && y<=n) stack[top=1]=n, ans[++cnt]=n--;
		while (top && stack[top]>y){
			int u=stack[top];
			ans[++cnt]=stack[++top]=pre[u];
		}
		while (top && stack[top]==y){
			int v=stack[top--];
			nex[pre[v]]=nex[v];
			pre[nex[v]]=pre[v];
			y++;
		}
	}
	for (int i=1;i<=cnt;i++) printf("%d ", ans[i]);
	return 0;
}
