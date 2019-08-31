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
#include <tr1/unordered_map>
#define N 2000000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int ls, lc;
int p[N], q[N];
char s[N], sc[N];
int pre[N], suf[N];
void self_kmp(int p[], char s[]){
	int ls=strlen(s+1);
	p[1]=0;
	for (int i=2, j=0;i<=ls;i++){
		while (j && s[j+1]!=s[i]) j=p[j];
		if (s[j+1]==s[i]) ++j;
		p[i]=j;
	}
}
void calc(int f[]){
	self_kmp(q, sc);
//	cout<<sc+1<<endl;
//	cout<<q[0]<<q[1]<<q[2]<<endl;
	for (int i=1, j=0;i<=ls;i++){
		while (j && sc[j+1]!=s[i]) j=q[j];
		if (sc[j+1]==s[i]) ++j;
		f[j]=i;
//		cout<<i<<' '<<j<<' '<<f[j]<<endl;
	}
//	cout<<f[0]<<' '<<f[1]<<' '<<f[2]<<endl;
	for (int j=lc;j;j--){
//		cout<<j<<' '<<f[j]<<' '<<q[j]<<' '<<f[q[j]]<<' '<<f[j-1]<<endl;
		f[q[j]]=max(f[q[j]], f[j]),
		f[j-1]=max(f[j-1],f[j]-1);
	}
}
void reverse(){
	for (int i=1;i<=ls/2;i++) swap(s[i], s[ls-i+1]);
	for (int i=1;i<=lc/2;i++) swap(sc[i], sc[lc-i+1]);
//	cout<<s+1<<endl<<sc+1<<endl;
}
bool cmp(int a, int b){return a<b;}
int main(){
	scanf("%s%s", s+1, sc+1);
	ls=strlen(s+1), lc=strlen(sc+1);
	if (lc>ls){
		puts("-1");
		return 0;
	}
//	cout<<"start"<<endl;
	
	for (int j=ls+1;j<=ls*2;j++) s[j]=s[j-ls];
	ls<<=1;
	self_kmp(q, sc);
	for (int i=1, j=0;i<=ls;i++){
		while (j && sc[j+1]!=s[i]) j=q[j];
		if (sc[j+1]==s[i]) ++j;
		if (j==lc){
			printf("%d\n", ls>>1);
			return 0;
		}
	}
	
//	ls>>=1;
//	s[ls+1]='\0';
//	cout<<"pre: "<<pre[0]<<' '<<pre[1]<<' '<<pre[2]<<endl;
	reverse();
	calc(suf);
	for (int i=1;i<lc;i++)
		suf_tmp[i]=ls-suf[lc-i+1]+1;
	for (int i=1;i<=lc;i++)
		suf[i]=suf_tmp[i],
		num[i]=i;
	sort(num+1, num+1+cmp);
	reverse();
	self_kmp(q, sc);
	for (int i=1, j=0;i<=ls;i++){
		while ( 
	}
//	cout<<"suf: "<<suf[0]<<' '<<suf[1]<<' '<<suf[2]<<endl;

	int ans=-1;
	for (int i=1;i<lc;i++){
		ans=max(ans, pre[i]-(ls-suf[lc-i]+1)+1);
		if (pre[i]-(ls-suf[lc-i]+1)+1<lc)
			ans=max(ans, ls+pre[i]-(ls-suf[lc-i]+1)+1);
//		cout<<i<<' '<<pre[i]<<' '<<ls-suf[lc-i]+1<<endl;
	}
	if (ans<lc) ans=-1;
	printf("%d\n", ans);
	
    return 0;
}
