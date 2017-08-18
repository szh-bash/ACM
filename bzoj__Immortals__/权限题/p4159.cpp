#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m, ans=1000000000;
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		int u, v, w;
		cin>>u>>v;
		w=u*n;
		w%=u+v;
		if (!w) w+=u+v;
		ans=min(ans,w);
	}
	cout<<ans<<endl;
	return 0;
}
