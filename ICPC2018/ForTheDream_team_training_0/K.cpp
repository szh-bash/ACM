#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef long long ll;
using namespace std;
int n;
int g[N];
int p[N], q[N], bit[N];
char s[N], s0[N], s1[N];
void add(int &a, int b){
	a=a+b>mo?mo:a+b;
}
int main(){
	bit[0]=1;
	for (int i=1;i<N;i++) bit[i]=(bit[i-1]<<1)>mo?mo:(bit[i-1]<<1);
	int _;cin>>_;
	for (;_;_--){
		cin>>n;n++;
		scanf("%s%s%s", s+1, s0+1, s1+1);
		s[n]=s0[n]=s1[n]='0';
		int pi0=0, pi1=0;
		for (int i=1;i<=n;i++){
			if (s0[i]=='0') p[i]=1, pi0=i;
			else p[i]=pi0?bit[i-pi0]:mo;
			if (s1[i]=='0') q[i]=1, pi1=i;
			else q[i]=pi1?bit[i-pi1]:mo;
		} 
		int fq=mo;
		for (int i=1;i<=n;i++)
			if (s[i]=='1'){
				g[i]=(g[i-1]+p[i])>mo?mo:(g[i-1]+p[i]);
				int qq=0, mi=mo;
				for (int j=i+1;j<=n && s[j]=='0' && qq<mo;j++)
					mi=min(mi,qq+p[j]),
					qq+=q[j];
				fq=min(fq,g[i-1]+q[i]);
				g[i]=min(g[i],fq+mi);
			}
			else
				g[i]=g[i-1],
				add(fq,q[i]);
		cout<<g[n]<<endl;
	}
    return 0;
}
