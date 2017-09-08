#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200000
typedef long long ll;
using namespace std;
struct qlz{
	int a, b, n;
}l[N], b[N];
int n, K, x, c[N];
int ans;
char s[6*N+100];
int read(){
	int p=0;
	while (s[x]<'0' || s[x]>'9') x++;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p;
}
bool cmp(qlz a, qlz b){return a.a<b.a;}
void cdq(int le, int ri){
	if (le==ri) return;
	int mid=le+ri>>1;
	cdq(le,mid);
	cdq(mid+1,ri);
	int j=le, q=le;
	for (int i=mid+1;i<=ri;i++){
		for (;j<=mid && l[j].b>l[i].b;j++){
			for (int k=l[j].n;k<=n;k+=k&(-k)) c[k]++;
			b[q++]=l[j];
		}
		b[q++]=l[i];
		for (int k=l[i].n-K-1;k>0;k-=k&(-k)) ans+=c[k];
		if (l[i].n+K<n){
			for (int k=n;k;k-=k&(-k)) ans+=c[k];
			for (int k=l[i].n+K;k;k-=k&(-k)) ans-=c[k];
		}
	}
	for (int i=le;i<j;i++)
		for (int k=l[i].n;k<=n;k+=k&(-k)) c[k]--;
	while (j<=mid) b[q++]=l[j++];
	for (int i=le;i<=ri;i++) l[i]=b[i];
}
int main(){
	cin>>n>>K;
	fread(s,1,n*12,stdin);
	for (int i=1;i<=n;i++) l[i].n=i;
	for (int i=1;i<=n;i++) l[read()].a=i;
	for (int i=1;i<=n;i++) l[read()].b=i;
	sort(l+1,l+1+n,cmp);
	cdq(1,n);
	cout<<ans<<endl;
	return 0;
}
