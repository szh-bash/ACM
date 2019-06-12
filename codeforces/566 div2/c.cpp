#include <map>
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200000
#define M 2000000
typedef long long ll;
using namespace std;
struct njh{
	int t, total, st;
	char ch;
}l[N];
int n, ans, pre, suf, f[N], g[N];
char s[M], ss[M];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool cmp(njh a, njh b){
	if (a.t<b.t) return 1;
	if (a.t>b.t) return 0;
	return a.ch<b.ch;
}
int main(){
	n=read();
	int total=0;
	for (int i=1;i<=n;i++){
		scanf("%s", ss);
		int len=strlen(ss), tag;
		for (int j=0;j<len;j++)
			tag=(ss[j]=='a' || ss[j]=='e' || ss[j]=='i' || ss[j]=='o' || ss[j]=='u'),
			(tag?l[i].ch=ss[j]:0),
			l[i].t+=tag;
		l[i].st=total;
		strcpy(s+total,ss);
		total+=len;
		s[total++]='\0';
	}
	sort(l+1,l+1+n,cmp);
	for (int i=1;i<=n;){
		int j=i;
		for (;j<=n && l[j].t==l[i].t;j++);
		if (l[i].t==0){
			for (int k=i;k<j;k++) f[++f[0]]=l[k].st;
			f[0]-=(j-i)&1;
			pre+=(j-i)/2;
			i=j;
			continue;
		}
		int tot=1, sum=0;
		for (int k=i+1;k<j;k++){
			if (l[k].ch!=l[k-1].ch){
				if (tot&1) f[++f[0]]=l[k-1].st;
				suf+=tot/2,
				sum+=tot&1,
				tot=1;
			}
			else{
				tot++;
				if (!(tot&1)) g[++g[0]]=l[k-1].st, g[++g[0]]=l[k].st;
			}
		}
		if (tot&1) f[++f[0]]=l[j-1].st;
		suf+=tot/2;
		sum+=tot&1;
		pre+=sum/2;
		f[0]-=sum&1;
		i=j;
	}
	if (pre>=suf){
		ans=suf;
		cout<<ans<<endl;
		for (int i=1;i<=suf;i++)
			printf("%s %s\n%s %s\n", s+f[i*2-1], s+g[i*2-1], s+f[i*2], s+g[i*2]);
	}
	else{
		ans=(pre+suf)/2;
		cout<<ans<<endl;
		for (int i=1;i<=pre;i++)
			printf("%s %s\n%s %s\n", s+f[i*2-1], s+g[i*2-1], s+f[i*2], s+g[i*2]);
		for (int i=pre+1;i<suf;i+=2)
			printf("%s %s\n%s %s\n", s+g[i*2-1], s+g[i*2+1], s+g[i*2], s+g[i*2+2]);
	}
	return 0;
}
