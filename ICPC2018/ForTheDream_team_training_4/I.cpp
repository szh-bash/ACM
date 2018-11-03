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
#define N 500000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
double ans[N];
int n, m;
int cnt, cnt0, nex[N], nex0[N], nu[N], nu0[N];
int tmpco[N], co[N], fa[N], tag[N], modi[N], flag[N];
int ff[N], li[N];
ll vi[N], num[N];
struct njh{
	int co;
}l[N];
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
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void add0(int u, int v){
	if (u==v) return;
	nex0[++cnt0]=nex0[u];nex0[u]=cnt0;nu0[cnt0]=v;
}
int father(int x){ return fa[x]==x?x:fa[x]=father(fa[x]);}
int main(){
	while (~scanf("%d%d", &n, &m)){
		cnt=cnt0=n;
		for (int i=1;i<=n;i++)
			co[i]=fa[i]=i,
			nex[i]=nex0[i]=num[i]=0,
			tag[i]=1;
		for (int i=1;i<=m;i++){
			int u=read(), v=read();
			add(u,v);
			add(v,u);
		}
		for (int i=1;i<=n;i++)
			for (int j=nex[i];j;j=nex[j]) co[nu[j]]=co[i];
		for (int i=1;i<=n;i++){
			add0(i,co[i]);
			if (father(i)==father(co[i])) continue;
			fa[fa[i]]=fa[co[i]];
		}
		for (int i=1;i<=n;i++) tmpco[i]=co[i], co[i]=father(i), num[co[i]]++;
		for (int i=1;i<=n;i++){
			cnt=0;
			for (int j=nex[i];j;j=nex[j]){
				int v=nu[j];
				if (co[i]==co[v]) continue;
				if (!flag[co[i]]){
					flag[co[i]]=1;
					l[++cnt].co=co[i];
					vi[co[i]]+=num[co[i]]*(i-tag[co[i]]);
				}
				modi[co[i]]++;
				if (!flag[co[v]]){
					flag[co[v]]=1;
					l[++cnt].co=co[v];
					vi[co[v]]+=num[co[v]]*(i-tag[co[v]]);
				}
				modi[co[v]]--;
				co[v]=co[i];
			}
		//	cout<<num[1]<<' '<<tag[1]<<endl;
		//	for (int j=1;j<=n;j++) cout<<co[j]<<' ';cout<<endl;
			for (int j=1;j<=cnt;j++)
				tag[l[j].co]=i,
				num[l[j].co]+=modi[l[j].co],
				flag[l[j].co]=modi[l[j].co]=0;
		}
		for (int i=1;i<=n;i++){
			vi[i]+=num[i]*(n+1-tag[i]);
		//	cout<<i<<' '<<vi[i]<<' '<<num[i]<<endl;
		}
		for (int i=1;i<=n;i++) ff[i]=0;
		int countt=0;
		for (int i=1;i<=n;i++){
			if (flag[fa[i]]) continue;
			flag[fa[i]]=1;
			int ct, p=i;
			ff[i]=1;
			li[ct=1]=i;
		//	cout<<"Tree "<<i<<" ";
			for (int j=nex0[i];j;){
				int v=nu0[j];
				p=v;
				//cout<<v<<' ';
				if (ff[v]) break;
				ff[v]=1;
				li[++ct]=v;
				j=nex0[v];
			}
		//	cout<<endl;
			int tot=0;
			for (int j=ct;j;j--){
				tot++;
				if (li[j]==p) break;
			}
			for (int j=ct;j;j--){
				//cout<<"lyk "<<tmpco[li[j]]<<' '<<tot<<endl;
				ans[++countt]=(double)vi[fa[li[j]]]/tot/n;
				if (li[j]==p) break;
			}
		}
		for (int i=1;i<=n;i++) flag[i]=ff[i]=vi[i]=0;
		sort(ans+1,ans+1+countt);
		for (int i=countt;i;i--) printf("%.6lf\n", ans[i]);
	}
    return 0;
}
