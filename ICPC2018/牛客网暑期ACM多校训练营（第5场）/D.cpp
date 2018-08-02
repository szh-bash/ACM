#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1000000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int c[N], w[N], n, m, a[N], b[N];
ll ans;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	n=read();
	m=n/2;
	for (int i=1;i<=m;i++) a[i]=2*i-1;
	for (int i=1;i<=m;i++){
		b[i]=read();
		for (int k=b[i];k<=n;k+=k&(-k))
			w[k]++;
	}
	for (int i=1, j=1;i<=m || j<=m;){
		int v1=0, v2=0;
		ans+=i+j-2;
		if (j>m){
			for (int k=a[i];k;k-=k&(-k)) ans-=c[k];
			for (int k=a[i];k<=n;k+=k&(-k)) c[k]++;
		//	cout<<a[i]<<' ';
			i++;
			continue;
		}
		if (i>m){
			for (int k=b[j];k;k-=k&(-k)) ans-=c[k];
			for (int k=b[j];k<=n;k+=k&(-k)) c[k]++;
			//cout<<b[j]<<' ';
			j++;
			continue;
		}
		for (int k=a[i];k;k-=k&(-k)) v1+=w[k];
		if (a[i]<b[j]) v2=(b[j]-a[i]+1)/2;
		if (v1<=v2){
			for (int k=a[i];k;k-=k&(-k)) ans-=c[k];
			for (int k=a[i];k<=n;k+=k&(-k)) c[k]++;
			//cout<<a[i]<<' ';
			i++;
		}
		else{
			for (int k=b[j];k;k-=k&(-k)) ans-=c[k];
			for (int k=b[j];k<=n;k+=k&(-k)) c[k]++;
			for (int k=b[j];k<=n;k+=k&(-k)) w[k]--;
			//cout<<b[j]<<' ';
			j++;
		}
	}
	//cout<<endl;
	cout<<ans<<endl;
    return 0;
}
