#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define M 2020
using namespace std;
int n, a[M], ans;
map<int ,int> f[M];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d", &a[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++){
			f[i][a[j]]=max(f[i][a[j]],f[j][a[j]*2-a[i]]+1);
			ans=max(ans,f[i][a[j]]);
		}
	cout<<ans+1<<endl;
	return 0;
}
