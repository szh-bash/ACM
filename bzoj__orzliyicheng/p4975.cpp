#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a[100], ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i]<a[j]) ans++;
	if (ans&1) cout<<"Q"<<endl;
	else cout<<"T"<<endl;
	return 0;
}
