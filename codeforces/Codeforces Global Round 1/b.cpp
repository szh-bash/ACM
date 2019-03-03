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
#define N 200000
typedef long long ll;
using namespace std;
int b[N], s[N], n, m, k;
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
	n=read();m=read();k=read();
	for (int i=1;i<=n;i++){
		b[i]=read();
		s[i]=b[i]-b[i-1]-1;
	}
	sort(s+2,s+1+n);
	int ans=b[n]-b[1]+1;
	for (int i=n;i>1 && n-i+1<k;i--)
		ans-=s[i];
	cout<<ans<<endl;
	return 0;
}
