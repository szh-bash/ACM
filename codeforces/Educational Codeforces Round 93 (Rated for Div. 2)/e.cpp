#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
#define Q 500005
struct node{
	int tp, x;
}l[Q];
int n, b[Q], len[2], flag[2][Q];
ll f[Q*4], s[Q*4], trans[Q];
map <int, int> mp;
void upd(int t, int l, int r, int x, int y){
	if (l==r){
		f[t]+=y;
		s[t]+=y/abs(y);
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) upd(t<<1, l, mid, x, y);
	else upd((t<<1)+1, mid+1, r, x, y);
	f[t]=f[t<<1]+f[(t<<1)+1];
	s[t]=s[t<<1]+s[(t<<1)+1];
}
ll query(int t, int l, int r, int x){
	if (s[t]<=x) return f[t];
	if (l==r) return f[t]/s[t]*x;
	int mid=l+r>>1;
	ll tmpL=0, tmpR=query((t<<1)+1,mid+1,r,x);
	if (x>s[(t<<1)+1]) tmpL=query(t<<1,l,mid,x-s[(t<<1)+1]);
	return tmpL+tmpR;
}
priority_queue<int, vector<int>, less<int> > p;
priority_queue<int, vector<int>, greater<int> > q;
int main(){
	n=read();
	int ct=0;
	for (int i=1;i<=n;i++){
		int u=read(), v=read();
		l[i].tp=u;
		l[i].x=v;
		b[i]=abs(v);
	}
	sort(b+1,b+1+n);
	for (int i=1;i<=n;i++)
		if (b[i]!=b[i-1]) trans[mp[b[i]]=++ct]=b[i];
	ll sum=0;
	for (int i=1;i<=n;i++){
		sum+=l[i].x;
		len[l[i].tp]+=l[i].x/abs(l[i].x);
		upd(1,1,ct,mp[abs(l[i].x)],l[i].x);
		if (l[i].tp){
			if (l[i].x>0) q.push(mp[l[i].x]), flag[1][mp[l[i].x]]=0;
			else flag[1][mp[-l[i].x]]=1;
		}
		else{
			if (l[i].x>0) p.push(mp[l[i].x]), flag[0][mp[l[i].x]]=0;
			else flag[0][mp[-l[i].x]]=1;
		}
		while (!q.empty() && flag[1][q.top()]) q.pop();
		while (!p.empty() && flag[0][p.top()]) p.pop();
		ll fix=0;
		if (!q.empty() && (p.empty() || p.top()<q.top())) 
			fix=-trans[q.top()]+trans[p.empty()?0:p.top()];
		else fix=0;
//		cout<<i<<' '<<sum<<' '<<fix<<' '; 
//		if (i==124858) cout<<i<<"-"<<sum<<"-"<<fix<<"-"<<l[i].x<<"-"<<l[i].tp<<"-"<<q.empty()<<"-"<<p.empty()<<"-";
//		if (i==124858) fix=-fix;
		printf("%I64d\n", (len[1]?query(1,1,ct,len[1]):0ll)+sum+fix);
	}
	return 0;
}
