#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 4000000
typedef long long ll;
using namespace std;
int n, m, cnt, x, ans[N];
char s[N*10];
struct qlz{
	int x, y, type, n;
}l[N], b[N];
int read(){
	int p=0;
	while (s[x]<'0' || s[x]>'9') x++;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p;
}
void add(int x ,int y, int type, int num){
	l[++cnt].x=x;l[cnt].y=y;l[cnt].type=type;l[cnt].n=num;
}
bool cmp(qlz a, qlz b){
	if (a.x<b.x) return 1;
	if (a.x>b.x) return 0;
	if (!a.type && b.type) return 1;
	return 0;
}
void cdq(int le, int ri){
	if (le==ri) return;
	int mid=le+ri>>1;
	cdq(le,mid);
	cdq(mid+1,ri);
	int j=le, q=le, tot=0;
	for (int i=mid+1;i<=ri;i++){
		for (;j<=mid && l[j].y<=l[i].y;j++){
			if ((l[j].y==l[i].y) && l[j].type && !l[i].type) break;
			if (!l[j].type) tot++;
			b[q++]=l[j];
		}
		b[q++]=l[i];
		if (l[i].type) ans[l[i].n]+=l[i].type*tot;
	}
	while (j<=mid) b[q++]=l[j++];
	for (int i=le;i<=ri;i++) l[i]=b[i];
}
int main(){
	cin>>n>>m;
	fread(s,1,(n+m*2)*18,stdin);
	for (int i=1;i<=n;i++){
		int x=read(), y=read();
		add(x,y,0,0);
	}
	for (int i=1;i<=m;i++){
		int x1=read(), y1=read(), x2=read(), y2=read();
		add(x2,y2,1,i);
		add(x2,y1-1,-1,i);
		add(x1-1,y2,-1,i);
		add(x1-1,y1-1,1,i);
	}
	sort(l+1,l+1+cnt,cmp);
	cdq(1,cnt);
	for (int i=1;i<=m;i++) printf("%d\n", ans[i]);
	return 0;
}
