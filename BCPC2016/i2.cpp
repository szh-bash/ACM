#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 2600010
#define m 155
using namespace std;
int n, l[N], k, r[N], f[N], y[N], wv[m], b[N], sa[N];
char ch;
char a[25000010];
bool cmp(int a, int b){return f[a]>f[b];}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T;
	cin>>T;
	while (T--){
		cin>>k>>n;
		int ls=-1, ma, j=1;
		for (int i=1;i<=n;i++){
			while(ch<33 || ch>122) ch=getchar();
			l[i]=ls+1;
			for (;ch>=33 && ch<=122;ch=getchar())
				a[++ls]=ch;
			r[i]=ls;
			f[i]=r[i]-l[i]+1;
			b[i]=i;
		}
		sort(b+1,b+1+n,cmp);
		for (int i=1;i<=n;i++) y[i]=b[i];
		ma=f[b[1]];
		while (ma){
			//cout<<ma<<endl;
			memset(wv,0,sizeof(wv));
			while (j<n && f[b[j+1]]==ma) j++;
			for (int i=1;i<=j;i++) ++wv[a[r[y[i]]]];
			for (int i=133;i;i--) wv[i]+=wv[i+1];
			for (int i=j;i;i--)
				sa[wv[a[r[y[i]]--]]--]=y[i];
			for (int i=1;i<=j;i++) y[i]=sa[i];
			ma--;
		}
		for (int i=l[y[n-k+1]];i<l[y[n-k+1]]+f[y[n-k+1]];i++)
			printf("%c", a[i]);
		if (T)  printf("\n");
	}
	return 0;
}
