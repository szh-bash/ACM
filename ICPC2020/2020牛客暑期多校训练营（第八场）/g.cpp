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
#define N 300
#define M (N*N)
int n, f[N][5];
char s[200];
void init(){
	n=read();
	for (int i=1;i<=n;i++){
		scanf("%s", s);
		for (int j=0, t=0;s[j];j++)
			if (s[j]=='['){
				++t;
				if (t==1){
					if (s[j+1]=='o') f[i][t]=1;
					else if (s[j+2]=='w') f[i][t]=2;
					else if (s[j+2]=='h') f[i][t]=3;
					else f[i][t]==0;
				}
				else if (t==2){
					if (s[j+1]=='d') f[i][t]=1;
					else if (s[j+1]=='s') f[i][t]=2;
					else if (s[j+1]=='o') f[i][t]=3;
					else f[i][t]==0;
				}
				else if (t==3){
					if (s[j+2]=='o') f[i][t]=1;
					else if (s[j+2]=='t') f[i][t]=2;
					else if (s[j+2]=='p') f[i][t]=3;
					else f[i][t]==0;
				}
				else{
					if (s[j+1]=='r') f[i][t]=1;
					else if (s[j+1]=='g') f[i][t]=2;
					else if (s[j+1]=='p') f[i][t]=3;
					else f[i][t]==0;
				}
			}
		for(int j=1;j<=4;j++) cout<<f[i][j]<<' ';cout<<endl; 
	}
}
int cnt;
int l[5], r[5], power[5], bit[5];
int nex[M], nu[M], sum[N];
int mask[N];
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
	sum[u]++;
}
void insert(){
	cnt=258;
	for (int i=0;i<cnt;i++) sum[i]=nex[i]=0;
	for (int i=1;i<=n;i++){
		mask[i]=0;
		for (int j=1;j<=4;j++){
			l[j]=f[i][j];
			if (f[i][j]) r[j]=f[i][j]; else r[j]=3;
			mask[i]+=(f[i][j]==0)*bit[4-j];
		}
		for (int a=l[1];a<=r[1];a++)
			for (int b=l[2];b<=r[2];b++)
				for (int c=l[3];c<=r[3];c++)
					for (int d=l[4];d<=r[4];d++)
						add(a*64+b*16+c*4+d,i);
	}
}
int st[5];
int stat[3][6]={{1, 1, 2, 2, 3, 3}, {2, 3, 1, 3, 1, 2}, {3, 2, 3, 1, 2, 1}};
void solve(int T){
	init();
	insert();
	int m=9*9*9*9;
	for (int i=0;i<m;i++){
		int x=i, free=0, ms=0;
		st[1]=st[2]=st[3]=0;
		for (int j=1;j<=4;j++){
			int p=x%9;
			if (p>5)
				st[1]+=(p-5)*power[4-j],
				st[2]+=(p-5)*power[4-j],
				st[3]+=(p-5)*power[4-j],
				free+=(p-5)*power[4-j]; 
			else
				st[1]+=stat[0][p]*power[4-j],
				st[2]+=stat[1][p]*power[4-j], 
				st[3]+=stat[2][p]*power[4-j],
				ms+=bit[4-j];
			x/=9;
		}
//		cout<<st[1]<<' '<<st[2]<<' '<<st[3]<<endl;
		int nd = ((sum[st[1]]-sum[free])==0)
				+((sum[st[2]]-sum[free])==0)
				+((sum[st[3]]-sum[free])==0);
		if (nd<=sum[free]){
			printf("Case #%d:", T);
			for (int j=1;j<=3;j++){
				int flag=(sum[st[j]]-sum[free])==0;
				cout<<j<<' '<<st[j]<<' '<<flag<<' '<<ms<<' '<<free<<endl;
				for (int k=nex[st[j]];k;k=nex[k]){
					int v=nu[k];
					if ((mask[v]&ms)!=ms || flag){
						printf(" %d", v);
						break;
					}
				}
			}
			puts("");
			return;
		}
	}
	puts("-1");
}
int main(){
	power[0]=bit[0]=1;
	for (int i=1;i<=4;i++) power[i]=power[i-1]*4, bit[i]=bit[i-1]*2;
	for (int _=read(), o=1;_;_--, o++) solve(o);
    return 0;
}
