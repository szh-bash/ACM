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
#define N 5500
#define M N*N
#define Q 60000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
#define inf 100005
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, q;
int a[N], b[N], c[N];
struct wave{
	int id, pre, nex;
	double l, r;
}l[M];
int ans[Q], num[Q];
ll y[Q];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int op;
double x0, x1;
int tag0, tag1;
int root;
void calc(int x, int v){
	int da=a[x]-a[v], db=b[x]-b[v], dc=c[x]-c[v];
	
	if (!da){
		//bx+c=0
		if (!db){
			op=-1;
			tag0=dc>=0?1:-1;
			return;
		}
		else{
			op=0,
			x0=-(double)dc/db,
			tag0=db<0?1:-1,
			tag1=db>0?1:-1;
			return;
		}
	}
	
	ll gen=1ll*db*db-1ll*4*da*dc;
	if (gen<=0) {
		op=-1;
		tag0=da>=0?1:-1;
		return;
	}
	
	op=1;
	x0=(-db-sqrt(gen))/(2*da), x1=(-db+sqrt(gen))/(2*da);
	if (da>0) tag0=-1;
	else swap(x0, x1), tag0=1;
	return;
}
bool cmp(int a, int b){return ans[a]<ans[b];}
void unio(int j){
	int u=l[j].pre;
	l[j].l=l[u].l;
	l[j].pre=l[u].pre;
	l[l[u].pre].nex=j;
	if (u==root) root=j;
}
void solve(){
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read(), b[i]=read(), c[i]=read();
	int cnt=1;
	root=1;
	l[1].id=1;
	l[1].l=-(l[1].r=inf);
	l[1].pre=0;
	l[1].nex=0;
	for (int i=2;i<=n;i++){
		for (int j=root;j;j=l[j].nex){
//			cout<<i<<' '<<j<<' '<<root<<endl;
			if (l[j].id==i){
				if (l[l[j].pre].id==i) unio(j);
				continue;
			}
			int v=l[j].id;
			calc(i, v);
			if (op==-1 && tag0==1){
				l[j].id=i;
			}
			else if (op==0){
				if (x0<=l[j].l){
					if (tag1==1) l[j].id=i;
				}
				else if (x0>=l[j].r){
					if (tag0==1) l[j].id=i;
				}
				else{
					l[++cnt].id=i;
					if (tag0==1){
						l[cnt].l=l[j].l;
						l[cnt].r=x0;
						l[cnt].pre=l[j].pre;
						l[l[j].pre].nex=cnt;
						l[cnt].nex=j;
						l[j].pre=cnt;
						l[j].l=x0;
					}
					else{
						l[cnt].r=l[j].r;
						l[cnt].l=x0;
						l[cnt].nex=l[j].nex;
						l[l[j].nex].pre=cnt;
						l[cnt].pre=j;
						l[j].nex=cnt;
						l[j].r=x0;
					}
				}
			}
			else if (op==1){
				if (x0>=l[j].r){
					if (tag0==-1) l[j].id=i;
				}
				else if (x1<=l[j].l){
					if (tag0==-1) l[j].id=i;
				}
				else if (x0<=l[j].l && l[j].r<=x1){
					if (tag0==1) l[j].id=i;
				}
				else if (l[j].l<=x0 && x1<=l[j].r){
					if (tag0==1){
						l[++cnt].id=j;
						l[cnt].nex=l[j].nex;
						l[l[j].nex].pre=cnt;
						l[cnt].l=x1;
						l[cnt].r=l[j].r;
						
						l[++cnt].id=i;
						l[cnt].nex=cnt-1;
						l[cnt].pre=j;
						l[cnt].l=x0;
						l[cnt].r=x1;
						
						l[j].nex=cnt;
						l[cnt-1].pre=cnt;
						
						l[j].r=x0;
					}
					else{
						l[++cnt].id=i;
						l[cnt].nex=l[j].nex;
						l[l[j].nex].pre=cnt;
						l[cnt].l=x1;
						l[cnt].r=l[j].r;
						
						l[++cnt].id=j;
						l[cnt].nex=cnt-1;
						l[cnt].pre=j;
						l[cnt].l=x0;
						l[cnt].r=x1;
						
						l[j].nex=cnt;
						l[cnt-1].pre=cnt;
						
						l[j].r=x0;
						l[j].id=i;
					}
				}
				else if (l[j].l<=x0){
					l[++cnt].id=i;
					if (tag0==-1){
						l[cnt].l=l[j].l;
						l[cnt].r=x0;
						l[cnt].pre=l[j].pre;
						l[l[j].pre].nex=cnt;
						l[cnt].nex=j;
						l[j].pre=cnt;
						l[j].l=x0;
					}
					else{
						l[cnt].r=l[j].r;
						l[cnt].l=x0;
						l[cnt].nex=l[j].nex;
						l[l[j].nex].pre=cnt;
						l[cnt].pre=j;
						l[j].nex=cnt;
						l[j].r=x0;
					}
				}
				else if (x1<=l[j].r){
					l[++cnt].id=i;
					if (tag0==1){
						l[cnt].l=l[j].l;
						l[cnt].r=x1;
						l[cnt].pre=l[j].pre;
						l[l[j].pre].nex=cnt;
						l[cnt].nex=j;
						l[j].pre=cnt;
						l[j].l=x1;
					}
					else{
						l[cnt].r=l[j].r;
						l[cnt].l=x1;
						l[cnt].nex=l[j].nex;
						l[l[j].nex].pre=cnt;
						l[cnt].pre=j;
						l[j].nex=cnt;
						l[j].r=x1;
					}
				}
			}
			if (l[j].id==i && l[l[j].pre].id==i) unio(j);
		}
//		cout<<i<<' '<<cnt<<endl;
	}
	q=read();
	for (int i=1;i<=q;i++) ans[i]=read(), num[i]=i;
	sort(num+1, num+1+q, cmp);
	for (int i=1, j=root;i<=q;i++){
		int u=num[i];
		while (ans[u]>l[j].r) j=l[j].nex;
		int p=l[j].id;
		y[u]=1ll*a[p]*ans[u]*ans[u]+1ll*b[p]*ans[u]+c[p];
		ans[u]=p;
	}
	for (int i=1;i<=q;i++) printf("%d %I64d\n", ans[i]-1, y[i]);
}
int main(){
	freopen("parabolas.in","r",stdin);
	for (int _=read(), o=1;_;_--, o++){
		printf("Case %d:\n", o);
		solve();
	}
    return 0;
}
