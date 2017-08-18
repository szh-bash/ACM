#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, q, p, c[301000], next[701000], nu[701000], a[301000], cnt, ct1;
int main(){
	cin>>n>>q;
	ct1=n;
	for (int i=1;i<=q;i++){
		int x, y, ans=0;
		scanf("%d%d", &x, &y);
		if (x==1){
			next[++ct1]=next[y];next[y]=ct1;nu[ct1]=++cnt;
			a[cnt]=1;
			for (int j=cnt;j<=q;j+=j&(-j)) c[j]++;
		}
		if (x==2){
			int j=next[y];
			while (j){
				int v=nu[j];
				if (v<=p) break;
				a[v]=0;
				for (int w=v;w<=q;w+=w&(-w)) c[w]--;
				j=next[j];
			}
			next[y]=0;
		}
		if (x==3 && y>p){
			for (int k=p+1;k<=y;k++)
				if (a[k]){
					for (int j=k;j<=q;j+=j&(-j)) c[j]--;
					a[k]=0;
				}
			p=y;
		}
		for (int j=q;j;j-=j&(-j)) ans+=c[j];
		cout<<ans<<endl;
	}
	return 0;
}
