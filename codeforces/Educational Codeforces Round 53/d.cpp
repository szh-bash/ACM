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
#define N 500000
#define lowbit(x) (x&(-x))
typedef unsigned long long ll;
using namespace std;
int n, m, a[N], cc[N];
ll T, ans;
ll c[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void upd(int x, int y){
	for (int i=x;i<=m;i+=lowbit(i)) c[i]+=y;
}
void upd2(int x, int y){
	for (int i=x;i<=m;i+=lowbit(i)) cc[i]+=y;
}
ll sum(int x){
	ll p=0;
	for (int i=x;i;i-=lowbit(i)) p+=c[i];
	return p;
}
int sum2(int x){
	ll p=0;
	for (int i=x;i;i-=lowbit(i)) p+=cc[i];
	return p;
}
int main(){
	n=read();cin>>T;
	m=n*2;
	for (int i=1;i<=n;i++)
		a[i]=a[i+n]=read(),
		upd(i,a[i]),
		upd(i+n, a[i+n]),
		upd2(i,1),
		upd2(i+n,1);
	int j=1, tot=n;
	while (tot){
		ll fs=sum(j+n-1)-sum(j-1);
		//cout<<T<<' '<<fs<<' '<<ans<<' '<<j<<' '<<a[1]<<' '<<a[2]<<' '<<a[3]<<endl;
		ans+=T/fs*tot;
		T%=fs;
		int le=j-1, ri=j+n-1;
		while (le<ri-1){
			int mid=le+ri>>1;
			if (sum(mid)-sum(j-1)<=T) le=mid;
			else ri=mid;
		}
		//cout<<j<<' '<<le<<' '<<ri<<endl;
		T-=sum(ri-1)-sum(j-1);
		ans+=sum2(ri-1)-sum2(j-1);
		j=ri;
		if (j>n) j-=n;
		tot--;
		upd(j,-a[j]);
		upd(j+n,-a[j+n]);
		upd2(j,-1);
		upd2(j+n,-1);
		a[j]=0;
		a[j+n]=0;
	}
	cout<<ans<<endl;
	return 0;
}
