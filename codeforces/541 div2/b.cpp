#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int n, a[20000], b[20000], ans;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	int x=-1;
	a[0]=b[0]=-1;
	for (int i=1;i<=n;i++){
		a[i]=read(), b[i]=read();
		if (min(a[i],b[i])==x) continue;
		x=min(a[i],b[i]);
		if (a[i-1]<b[i-1]){
			if (a[i]>=b[i-1]) ans+=min(a[i]-b[i-1]+1,b[i]-b[i-1]+1);
			else continue;
		}
		else if (a[i-1]>b[i-1]){
			//cout<<ans<<endl;
			if (a[i-1]<=b[i]) ans+=min(b[i]-a[i-1]+1,a[i]-a[i-1]+1);
			else continue; 
			//cout<<"lyk "<<min(b[i]-a[i-1]+1,a[i]-a[i-1]+1)<<endl;
			//cout<<ans<<endl;
		}
		else{
			ans+=x-a[i-1];
		}
		//cout<<i<<' '<<ans<<' '<<x<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
