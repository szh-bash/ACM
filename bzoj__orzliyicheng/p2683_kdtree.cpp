#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define K 2
#define N 200050
#define inf 10000000
#define DATA N*35
typedef long long ll;
int pos;
char s[DATA+1];
int read(){
	int p=0;
//	char ch=getchar();
//	while (ch<'0' || ch>'9') ch=getchar();
//	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	while (s[pos] && (s[pos]<'0' || s[pos]>'9')) pos++;
	while (s[pos] && (s[pos]>='0' && s[pos]<='9')) p=p*10+s[pos++]-'0';
	return p;
}
int D;
struct Tree_Point{
	int d[K];
	int ls, rs;
	int min_d[K], max_d[K];
	int a, sum;
	bool operator <(const Tree_Point &o) const {return d[D]<o.d[D];}
}t[N];
int A;
void update(int x){
	int ls=t[x].ls, rs=t[x].rs;
	for (int j=0;j<K;j++)
		t[x].min_d[j]=std::min(t[x].min_d[j], std::min(t[ls].min_d[j],t[rs].min_d[j])),
		t[x].max_d[j]=std::max(t[x].max_d[j], std::max(t[ls].max_d[j],t[rs].max_d[j]));
	t[x].sum=t[x].a+t[ls].sum+t[rs].sum;
}
int rebuild(int l, int r, int d){
	D=d;
	int x=l+r>>1;
	std::nth_element(t+l,t+x,t+r+1);
	for (int j=0;j<K;j++)
		t[x].min_d[j]=t[x].max_d[j]=t[x].d[j];
	if (l<x) t[x].ls=rebuild(l,x-1,d^1); else t[x].ls=0;
	if (r>x) t[x].rs=rebuild(x+1,r,d^1); else t[x].rs=0;
	update(x);
	return x;
}
int cnt;
int dx[K];
void insert(int &u, int d){
	if (!u) {
		u=++cnt;
		for (int j=0;j<K;j++)
			t[u].d[j]=t[u].min_d[j]=t[u].max_d[j]=dx[j];
		t[u].a=t[u].sum=A;
		t[u].ls=t[u].rs=0;
		return;
	}
	if (dx[d]<=t[u].d[d]) insert(t[u].ls,d^1);
	else insert(t[u].rs,d^1);
	update(u);
}
int min_d[K], max_d[K];
int query(int x){
	if (!x) return 0;
	for (int j=0;j<K;j++)
		if (t[x].min_d[j]>max_d[j] || t[x].max_d[j]<min_d[j]) return 0;
	int cont=1;
	for (int j=0;j<K;j++)
		if (!(t[x].min_d[j]>=min_d[j] && max_d[j]>=t[x].max_d[j])) cont=0;
	if (cont) return t[x].sum;
	cont=1;
	for (int j=0;j<K;j++)
		if (t[x].d[j]<min_d[j] || t[x].d[j]>max_d[j]) cont=0;
	int res=0;
	if (cont) res+=t[x].a;
	res+=query(t[x].ls)+query(t[x].rs);
	return res;
}
int main(){
	fread(s,1,DATA,stdin);
	t[0].a=t[0].sum=0;
	for (int j=0;j<K;j++)
		t[0].min_d[j]=-(t[0].max_d[j]=-inf);
	int m=read();
	int root=0;
	for (int o=0, last=0;;){
		int op=read();
		if (op==1){
			for (int j=0;j<K;j++) dx[j]=read();
			A=read();
			insert(root,0);
			if (++o==10000) root=rebuild(1,cnt,0), o=0;
		}
		else if (op==2) {
			for (int j=0;j<K;j++) min_d[j]=read();
			for (int j=0;j<K;j++) max_d[j]=read();
			printf("%d\n", query(root));
		}
		else break;
	}
	return 0;
}
