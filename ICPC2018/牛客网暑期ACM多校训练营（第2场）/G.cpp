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
#define N 500005
#define M 10000000
#define LIMIT 1000000000
#define BLOCK (LIMIT/M)
typedef unsigned long long ull;
//typedef __int128 ull; 
typedef long long ll;
using namespace std;
int n, l[M+5], r[M+5], check, pre[M+5], nex[M+5];
ull T, sum[N], sum2[N], s[N], x[N], a[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll work(int dis, int i){
	int left, right;
	int c=x[i]+dis, n=c/BLOCK;
	if (n>M) n=M;
	int le=l[n], ri=r[n]+1;
	if (!r[n]) right=pre[n];
	else{
		while (le<ri-1){
			int mid=le+ri>>1;
			if (x[mid]<=c) le=mid;
			else ri=mid;
		}
		right=le;
	}
	c=x[i]-dis,n=c/BLOCK;
	if (n<0) n=0;
	le=l[n]-1, ri=r[n];
//	cout<<le<<' '<<ri<<' '<<x[1]<<' '<<c<<endl;
	if (!r[n]) left=nex[n];
	else{
		while (le<ri-1){
			int mid=le+ri>>1;
		//	cout<<le<<' '<<ri<<' '<<x[mid]<<' ';
			if ((ll)x[mid]<c) le=mid;
			else ri=mid;
		//	cout<<le<<' '<<ri<<endl;
		}
		left=ri;
	}
//	cout<<left<<' '<<i<<' '<<right<<endl;
	//cacl
	ull p=0;
	ll q=s[right]-s[left-1];
	p+=sum[right]-sum[i]-(ull)2*x[i]*(s[right]-s[i]);
	p+=sum2[left]-sum2[i]-(ull)2*((ull)LIMIT-x[i])*(s[i-1]-s[left-1]);
//	cout<<p<<endl;
	if (p<=T) { check=0; return q;}
	
	if (x[right]-x[i]>x[i]-x[left]){
		q-=a[right];
		p-=sum[right]-sum[right-1]-(ull)2*x[i]*a[right];
		if (p+(ull)2*(x[right]-x[i])>T) { check=-1; return 0;}
		q+=(T-p)/((ull)2*(x[right]-x[i]));
	}
	else
		if (x[right]-x[i]<x[i]-x[left]){
			q-=a[left];
			p-=sum2[left]-sum2[left+1]-(ull)2*((ull)LIMIT-x[i])*a[left];
			if (p+(ull)2*(x[i]-x[left])>T) { check =-1; return 0;}
			q+=(T-p)/((ull)2*(x[i]-x[left]));
		}
		else{
			q-=a[left]+a[right];
			p-=sum[right]-sum[right-1]-(ull)2*x[i]*a[right];
			p-=sum2[left]-sum2[left+1]-(ull)2*((ull)LIMIT-x[i])*a[left];
			if (p+(ull)2*(x[i]-x[left])>T) { check =-1; return 0;}
			q+=(T-p)/((ull)2*(x[i]-x[left]));
		}
	check=1;
	return q;
}
int main(){
//	cout<<BLOCK<<endl;
	n=read();
	ll tmp;
	cin>>tmp;T=tmp;
	for (int i=0;i<=M;i++) l[i]=n+1, r[i]=0;
	for (int i=1;i<=n;i++)
		x[i]=read(),
		l[x[i]/BLOCK]=min(l[x[i]/BLOCK],i),
		r[x[i]/BLOCK]=max(r[x[i]/BLOCK],i);
	for (int i=1;i<=n;i++)
		a[i]=read(),
		s[i]=s[i-1]+a[i],
		sum[i]=sum[i-1]+a[i]*x[i]*2;
	for (int i=n;i;i--)
		sum2[i]=sum2[i+1]+a[i]*((ull)LIMIT-x[i])*2;
		
	for (int i=0;i<=M;i++)
		pre[i]=r[i]?r[i]:pre[i-1];
	for (int i=M;i>=0;i--)
		nex[i]=r[i]?l[i]:nex[i+1];
	ll ans=0;
	for (int i=1;i<=n;i++){
//		cout<<"lykkk: "<<i<<endl;
		int le=0, ri=max(LIMIT-x[i],x[i])+1, mid;
//		cout<<le<<' '<<ri<<endl;
		ll v=0;
		while (le<ri-1){
//			cout<<"lyk "<<ri<<endl;
			mid=le+ri>>1;
			v=work(mid, i);
//			cout<<le<<' '<<ri<<' '<<mid<<' '<<check<<' '<<v<<endl;
			if (!check) le=mid;
			else
				if (check<0) ri=mid;
				else break;
		}
		ans=max(ans,v);
	}
	cout<<ans<<endl;
    return 0;
}
