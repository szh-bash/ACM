#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define C 27
#define N 200005
#define MOD 1000000007
#define pii pair<int, int>
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') (ch=='-'?q=-1:0), ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int output_len;
char output[N*15];
void printi(int x){
	char s[20];
	int ct=0;
	while (x){
		s[ct++]=x%10+'0';
		x/=10;
	}
	for (int i=0;i<ct/2;++i) swap(s[i],s[ct-i-1]);
	s[ct]='\n';
	for (int i=0;i<=ct;i++) output[output_len++]=s[i];
}
void printll(ll x){
	char s[22];
	int ct=0;
	while (x){
		s[ct++]=x%10+'0';
		x/=10;
	}
	for (int i=0;i<ct/2;++i) swap(s[i],s[ct-i-1]);
	s[ct]='\n';
	for (int i=0;i<=ct;i++) output[output_len++]=s[i];
}
void add(int &a, int b){
	a+=b;
	if (a>=MOD) a-=MOD;
}
class Sam{
	public:
		int n, cnt, last;
		int maxlen[N], minlen[N];
		int link[N], trans[N][C];
		int in[N], size[N], q[N];
		int f[N];
		char st[N];
		int dp[N];
		int tot[N];
		int flag[N];
		int sg[N];
		ll g[N][C][2];
		friend void printi(int x);
		friend void add(int &a, int b);
		void clear();
		void build(char *s);
		void extend(int ch);
		ll subst_diff();
		void get_size();
		ll get_sum();
		void lcs();
		void get_sg(int p);
		void solve();
};
void Sam::clear(){
	last=cnt=1;
	memset(sg,-1,sizeof(sg));
//	memset(f,0,sizeof(f));
//	memset(q,0,sizeof(q));
//	memset(in,0,sizeof(in));
//	memset(size,0,sizeof(size));
//	memset(trans,0,sizeof(trans));
//	memset(minlen,0,sizeof(minlen));
//	memset(maxlen,0,sizeof(maxlen));
//	memset(link,0,sizeof(link));
}
void Sam::build(char *s){
	clear();
	n=strlen(s);
	for (int i=0;i<n;++i) extend(s[i]-'a');
	for (int i=1;i<=cnt;++i) minlen[i]=maxlen[link[i]]+1;
	get_size();
}
void Sam::extend(int ch){
	int cur=++cnt;
	int p=last;
	maxlen[cur]=maxlen[p]+1;
	size[cur]=1;
	for (;p && !trans[p][ch];p=link[p]) trans[p][ch]=cur;
	if (!p) link[cur]=1;
	else{
		int q=trans[p][ch];
		if (maxlen[q]==maxlen[p]+1) link[cur]=q;
		else{
			int y=++cnt;
			maxlen[y]=maxlen[p]+1;
			link[y]=link[q];
			size[y]=0;
			memcpy(trans[y], trans[q], sizeof(trans[y]));
			for (;p && trans[p][ch]==q;p=link[p]) trans[p][ch]=y;
			link[q]=link[cur]=y;
		}
	}
	last=cur;
}
void Sam::get_size(){
	int r=0;
	for (int i=1;i<=cnt;++i) in[link[i]]++;
	for (int i=1;i<=cnt;++i) if (!in[i]) q[++r]=i;
	for (int i=1;i<=r;++i){
		int u=q[i], v=link[u];
		size[v]+=size[u];
		if (!(--in[v])) q[++r]=v;
	}
}
ll Sam::subst_diff(){
	ll res=0;
	for (int i=1;i<=cnt;++i) res+=maxlen[i]-minlen[i]+1;
	return res;
}
void Sam::lcs(){
	int n=read();
	for (int i=1;i<=n;i++){
		scanf("%s", st+1);
		int len=strlen(st+1);
		int ans=0;
		for (int j=1, p=1, lcs=0;j<=2*len;j++){
			int ch=st[j>len?j-len:j]-'a';
			while (p>1 && !trans[p][ch]) p=link[p], lcs=maxlen[p];
			if (trans[p][ch]) p=trans[p][ch], ++lcs;
			else lcs=0;
			while (maxlen[link[p]]>=len) p=link[p], lcs=maxlen[p];
			if (lcs>=len && flag[p]!=i) flag[p]=i, ans+=size[p];
		}
		printf("%d\n", ans);
	}
}
void Sam::get_sg(int p){
	sg[p]=0;
	int flag[C];
	for (int j=0;j<C;j++) flag[j]=0;
	for (int j=0;j<C;j++){
		int v=trans[p][j];
		if (v){
			if (sg[v]==-1) get_sg(v);
			flag[sg[v]]=1;
			for (int k=0;k<C;k++)
				g[p][k][1]+=g[v][k][1];
		}
	}
	for (int j=0;j<C;j++)
		if (!flag[j]){
			sg[p]=j;
			break;
		}
	++g[p][sg[p]][1];
	ll sum=0;
	for (int j=0;j<C;j++) sum+=g[p][j][1];
	for (int j=0;j<C;j++) g[p][j][0]=sum-g[p][j][1];
}
void Sam::solve(){
}
Sam sam, sam0, sam1;
char st[N], sta[N], stb[N];
ll K;
void solve(){
	int len0=0, len1=0;
	ll sum=0;
	for (int j=0;j<C;j++){
		sum+=sam0.g[1][j][1]*sam1.g[1][j][0];
		if (sum>=K) break;
	}
	if (sum<K){
		puts("NO");
		return;
	}
	int s1=1, s2=1, ts1=0, ts2=0;
	while (s1!=ts1 && K>sam1.g[1][sam0.sg[s1]][0]){
		ts1=s1;
		K-=sam1.g[1][sam0.sg[s1]][0];
		for (int j=0;j<C;j++){
			int v=sam0.trans[s1][j];
			if (v){
				ll sum=0;
				for (int k=0;k<C;k++) sum+=sam0.g[v][k][1]*sam1.g[1][k][0];
				if (sum<K) K-=sum;
				else{
					sta[len0++]=j+'a';
					s1=v;
					break;
				}
			}
		}
	}
	int sg=sam0.sg[s1];
	while (s2!=ts2 && K>(sg!=sam1.sg[s2])){
		ts2=s2;
		K-=sg!=sam1.sg[s2];
		for (int j=0;j<C;j++){
			int v=sam1.trans[s2][j];
			if (v)
				if (sam1.g[v][sg][0]>=K){
					stb[len1++]=j+'a';
					s2=v;
					break;
				}
				else K-=sam1.g[v][sg][0];
		}
	}
	sta[len0]='\0';
	stb[len1]='\0';
	printf("%s\n%s\n", sta, stb);
}
int main(){
	cin>>K;
	scanf("%s", st);
	sam0.build(st);
	sam0.get_sg(1);
	scanf("%s", st);
	sam1.build(st);
	sam1.get_sg(1);
	solve();
	return 0;
}

