#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 400000
typedef long long ll;
using namespace std;
int n, ma, top;
char s[N], stack[N];
ll ans, tot, f[N][5];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		scanf("%s", s);
		int len=strlen(s), top=0;
		for (int j=0;j<len;j++)
			if (s[j]=='(') stack[++top]='(';
			else
				if (stack[top]=='(') top--;
				else stack[++top]=')';
		int a=0, b=0;
		for (int j=1;j<=top;j++)
			if (stack[j]==')') b++;else a++;
		if (!a && !b) tot++;
		if (a && b) continue;
		if (a) f[a][0]++;
		if (b) f[b][1]++;
		ma=max(ma,len);
	}
	ans=tot*tot;
	for (int i=1;i<=ma;i++)
		ans+=f[i][0]*f[i][1];
	cout<<ans<<endl;
	return 0;
}
