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
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
struct node{
	int n, x;
	node (int n, int x): n(n), x(x){}
	bool operator <(const node &o) const {return this->x<o.x;}
	bool operator >(const node &o) const {return this->x>o.x;} 
};
node st(0,0);
priority_queue<node, vector<node>, less<node> > q;
int n, m, a[N], b[N], ans;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int check(){
	while (!q.empty()) q.pop();
	for(int i=2;i<=m;i++) q.push(node(i,a[i]));
	node tmp(0,0);
	while (!q.empty() && st.x){
		node top=q.top();
		q.pop();
		if (top.n!=st.n){
			if (top.x){
				top.x--,
				st.x--,
				q.push(top);
			}
			else{
				q.push(top);
				break;
			}
		}
		else tmp = top;
	}
	if (st.x){
		if (st.n==1) return st.x+a[1];
		return a[1]-st.x-tmp.x;
	}
	q.push(tmp);
	int ct=1, sum=0;
	while (!q.empty()) {
		b[++ct]=q.top().x, q.pop(), sum+=b[ct];
	}
	while (!b[ct] && ct>2) ct--;
	if (ct==2) return a[1]-b[2];
	if (b[2]*2>=sum) return a[1]-(b[2]*2-sum);
	if (sum&1) return a[1]-1;
	return a[1];
}
int main(){
	n=read();m=read();
	for (int i=1;i<=m;i++) a[i]=read();
	ans = max(0, check());
	if (ans){
		puts("YES");
		printf("%d\n",ans);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (a[j]){
					a[j]--;
					node st_tmp=st;
					if (!st.x)
						st.n=j,
						st.x=1;
					else if (st.n!=j)
						st.x--;
					else st.x++;
					node st_tmp2=st;
					if (check()==ans){
						st=st_tmp2;
						printf("%d\n",j);
						break;
					}
					st=st_tmp;
					a[j]++;
				}
			
	}
	else puts("NO");
    return 0;
}
