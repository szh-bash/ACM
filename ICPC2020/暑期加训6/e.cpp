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
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 200005
struct node{
	int x, y, n;
	node(){}
	node (int n, int x): n(n), x(x){}
	bool operator <(const node &o) const {return this->x<o.x;}
	bool operator >(const node &o) const {return this->x>o.x;} 
}l[N];
bool cmp(node &a, node &b){ return a.x<b.x;}
int n, k, cnt, flag[N], r[N];
priority_queue<node, vector<node>, less<node> > q;
int main(){
	n=read();k=read();
	for (int i=1;i<=n;i++){
		int x=read(), y=read();
		l[++cnt].x=x;l[cnt].y=i;
		l[++cnt].x=y;l[cnt].y=-i;
		r[i]=y;
	}
	sort(l+1,l+1+cnt,cmp);
	int ans=n, sum=0;
	for (int i=1, j=1;i<=cnt;i=j){
		for (;j<=cnt && l[j].x==l[i].x;j++){
			if (l[j].y>0) q.push(node(l[j].y,r[l[j].y])), flag[l[j].y]=1;
			sum+=l[j].y/abs(l[j].y)*flag[abs(l[j].y)];
			if (l[j].y<0) flag[-l[j].y]=0;
		}
		while (sum>k){
			node top=q.top();
			q.pop();
			if (flag[top.n])
				flag[top.n]=0,
				sum--,
				ans--;
		}
	}
	cout<<ans<<endl;
    return 0;
}
