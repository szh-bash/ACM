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
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, tag[100], g[1005][1005], q[1005], w[1005];
ll ans;
short a[1005][1005];
char s[1005];
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
	freopen("j.in","r",stdin);
	freopen("j.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++){
		scanf("%s", s+1);
		for (int j=1;j<=52;j++) tag[j]=0;
		for (int j=1;j<=m;j++){
			if (s[j]>='a') a[i][j]=s[j]-'a'+27;
			else a[i][j]=s[j]-'A'+1;
			g[i][j]=max(g[i][j-1],tag[a[i][j]]);
			tag[a[i][j]]=j;
		}
	}
/*	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) cout<<g[i][j]<<' ';
		cout<<endl;
	}*/
	for (int i=1;i<=52;i++) tag[i]=0;
	for (int i=1;i<=n;i++){
		int p=1 , head=1, tail=0;
		q[0]=i+1;
		for (int j=1;j<=m;j++){
			int le=g[i][j];
			p=head;
			//cout<<tail<<' '<<q[tail]<<' '<<w[tail]<<endl;
			for (int k=i;k>=0;k--){
			//	cout<<i<<' '<<j<<' '<<k<<endl;
				if (tag[a[k][j]] || !k){
					while (tail>head && q[tail]<k+1 && q[tail-1]<k+1) tail--;
					if (!tail || q[tail]>k+1){
						q[++tail]=++k;
						w[tail]=j;
					}
					else q[tail]=++k;
					while (k<=i) tag[a[k++][j]]=0;
					break;
				}
				else{
				//	cout<<p<<' '<<tail<<' '<<q[p]<<' '<<k<<' '<<w[p]<<' '<<le<<endl;
					tag[a[k][j]]=1;
					le=max(le,g[k][j]);
					while (p<=tail && q[p]>k) p++;
					if (p>tail) ans++;
					else ans+=j-max(le+1,w[p])+1;
				//	cout<<i<<' '<<j<<' '<<k<<' '<<p<<' '<<q[p]<<' '<<w[p]<<' '<<ans<<endl;
				}
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}
