#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 200100
#define M 125
#define la 97
#define lz 122
using namespace std;
char s[N], ans[N];
int cnt, len, top, pos, pre[N], stack[N], f[N], v[N][M], fa[N], nex[N][30];
void solve(int l, int r){
	if (l>r) return;
	while (v[f[r]][s[l]]>r)
		v[f[r]][s[l]]=pre[v[f[r]][s[l]]];
	ans[l]='(';
	ans[v[f[r]][s[l]]]=')';
	solve(v[f[r]][s[l]]+1,r);
	solve(l+1,v[f[r]][s[l]]-1);
}
void add(int x){
	if (!nex[pos][s[x]-'a'])
		nex[pos][s[x]-'a']=++cnt, fa[cnt]=pos, pos=cnt;
	else
		pos=nex[pos][s[x]-'a'];
	stack[++top]=x;
	f[x]=pos;
}
void del(int x){
	pos=fa[pos];
	top--;
	f[x]=pos;
}
int main(){
	scanf("%s", s);
	len=strlen(s);
	for (int i=0;i<len;i++){
		if (!top || s[stack[top]]!=s[i])
			add(i); 
		else
			del(i);
	}
	if (!top){
		for (int i=0;i<len;i++)
			pre[i]=v[f[i]][s[i]],
			v[f[i]][s[i]]=i;
		solve(0,len-1);
		for (int i=0;i<len;i++)
			printf("%c", ans[i]);
	}
	else
		cout<<-1<<endl;
	return 0;
}
