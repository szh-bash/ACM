#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n, k, cnt, a[100];
int main(){
	cin>>n>>k;
	for (int i=2;i<=n;i++){
		while (n%i==0){
			a[++cnt]=i;
			n/=i;
		}
	}
	if (cnt<k) cout<<-1<<endl;
	else{
		for (int i=1;i<k;i++)
			cout<<a[i]<<' ';
		int j=1;
		for (int i=k;i<=cnt;i++)
			j=j*a[i];
		cout<<j<<endl;
	}
	return 0;
}
