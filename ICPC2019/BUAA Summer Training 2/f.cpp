#include <map>
#include <set>
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
#define N 200005
#define M 1000005
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, l[N], e[N], c[N], cnt;
ll bit[2][M];
pair<int, int> event[N];
set <int> s;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void bit_add(ll *bit, int x, int y){
	for (; x && x< N; x+=(x & -x)) bit[x]+=y;
}
ll bit_query(ll *bit, int x){
	ll res=0;
	for (; x; x-=(x & -x)) res+=bit[x];
	return res;
}
void add(int x){
	s.insert(x);
	auto it=s.find(x);
	int pre=-1, nex=-1;
	if (it!=s.begin()){
		pre=*--it;
		++it;
		bit_add(bit[0], x-pre, 1);
		bit_add(bit[1], x-pre, x-pre);
	}
	if (++it!=s.end()){
		nex=*it;
		bit_add(bit[0], nex-x, 1);
		bit_add(bit[1],	nex-x, nex-x);
	}
	if (pre!=-1 && nex!=-1){
		bit_add(bit[0], nex-pre, -1);
		bit_add(bit[1], nex-pre, pre-nex);
	}
	
}
void del(int x){
	auto it=s.find(x);
	int pre=-1, nex=-1;
	if (it!=s.begin()){
		pre=*--it;
		++it;
		bit_add(bit[0], x-pre, -1);
		bit_add(bit[1], x-pre, pre-x);
	}
	if (++it!=s.end()){
		nex=*it;
		bit_add(bit[0], nex-x, -1);
		bit_add(bit[1],	nex-x, x-nex);
	}
	if (pre!=-1 && nex!=-1){
		bit_add(bit[0], nex-pre, 1);
		bit_add(bit[1], nex-pre, nex-pre);
	}
	s.erase(x);
}
ll solve(){
	memset(bit, 0, sizeof(bit));
	s.clear();
	n=read();
	for (int i=1;i<=n;i++) e[i]=read(), l[i]=read(), c[i]=read();
	cnt=0;
	for (int m=read();m;m--){
		int t=read(), si=read(), ti=read();
		event[++cnt]={si, t};
		event[++cnt]={ti+1, -t};
	}
	sort(event+1,event+1+cnt);
	ll ans=0;
	for (int i=1, j=1;i<=N;i++){
		while (j<=cnt && event[j].first==i){
			int t=event[j++].second;
			if (t>0) add(t); else del(-t);
		}
		if (s.empty()) continue;
		ans+=min(1ll*c[i], e[i]+1ll*(*s.begin())*l[i]);
		if (l[i]){
			int step=c[i]/l[i];
			ans+=bit_query(bit[1], step)*l[i];
			ans+=(s.size()-1-bit_query(bit[0], step))*c[i];
		}
	}
	return ans;
}
int main(){
	for (int _=read(), o=1;_;_--, o++)
		printf("Case #%d: %lld\n", o, solve());
    return 0;
}
