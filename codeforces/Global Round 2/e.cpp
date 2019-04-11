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
typedef long long ll;
using namespace std;
int n, a[N], b[N], c[N];
ll ans;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void seek(int &j, int &o, int i){
	b[i]-=2;
	if (b[i]<0) return;
	while (j<i && !b[j]) j++;
	if (j<=i && b[j]){
		b[j]--, ans++;
		if (j==i) c[i]++;
	}
	else{
		if (b[o]) {b[o]--, ans++;if(o==i) c[i]++;return;}
		if (c[o]) {c[o]--, b[o]+=2;if (o==i) c[i]++;return;}
		while (o<i && !c[o]) o++;
		if (!c[o]) return;
		if (o==i) c[i]++; 
		c[o]--;b[o]+=2;
	}
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(), b[i]=a[i]%3, c[i]=a[i]/3, ans+=c[i];
	int i=n, j=1, o=1;
	for (;i && o<=i;i--)
		if (b[i]==1){
			if (c[i]) c[i]--, ans--, b[i]+=3;
			else continue;
			seek(j,o,i);
			seek(j,o,i);
		}
		else if (b[i]==2){
			seek(j,o,i);
		}
		else continue;
	j=n;
	for (i=n;i;i--){
		if (c[i]<2) continue;
		j=min(j,i);
		int tmp=0;
		while (j && tmp<3) tmp+=b[j--];
		if (tmp<3) break;
		c[i++]-=2;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
