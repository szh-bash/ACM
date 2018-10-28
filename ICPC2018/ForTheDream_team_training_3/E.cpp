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
#define INF 100000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
#define M (100000*12+5)
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int de[10];
int n, cnt, st, ed, nex[M*20], nu[M*20];
int dis[M], flag[M];
//int de[10];
struct node{
	int n, dist;
	node (int n, int dist): n(n), dist(dist) {}
	bool operator <(const node &o) const {return this->dist<o.dist;}
	bool operator >(const node &o) const {return this->dist>o.dist;}
};
priority_queue<node, vector<node>, greater<node> > q;
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
//	cout<<u<<' '<<v<<endl;
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
bool check(int x){
	for (int i=1;i<=5;i++) flag[i]=1;
	while (x){
		flag[x%10]--;
		x/=10;
	}
	for (int i=1;i<=5;i++) if (flag[i]) return 0;
	return 1;
}
void add_plus(int x){
	for (int p=0;p<5;p++)
		for (int i=0;i<3;i++)
			for (int j=0;j<=2;j++){
//				cout<<"plus: "<<x<<' '<<p<<' '<<i<<' '<<j<<endl;
				int v=(x/de[p])%10;
//				cout<<x<<' '<<p<<' '<<v<<' '<<de[p]<<' ';
				if (++v>9) v=0;
				v=(x/de[p+1]*10+v)*de[p]+x%de[p];
//				cout<<v<<' '<<cnt<<endl;
				add(x*12+i*3+j,v*12+(i+1)*3+j);
			}

}
void add_double(int x){
	for (int p=0;p<5;p++)
		for (int i=0;i<4;i++)
			for (int j=0;j<2;j++){
//				cout<<"double: "<<x<<' '<<p<<' '<<i<<' '<<j<<endl;
				int v=x/de[p]%10;
//				cout<<x<<' '<<p<<' '<<v<<' '<<de[p]<<' ';
				v*=2;
				if (v>9) v-=10;
				v=(x/de[p+1]*10+v)*de[p]+x%de[p];
//				cout<<v<<' '<<cnt<<endl;
				add(x*12+i*3+j,v*12+i*3+j+1);
			}

}
void add_swap(int x){
	for (int p=0;p<4;p++)
//		for (int i=0;i<1;i++)
//			for (int j=0;j<1;j++){
			{
//				cout<<"swap: "<<x<<' '<<p<<endl;
				int u=x/de[p]%10, v=x/de[p+1]%10, w;
				if (u==v) continue;
				w=x%de[p]+v*de[p]+u*de[p+1]+x/de[p+2]*de[p+2];
//				cout<<x<<' '<<w<<endl;
			//	add(x*12+i*3+j,w*12+i*3+j);
				add(x*12,w*12);
			}
}
void build(){
	for (int i=0;i<100000;i++)
		add_plus(i),
		add_double(i),
		(check(i)?add_swap(i):void(0));
}
void dijkstra(){
	n=100000*12;
	for (int i=1;i<=5;i++) flag[i]=0;
	for (int i=0;i<=n;i++) dis[i]=INF;
	dis[st]=0;
	q.push(node(st,0));
	while (!q.empty()){
		node curNode=q.top();
		q.pop();
		int u=curNode.n;
		flag[u]=1;
	//	cout<<u<<' '<<dis[u]<<endl;
		for (int j=nex[u];j;j=nex[j]){
			int v=nu[j];
			if (!flag[v] && dis[u]+1<dis[v])
				dis[v]=dis[u]+1,
				q.push(node(v,dis[v]));
		}
		while (!q.empty() && flag[q.top().n]) q.pop();
	}
}
int get_ans(int ed){
	int ans=INF;
	for (int i=0;i<4;i++)
		for (int j=0;j<3;j++)
			ans=min(ans,dis[ed*12+i*3+j]);
	return ans==INF?-1:ans;
}
int main(){
	de[0]=1;
	for (int i=1;i<6;i++) de[i]=de[i-1]*10;
	cnt=100000*12;
	st=12345*12;
	build();
	dijkstra();
//	return 0;
//	for (int i=1;i<=n;i++) cout<<i<<' '<<dis[i]<<endl;
    while (~scanf("%d", &ed)) printf("%d\n", get_ans(ed));
	return 0;
}
