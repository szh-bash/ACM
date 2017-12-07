#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, hd[200100], next[200100], p[100100], f[100100], cnt, he[100100],l[100100], fa[100100], fail[100100];
char va[200100], ans[100100];
char s[100100], ss[100100];
int main(){
	scanf("%s", ss);
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%s", s);
		int j=0, k=0, ls=strlen(s);
		while (k<ls){
			int h=hd[j], flag=0;
			while (h){
				if (va[h]==s[k]) {flag=1;break;}
				h=next[h];
			}
			if (flag)	j=h;
			else{
				next[++cnt]=hd[j];
				hd[j]=cnt;
				va[cnt]=s[k];
				fa[cnt]=j;
				he[cnt]=he[j]+1;
				j=cnt;
			}
			++k;
		}
		f[cnt]=1;
	}
	int r=0;
	for (int i=0;i<=r;i++){
		int j=hd[l[i]];
		while (j){
			l[++r]=j;
			j=next[j];
		}
	}
	int ls=strlen(ss);
	for (int i=1;i<=r;i++){
		int v=l[i];
		int j=fail[fa[v]], flag=0;
		while (j){
			int k=hd[j];
			while (k){
				if (va[k]==va[v]){flag=1;break;}
				k=next[k];
			}
			if (flag==0) j=fail[j];
			else{
				fail[v]=k;
				break;
			}
		}
		if (!flag && fa[v]){
			int k=hd[j];
			while (k){
				if (va[k]==va[v]){flag=1;break;}
				k=next[k];
			}
			if (flag) fail[v]=k;
		}
	}
	cnt=0;
	int j=0;
	for (int i=0;i<ls;i++){
		ans[++cnt]=ss[i];
		int flag=0, k=0;
		while (j){
			k=hd[j];
			while (k){
				if (va[k]==ss[i]){flag=1;break;}
				k=next[k];
			}
			if (!flag) j=fail[j];
				else break;
		}
		if (!flag){
			k=hd[j];
			while (k){
				if (va[k]==ss[i]){flag=1;break;}
				k=next[k];
			}
		}
		if (flag){
			if (f[k]){
				cnt-=he[k];
				j=p[cnt];
			}
			else j=p[cnt]=k;
		}
		else j=p[cnt]=0;
	}
	for (int i=1;i<=cnt;i++) printf("%c", ans[i]);cout<<endl;
	return 0;
}
