#include <map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, nex[200], nu[200], tag[200];
map <string, int> mp;
char s0[100], s1[100];
int check(int u, int tx){
	tag[u]=1;
	if (u==tx) return 1;
	int flag=0;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (!tag[v]) flag|=check(v,tx);
	}
	return flag;
}
int main(){
	while (~scanf("%d", &n)){
		int flag=1, ct=n*2, cnt=0;
		mp.clear();
		for (int i=1;i<=n*2;i++) nex[i]=0;
		for (int i=1;i<=n;i++){
			scanf("%s%s", s0, s1);
			if (!flag) continue;
			if (!mp[s0]) mp[s0]=++cnt;
			if (!mp[s1]) mp[s1]=++cnt;
			int u=mp[s0], v=mp[s1];
			for (int j=1;j<=n*2;j++) tag[j]=0;
			if (check(v,u)){
				cout<<s0<<' '<<s1<<endl;
				flag=0;
				continue;
			}
			nex[++ct]=nex[u];nex[u]=ct;nu[ct]=v;
		}
		if (flag) cout<<0<<endl;
	}
	return 0;
}
