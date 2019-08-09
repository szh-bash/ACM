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
#define N 3000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int f[N], g[N], n, nxt[N];
char s[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int main(){	
	for (int _=read();_;_--){
		scanf("%s", s+1);
		n=strlen(s+1);
		f[n+1]=0;
		for (int i=n;i;i--){
			int status=1, head0=0, head1=0, tail0=0, tail1=0;
			int cycle=1;
			f[i]=n;
			g[i]=i+1;
			nxt[i]=i-1; 
			for (int j=i, p=i-1;j<=n;j++){
				if (s[j]=='0'){
					if (j!=i){
						if (s[j]!=s[p+1]) break;
						nxt[j]=++p;
					}
					
					if (head0==j-i) head0++;
					
					if (tail1){
						if (head0==tail0 && head1>tail1) break;
						cycle&=(head0==tail0 && head1==tail1),
						tail0=0, 
						tail1=0;
					}
					
					tail0++;
					
					if (!head1) status=1;
					else{
						status=0;
						if (tail0>head0) break;
					}
					
					if (status && 1+f[j+1]<f[i])
						f[i]=1+f[j+1],
						g[i]=j+1;
				}
				else{
					int flag=0;
					if (j!=i){
						while (p>=i && s[j]!=s[p+1]) p=nxt[p], flag=1;
						if (s[p+1]==s[j]) p++;
						nxt[j]=p;
					}
					
					if (head0+head1==j-i) head1++;
					tail1++;
					
					if (!status){
//						if (tail0<head0 || tail0 == head0 && tail1>head1 || tail0==head0 && tail1==head1 && cycle) status=1;
						if (flag || (j-i+1)%(j-nxt[j])==0 && (j-nxt[j])*2>=(j-i+1)) status=1;
					}
					
					if (status && 1+f[j+1]<f[i])
						f[i]=1+f[j+1],
						g[i]=j+1;
				}
			}
		}
		for (int x=1;x<=n;x=g[x]){
			for (int j=x;j<g[x];j++) printf("%c",s[j]);
			printf("%s", g[x]<=n?" ":"\n");
		}
	}
    return 0;
}
