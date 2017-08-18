#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m, a[200], p;
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		for (int j=i;j<=n;j+=j&(-j)) a[j]+=x;
	}
	for (int j=1;j<=m;j++){
		int l, r, ans=0;
		cin>>l>>r;
		for (int i=r;i;i-=i&(-i))
			ans+=a[i];
		for (int i=l-1;i;i-=i&(-i))
			ans-=a[i];
		if (ans>0) p+=ans;
	}
	cout<<p<<endl;
	return 0;
}
