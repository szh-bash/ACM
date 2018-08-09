#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 50000*10
#define M 200000*20
using namespace std;
int n, m, len, o, ans, q[M], instack[N], nexx[M], nuu[M], l[N], d[N], tag[N], rev[N], u[M], v[M], ch1[M], ch2[M], pos[N], w[N][3], nex[M], nu[M], dfn[N], low[N], stack[N], fflag[N], co[N], top, cnt, ct;
char s[N], s1[N], s2[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	stack[++top]=u;
	instack[u]=1;
	fflag[u]=1;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else
			if (instack[v]) low[u]=min(low[u],dfn[v]);
	}
	fflag[u]=0;
	if (low[u]==dfn[u]){
		co[stack[top]]=++ct;
		instack[stack[top]]=0;
		while (stack[top--]!=u) co[stack[top]]=ct, instack[stack[top]]=0;
	}
}
int main(){
	len=n=read();m=read();
	scanf("%s", s+1);
	for (int i=1;i<=len;i++)
		if (s[i]=='x') pos[++pos[0]]=i;
		else
			if (s[i]=='a') w[i][0]=1, w[i][1]=2;
			else
				if (s[i]=='b') w[i][0]=0, w[i][1]=2;
				else w[i][0]=0, w[i][1]=1;
	o=read();
	for (int i=1;i<=o;i++){
		u[i]=read();ch1[i]=getchar()-'A';v[i]=read();ch2[i]=getchar()-'A';
		//cout<<u[i]<<' '<<ch1[i]<<' '<<v[i]<<' '<<ch2[i]<<endl;
	}
	int T=1<<pos[0];
	for (int k=0;k<T;k++){
	//	cout<<k<<endl;
		for (int i=1;i<=pos[0];i++){ 
			w[pos[i]][0]=((1<<(i-1))&k)>0;
			//w[pos[i]][0]=0;
			w[pos[i]][1]=1+(((1<<(i-1))&k)>0);
		//	cout<<i<<' '<<w[pos[i]][0]<<' '<<w[pos[i]][1]<<endl; 
		}
		cnt=n*2;
		for (int i=1;i<=cnt;i++) nex[i]=0;
		int flag=0;
		for (int i=1;i<=o;i++){
		//	if (u[i]==v[i] && ch1[i]==ch2[i]) continue;
//			if (u[i]==38) cout<<u[i]<<' '<<ch1[i]<<' '<<v[i]<<' '<<ch2[i]<<endl;
			int uu=0, vv=0;
			if (w[u[i]][0]==ch1[i]) uu=0;
			else
				if (w[u[i]][1]==ch1[i]) uu=1;
				else flag=1;
			if (flag) { flag=0; continue;}
			if (w[v[i]][0]==ch2[i]) vv=0;
			else
				if (w[v[i]][1]==ch2[i]) vv=1;
				else flag=1;
			//if (flag && u[i]==v[i]) flag=0, vv=uu^1;
			if (flag){
				flag=0;
/*				add(u[i]+uu*n,v[i]);
				add(u[i]+uu*n,v[i]+n);
				add(v[i],u[i]+(uu^1)*n);
				add(v[i]+n,u[i]+(uu^1)*n);*/
				add(u[i]+uu*n,u[i]+(uu^1)*n);
				//cout<<u[i]+uu*n<<' '<<u[i]+(uu^1)*n<<endl;
				continue;
			}
//			cout<<u[i]+uu*n<<' '<<v[i]+vv*n<<' '<<v[i]+(vv^1)*n<<' '<<u[i]+(uu^1)*n<<endl;
			add(u[i]+uu*n,v[i]+vv*n);
			add(v[i]+(vv^1)*n,u[i]+(uu^1)*n);
		}
/*		for (int i=1;i<=2*n;i++)
			for (int j=1;j<=2*n;j++)
				if (i!=j && i+n!=j && i!=j+n && a[i][j]) cout<<i<<' '<<j<<endl;*/
		ct=cnt=0;
		for (int i=1;i<=n*2;i++) dfn[i]=low[i]=0;
		for (int i=1;i<=n*2;i++)
			if (!dfn[i]) tarjan(i);
		for (int i=1;i<=n;i++)
				if (co[i]==co[i+n]){
					flag=1;
					break;
				}
		if (flag) continue;
		int scc=ct;
		for (int i=1;i<=scc;i++) nexx[i]=d[i]=tag[i]=0; 
		for (int i=1;i<=n*2;i++)
			for (int j=nex[i];j;j=nex[j]){
				int v=nu[j];
				if (co[i]==co[v]) continue;
				nexx[++ct]=nexx[co[v]];nexx[co[v]]=ct;nuu[ct]=co[i];
				d[co[i]]++;
			}
		l[0]=0;
		for (int i=1;i<=scc;i++)
			if (!d[i]) l[++l[0]]=i;
		for (int i=1;i<=n;i++){
			rev[co[i]]=co[i+n],
			rev[co[i+n]]=co[i];
//			cout<<co[i]<<' '<<co[i+n]<<' '<<rev[co[i]]<<' '<<rev[co[i+n]]<<endl;
		}
//		cout<<"lyk"<<endl;
		for (int i=1;i<=l[0];i++){
			int u=l[i];
			if (tag[u]) continue;
			tag[u]=1;
			tag[rev[u]]=-1;
/*			q[q[0]=1]=rev[u];
			for (int e=1;e<=q[0];e++)
				for (int j=nexx[q[e]];j;j=nexx[j])
					if (!tag[nuu[j]]) tag[nuu[j]]=-1, q[++q[0]]=nuu[j];*/
			for (int j=nexx[u];j;j=nexx[j])
				if (!--d[nuu[j]]) l[++l[0]]=nuu[j];
		}
//		cout<<co[94]<<' '<<co[194]<<' '<<co[138]<<' '<<co[38]<<endl;
/*		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (co[i]==26 && co[j]==29 && co[i+n]==co[j+n])
					cout<<i<<' '<<j<<' '<<w[i][0]<<' '<<w[i][1]<<' '<<a[i][j]<<' '<<a[j][i]<<' '<<a[i+n][j+n]<<' '<<a[j+n][i+n]<<endl;
*/
//		if (!flag) cout<<"Accepted"<<endl;
//		cout<<flag<<endl;
		for (int i=1;i<=n;i++) printf("%c", w[i][tag[co[i]]<=0]+'A');
		puts("");
		ans=1;
		break;
	}
	if (!ans) cout<<"-1"<<endl;
	return 0;
}
