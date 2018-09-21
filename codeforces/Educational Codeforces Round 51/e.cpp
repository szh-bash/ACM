#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define num(x) ((x)>='0' && (x)<='9')
#define N 2000000
#define mo 998244353
#define seed 233
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
using namespace std::tr1;
unordered_map <int, int> mp;
ull hsb[N], hs[N], inv[N];
int f[N], g[N], len, la, c[N], flag;
char a[N], b[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (!num(ch)) 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (num(ch)) p=p*10+ch-'0', ch=getchar(); 
	return p*q;
}
void sub(){
	flag=1;
	for (int i=0;i<len;i++) if (b[i]!='0') {flag=0;break;}
	if (flag) return;
	for (int i=0;i<len;i++) c[i]=b[len-i-1]-'0';
	c[0]--;
	for (int i=0;i<len;i++){
		if (c[i]>=0) break;
		c[i]+=10;
		c[i+1]--;
	}
	for (int i=0;i<len;i++) b[i]=c[len-i-1]+'0';
	cout<<b<<endl;
}
bool check(int x){
	x-=len-1;
	int le=-1, ri=len;
	while (le<ri-1){
		int mid=le+ri>>1;
		if ((hs[x+mid]-hs[x-1]*inv[mid+1])==hsb[mid+1]) le=mid;else ri=mid;
	}
	//if (x==1) cout<<ri<<endl;
	if (ri==len || a[x+ri]<=b[ri+1]) return 0;
	return 1;
}
void add(int &a, int b){
	a+=b;
	if (a>=mo) a-=mo;
}
void dec(int &a, int b){
	a-=b;
	if (a<0) a+=mo;
}
int calc(){
	for (int i=0;i<len;i++) c[i]=b[len-i-1]-'0';
	while (len>1 && !c[len-1]) len--;
	for (int i=0;i<len;i++) b[i+1]=c[len-i-1]+'0';
	for (int i=1;i<=len;i++) hsb[i]=hsb[i-1]*seed+b[i]-'0';
	g[0]=f[0]=1;
	for (int i=1;i<=la;i++){ 
		//cout<<i-1<<' '<<f[i-1]<<' '<<g[i-1]<<endl;
		f[i]=g[i-1];
		add(g[i],g[i-1]);
		if (i>=len)
			if (check(i) && a[i-len+1]!='0') dec(f[i],f[i-len]);
		add(g[i],f[i]);
		if (a[i]=='0') dec(g[i],f[i-1]);
		if (i>=len && a[i-len+1]!='0') dec(g[i],f[i-len]);
		//cout<<i<<' '<<f[i]<<' '<<g[i]<<endl;
	}
	//cout<<check(2)<<endl;
	return f[la];
}
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int main(){
	scanf("%s", a+1);
	la=strlen(a+1);
/*	for (int i=0;i<la;i++) c[i]=a[la-i-1]-'0';
	int ff=0;
	while (la>1 && !c[la-1]) la--, ff=1;
	for (int i=0;i<la;i++) a[i+1]=c[la-i-1];*/
	for (int i=1;i<=la;i++) hs[i]=hs[i-1]*seed+a[i]-'0';
//	int k=power(seed,mo-2);
	inv[0]=1;
	for (int i=1;i<=la;i++) inv[i]=inv[i-1]*seed;
	int ans=0;
	
	scanf("%s", b);
	len=strlen(b);
	sub();
	if (!flag) dec(ans,calc());
	cout<<ans<<' '<<flag<<endl;
	scanf("%s", b);
	len=strlen(b);
	add(ans,calc());
	ans=(ans%mo+mo)%mo;
	cout<<ans<<endl;
	return 0;
}
