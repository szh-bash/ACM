#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, w, a[101000], c[101000];
bool cmp (int a, int b){return a>b;}
int main(){
	cin>>n>>w;
	for (int i=1;i<=n;i++) scanf("%d", &a[i]);
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j+=j&(-j)) c[j]=max(c[j],a[i]);
	for (int i=1;i<=n;i++){
		long long tmp=-1;
		for (int j=1;j<=n;j+=i){
			int k=min(n,j+i-1), v=0;
			while (k>=j){
				if (k-(k&(-k))>=j-1) {v=max(v,c[k]);k-=k&(-k);}
				else {v=max(v,a[k]);k--;}
			}
			tmp=tmp+v+1;
		}
		if (tmp<=w) {cout<<i<<endl;break;}
	}
}
