#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a[210000], b[210000], c[210000], f[210000][60], k[60];
long long sum;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d", &b[i]);
	for (int i=1;i<=n;i++) scanf("%d", &c[i]), sum=sum+b[i]+c[i];
	if (sum % (2*n)) {cout<<-1<<endl;return 0;}
	sum/=2*n;
	for (int i=1;i<=n;i++){
		if (sum>(b[i]+c[i]) || (b[i]+c[i]-sum)%n){
			cout<<-1<<endl;
			return 0;
		}
		a[i]=(b[i]+c[i]-sum)/n;
	}
	for (int i=1;i<=n;i++){
		int x=a[i];
		while (x){
			f[i][++f[i][0]]=x%2;
			k[f[i][0]]+=f[i][f[i][0]];
			x/=2;
		}
	}
	for (int i=1;i<=n;i++){
		int t=0;
		for (int j=1;j<=f[i][0];j++){
			if (f[i][j]) t+=k[j];
			if ((t%2)!=b[i]%2){
				cout<<-1<<endl;
				return 0;
			}
			t/=2;
			b[i]/=2;
		}
		if (b[i]!=t) {cout<<-1<<endl;return 0;}
		t=0;
		for (int j=1;j<=55;j++){
			if (f[i][j]) t+=n;
			else t+=k[j];
			if ((t%2)!=c[i]%2){
				cout<<-1<<endl;
				return 0;
			}
			t/=2;
			c[i]/=2;
		}
	}
	for (int i=1;i<=n;i++) printf("%d ", a[i]); 
	return 0;
}
