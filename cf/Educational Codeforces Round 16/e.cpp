#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define mo 65010000
using namespace std;
int n, flag[20000010], l[65010000];
long long f[20000010];
int main(){
	int x, y;
	cin>>n>>x>>y;
	memset(flag,0,sizeof(flag));
	int le=0, ri=1, v;
	l[1]=1;
	for (int i=2;i<=2*n;i++) f[i]=(long long)1000000000*100000000;
	f[1]=x;flag[1]=1;
	while (le!=ri){
		le=(le+1)%mo;
		v=l[le];
		flag[v]=0;
		if (v<n*2 && f[v]+x<f[v+1]){
			f[v+1]=f[v]+x;
			if (f[l[ri]]>f[v+1]){
				l[le]=v+1;
				le=(le+mo-1)%mo;
			}
			else
				if (!flag[v+1]) l[ri=(ri+1)%mo]=v+1;
			flag[v+1]=1;
		}
		if (v<=n && f[v*2]>f[v]+y){
			f[v*2]=f[v]+y;
			if (f[l[ri]]>f[v*2]){
				l[le]=v*2;
				le=(le+mo-1)%mo;
			}
			else
				if (!flag[v*2])l[ri=(ri+1)%mo]=v*2;
			flag[v*2]=1;
		}
		if (v>1 && f[v-1]>f[v]+x){
			f[v-1]=f[v]+x;
			if (f[l[ri]]>f[v-1]){
				l[le]=v-1;
				le=(le+mo-1)%mo;
			}
			else
				if (!flag[v-1])l[ri=(ri+1)%mo]=v-1;
			flag[v-1]=1;
		}
	}
	cout<<f[n]<<endl;
	return 0;
}
