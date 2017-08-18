#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a[110000], b;
int main(){
	cin>>n;
	int a1=0, a2=999999999;
	for (int i=1;i<=n;i++) scanf("%d", &a[i]), a1=max(a1,a[i]), a2=min(a2,a[i]);
	int flag=0;
	for (int i=1;i<=n;i++) if (a[i]!=a1 && a[i]!=a2) {flag=1;break;} 
	if (!flag){
		cout<<"YES"<<endl;
		return 0;
	}
	b=(a1+a2)/2;
	if (b*2!=a1+a2) {cout<<"NO"<<endl;return 0;}
	flag=0;
	for (int i=1;i<=n;i++)
		if ((a[i]!=b) && (abs(a[i]-b)!=a1-b)) {flag=1;break;}
	if (flag) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}
