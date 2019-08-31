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
#define N 300
#define M (N*N)
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
pair <int, int> ans[M];
int f[N][N], g[N][N], d[N], num[N], tmpd[N];
int n;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
bool cmp(int x, int y){return d[x]>d[y];}
int main(){
	while (~scanf("%d", &n)){
		int sum=0;
		for (int i=1;i<=n;i++) tmpd[i]=d[i]=read(), num[i]=i, sum+=d[i];
		if (sum&1){
			puts("IMPOSSIBLE");
			continue;
		}
		
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) f[i][j]=0;
		bool flag=1;
		int ct=n;
		sort(num+1, num+1+ct, cmp);
		while (ct && !d[num[ct]]) ct--;
		while (ct>1){
			
			int td=d[num[1]];
			for (int i=1;i<=td && i+1<=ct;i++)
				f[num[1]][num[i+1]]=f[num[i+1]][num[1]]=1,
				d[num[i+1]]--,
				d[num[1]]--;
			if (d[num[1]]) {flag=0;break;}
			while (ct && !d[num[1]]) num[1]=num[ct--], sort(num+1, num+1+ct, cmp);
		}
		if (!flag || ct) puts("IMPOSSIBLE");
		
		flag=0;
		ct=n;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				g[i][j]=f[i][j], f[i][j]=0;
		for (int i=1;i<=n;i++) d[i]=tmpd[i], num[i]=i;
		sort(num+1, num+1+ct, cmp);
		while (ct && !d[num[ct]]) ct--;
		while (ct>1){
			int td=d[num[1]];
			if (!flag && td+2<=ct && d[num[td+2]]==d[num[td+1]]){
				flag=1;
				f[num[1]][num[td+2]]=f[num[td+2]][num[1]]=1;
				d[num[1]]--;
				d[num[td+2]]--;
				td--;
			}
			for (int i=1;i<=td && i+1<=ct;i++)
				f[num[1]][num[i+1]]=f[num[i+1]][num[1]]=1,
				d[num[i+1]]--,
				d[num[1]]--;
			sort(num+1, num+1+ct, cmp);
			while (ct && !d[num[ct]]) ct--;
		}
		if (!flag){
			printf("UNIQUE\n%d %d\n", n, sum/2);
			int ct=0;
			for (int i=1;i<=n;i++)
				for (int j=i+1;j<=n;j++)
					if (g[i][j]) ans[++ct]={i,j};
			for (int i=1;i<=ct;i++) printf("%d%s", ans[i].first, i==ct?"\n":" ");
			for (int i=1;i<=ct;i++) printf("%d%s", ans[i].second, i==ct?"\n":" ");
			if (!ct) printf("\n\n");
		}
		else{
			printf("MULTIPLE\n%d %d\n", n, sum/2);
			int ct=0;
			for (int i=1;i<=n;i++)
				for (int j=i+1;j<=n;j++)
					if (g[i][j]) ans[++ct]={i,j};
			for (int i=1;i<=ct;i++) printf("%d%s", ans[i].first, i==ct?"\n":" ");
			for (int i=1;i<=ct;i++) printf("%d%s", ans[i].second, i==ct?"\n":" ");
			ct=0;
			for (int i=1;i<=n;i++)
				for (int j=i+1;j<=n;j++)
					if (f[i][j]) ans[++ct]={i,j};
			printf("%d %d\n", n, sum/2);
			for (int i=1;i<=ct;i++) printf("%d%s", ans[i].first, i==ct?"\n":" ");
			for (int i=1;i<=ct;i++) printf("%d%s", ans[i].second, i==ct?"\n":" ");
		}
	}
    return 0;
}
