#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#define bit(x) x&(-x)
const int N=100000;
int n,m,c[N],a[N];
int add(int i,int x){for (;i<=n;i+=bit(i)) c[i]=min(c[i],x); }
int Min(int l,int r){
	int ans=1e9;
	while (l<=r){
		if (r-bit(r)>=l-1) { ans=min(ans,c[r]); r-=bit(r); } 
		else ans=min(ans,a[r--]);
	}
	return ans;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) c[i]=1e9;
	for (int i=1;i<=n;i++){
		scanf("%d", &a[i]);
		add(i,a[i]);
	}
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",Min(x,y));
	}
	return 0;
}
