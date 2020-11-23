#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define K 2
#define N 1000010
#define inf 100000000
#define DATA N*22
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
	int tag, D;
	int d[K];
	int ls, rs;
	int min_d[K], max_d[K];
}t[N];
struct Point{	//include operator && sort_point
	int d[K];
	int tag, op;
	bool operator <(const Point &o) const {
		return d[D]==o.d[D]?tag<o.tag:d[D]<o.d[D];
	}
	bool operator <(const Tree_Point &o) const {
		return d[D]==o.d[D]?tag<o.tag:d[D]<o.d[D];
	}
}a[N], op[N/2];
void update(int x){
	int ls=t[x].ls, rs=t[x].rs;
	for (int j=0;j<K;j++)
		t[x].min_d[j]=std::min(t[x].min_d[j], std::min(t[ls].min_d[j],t[rs].min_d[j])),
		t[x].max_d[j]=std::max(t[x].max_d[j], std::max(t[ls].max_d[j],t[rs].max_d[j]));
}
int build(int l, int r, int d){
	D=d;if (D==K) D=d=0;
//	D=rand()%K;
//	std::cout<<"Build: "<<l<<' '<<r<<' '<<d<<std::endl;
	int mid=l+r>>1;
	std::nth_element(a+l,a+mid,a+r+1);
	t[mid].tag=a[mid].tag;
	t[mid].D=D;
	for (int j=0;j<K;j++){
		t[mid].d[j]=a[mid].d[j];
		if (!t[mid].tag)
			t[mid].min_d[j]=t[mid].max_d[j]=a[mid].d[j];
		else
			t[mid].min_d[j]=-(t[mid].max_d[j]=-inf);
	}
	if (l<mid) t[mid].ls=build(l,mid-1,d+1);
	if (r>mid) t[mid].rs=build(mid+1,r,d+1);
	update(mid);
	return mid;
}
int tag;
void activate(int x){
	D=t[x].D;
//	std::cout<<"Activating: "<<x<<' '<<d<<std::endl;
	if (tag==t[x].tag){
		for (int j=0;j<K;j++)
			t[x].min_d[j]=std::min(t[x].min_d[j], t[x].d[j]),
			t[x].max_d[j]=std::max(t[x].max_d[j], t[x].d[j]);
		return;
	}
	if (op[tag]<t[x])
		activate(t[x].ls);
	else activate(t[x].rs);
	update(x);
}
int getdist(int x){
	int res=0;
	for (int j=0;j<K;j++)
		res+=std::max(t[x].min_d[j]-op[tag].d[j],0)
			+std::max(op[tag].d[j]-t[x].max_d[j],0);
	return res;
}
int ans;
int query(int x){
	int tmp=0, dls, drs;
	int ls=t[x].ls, rs=t[x].rs;
	if (t[x].tag<=tag)
		for (int j=0;j<K;j++) tmp+=abs(t[x].d[j]-op[tag].d[j]);
	else tmp=inf;
	if (ls) dls=getdist(ls); else dls=inf;
	if (rs) drs=getdist(rs); else drs=inf;
	if (tmp<ans) ans=tmp;
	tmp=dls<drs; 
	if (tmp){
		if (dls<ans) query(ls);
		if (drs<ans) query(rs);
	}
	else{
		if (drs<ans) query(rs);
		if (dls<ans) query(ls);
	}
}
int main(){
	fread(s,1,DATA,stdin);
	srand(unsigned(time(NULL)));
	int n=read(), m=read();
	for (int i=1;i<=n;i++)
		for (int j=0;j<K;j++) a[i].d[j]=read();
	for (int i=1;i<=m;i++){
		op[i].tag=i;
		op[i].op=read();
		for (int j=0;j<K;j++) op[i].d[j]=read();
		if (op[i].op==1) a[++n]=op[i];
	}
	for (int j=0;j<K;j++)
		t[0].min_d[j]=-(t[0].max_d[j]=-inf);
	int root=build(1,n,0);
//	std::cout<<"Operating!"<<' '<<n<<' '<<m<<std::endl;
	for (tag=1;tag<=m;tag++)
		if (op[tag].op==1)
			activate(root);
		else{
			ans=inf-1;
			query(root);
			printf("%d\n", ans);
		}
	return 0;
}
