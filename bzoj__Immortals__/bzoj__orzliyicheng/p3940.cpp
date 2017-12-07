#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
char ss[110000], s[110000];
int n, cnt, next[110000], v[110000], hd[110000];
void build(){
	int ll=0, rr=1;
	l[1]=1;
	while (ll<rr)
		for (int j=next[l[++ll]];j;j=hd[j]) l[++rr]=j;
	for (int i=1;i<=
}
int main(){
	scanf("%s", ss);
	cin>>n;
	cnt=1;
	for (int i=1;i<=n;i++){
		scanf("%s", s);
		int t=1;
		for (int j=0;j<strlen(s);j++){
			int k=next[j];
			while (k && v[k]!=s[j])	k=hd[k];
			if (!k){
				next[++cnt]=next[j];
				hd[cnt]=next[j];
				next[j]=cnt;
				v[cnt]=s[j];
				k=cnt;
			}
			t=k;
		}
	}
	build();
	return 0;
}
