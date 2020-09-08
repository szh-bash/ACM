#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll f(int n){
	ll res=0;
	for (int i=1;i<n;i++)
		for (int j=1;j*i<n;j++)
			for (int k=1;k*(i+1)+j*i<n;k++)
				if ((n-j*i-k*(i+1))%(i+2)==0)
					res++;
	return res;
}
#define N 100005
ll ans[N];
ll g(int n){
	ll res=0;
	for (int i=1;i<n;i++)
		for (int j=(n+2)/(i+2)+1;j*i<=n-3;j++){
			int u=n-i*j, v;
			if (u>=j) v=(u-j+1);else v=1;
			u-=v*2;
			res+=(u-1)/2+1;
		}
	return res;
}
void solve(int T){
	int l=read(), r=read();
	printf("Case #%d: %lld\n", T, ans[r]-ans[l-1]);
}
int main(){
	int p=1;
	for (int i=1;i<=1000;i++) p&=f(i)==g(i);
	cout<<p<<endl;
	for (int i=1;i<=10000;i++) ans[i]=ans[i-1]+g(i+90000); 
	for (int i=1;i<=10;i++) cout<<i<<' '<<g(i)<<endl; 
	for (int _=read(), o=1;o<=_;o++) solve(o);
    return 0;
}
