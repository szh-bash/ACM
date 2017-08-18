#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m, a[200000], f[3], g[3], e[3];
int main(){
	cin>>n;
	m=n/2;
	for (int i=1;i<=n;i++){
		scanf("%d", &a[i]);
		f[a[i]]++;
	}
	int j=1;
	for (int i=1;i<=n;i++){
		g[a[i]]++;
		e[a[i]]++;
		if (g[0]*2==f[0] && g[1]*2==f[1] && g[2]*2==f[2]){
			cout<<1<<endl;
			return 0;
		}
		if (i-j==m){
			e[a[j++]]--;
			if (e[0]*2==f[0] && e[1]*2==f[1] && e[2]*2==f[2]){
				cout<<2<<endl;
				return 0;
			}
		}
	}
	cout<<3<<endl;
	return 0;
	
}
