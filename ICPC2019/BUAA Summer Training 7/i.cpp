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
#define N 200
#define T 20000
#define M 100000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m, ma, cnt, con[N], fa[N], fr[N];
int nex[M], nu[M], a[M];
char op[10], s[10];
int id[200];
int q[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;fr[v]=cnt;
}
void build(int u){
	int tmp=n+1, p;
	for (int j=nex[u];j>-1;j=nex[j]){
		if (nu[j]<tmp) tmp=nu[j], p=j;
		build(nu[j]);
	}
	con[u]=p;
}
vector<pair<int, int> > l[T];
pair<int, int> ans[M];
bool cmp(pair<int, int> a, pair<int, int> b){return a.second<b.second;}
int main(){
	freopen("instruction.in", "r", stdin);
	freopen("instruction.out", "w", stdout);
	cnt=n=read();
	for (int i=0;i<=n;i++) nex[i]=-1, fa[i]=i;
	for (int i=1;i<=n;i++){
		scanf("%s", op);
		fa[i]=read();
		add(fa[i], i);
		if (op[0]=='p'){
			scanf("%s", s);
			id[s[0]]=i;
		}
	}
	build(0);
	m=read();
	for (int i=1;i<=m;i++){
		a[i]=read();
		scanf("%s", s);
		int j=id[s[0]];
		int ct=0;
		while (j){
			q[++ct]=j;
			j=fa[j];
		}
		q[++ct]=j;
		for (int j=ct;j>1;j--){
			pair <int, int> p;
			p={q[j], fr[q[j-1]]};
			l[ct-j+a[i]].push_back(p);
		}
		ma=max(ma, ct-1+a[i]);
	}
	cnt=0;
	for (int i=0;i<=ma;i++){
		int len=l[i].size();
		for (int j=0;j<len;j++){
			pair <int, int> p=l[i][j];
			if (con[p.first]!=p.second)
				con[p.first]=p.second,
				ans[++cnt]={i,p.first};
		}
	}
	sort(a+1, a+1+cnt);
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;i++)
		printf("%d %d\n", ans[i].second, ans[i].first);
    return 0;
}
