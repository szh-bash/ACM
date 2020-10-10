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
	int x, y;
}l[N];
bool cmp(node &a, node &b){ return a.x<b.x;}
int n, k, cnt;
int main(){
	n=read();k=read();
	for (int i=1;i<=n;i++){
		int x=read();
		l[++cnt].x=x;l[cnt].y=1;
		l[++cnt].x=x+1000;l[cnt].y=-1;
	}
	sort(l+1,l+1+cnt,cmp);
	int ans=0, sum=0;
	for (int i=1, j=1;i<=cnt;i=j){
		for (;j<=cnt && l[j].x==l[i].x;j++) sum+=l[j].y;
		ans=max(ans,sum);
	}
	cout<<(ans-1)/k+1<<endl;
    return 0;
}
