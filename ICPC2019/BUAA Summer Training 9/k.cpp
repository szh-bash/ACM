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
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
#define N 300000
#define M 800000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m, cnt, in[N];
int nex[M], nu[M];
int ans[N];
int ct;
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
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
struct node{
	int n;
	node (int n): n(n){}
	bool operator <(const node &o) const {return this->n<o.n;}
	bool operator >(const node &o) const {return this->n>o.n;} 
};
priority_queue<node, vector<node>, less<node> > q;
int main(){
	cnt=n=read();
	m=read();
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
//		add(u, v);
//		in[v]++;
		add(v, u);
		in[u]++;
	}
	for (int i=1;i<=n;i++) if (!in[i]) q.push(node(i));
	for (int i=1;!q.empty();i++){
		int u=q.top().n;
		q.pop();
		for (int j=nex[u];j;j=nex[j]){
			int v=nu[j];
			if (!--in[v]) q.push(node(v));
		}
		ans[++ct]=u;
	}
	while (ct) printf("%d ", ans[ct--]);
    return 0;
}
