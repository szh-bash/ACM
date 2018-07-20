#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200000
#define INF 1000000500
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, f[N+5], z[N+5];
ull s1[N], s2[N], s3[N], ans;
char s[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void calc(ull K, int x){
	if (K==0) return;
	ull L=(x-f[x])>>1, R=(n/2)-L-K;
	//cout<<L<<' '<<K<<' '<<R<<endl;
	ull p=L*R, q=L+R, c=(n-1)-L-R+2;
	ull k=(K-1)/2+1;
	ans+=(-2*s3[k]+(c-2*q)*s2[k]+(q*c-2*p)*s1[k]+p*c*k)/2;
	//cout<<ans<<endl;
}
int main(){
	for (ull i=1;i<=N/2;i++)
		s1[i]=s1[i-1]+i,
		s2[i]=s2[i-1]+i*i,
		s3[i]=s3[i-1]+i*i*i;
	for (int T=read(), j=1;T;T--, j++){
		ans=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		for (int a=n;a;a--) z[a*2]=s[a];
		n=(n<<1)+1;
		for (int a=1;a<=n;a+=2) z[a]=1;
		f[1]=1;
	    int id, mx=0;
	    for (int i=1;i<=n;i++){
	        if (i<mx) f[i]=min(f[2*id-i], mx-i); else f[i]=1;
	        while (z[i-f[i]] == z[i+f[i]]) f[i]++;
	        if (mx<i+f[i])
	            id=i,
	            mx=i+f[i];
	        calc(f[i]-1,i);
	    }
		//for (int a=1;a<=n;a++)
		//	cout<<f[a]<<' ';cout<<endl;
		printf("Case #%d: %lld\n", j, ans);
	}
	return 0;
}
