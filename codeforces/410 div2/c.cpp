#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a[120000], ans;
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d", &a[i]);
	int cnt=a[1];
	for (int i=2;i<=n;i++) cnt=gcd(cnt,a[i]);
	cout<<"YES"<<endl;
	if (cnt>1) cout<<0<<endl;
	if (cnt==1){
		int t=0;
		a[++n]=0;
		for (int i=1;i<=n;i++)
			if (a[i]%2==0)
				ans+=(t+1)/2+(t&1), t=0;
			else t++;
		cout<<ans<<endl;
	}
	return 0;
}
