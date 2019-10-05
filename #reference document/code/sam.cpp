#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define C 26
#define N 2000005
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
class Sam{
	public:
		int n, cnt, last;
		int maxlen[N], minlen[N];
		int link[N], trans[N][C];
		int in[N], size[N], q[N];
		int f[N];
		friend void printi(int x);
		void clear();
		void build(char *s);
		void extend(int ch);
		ll subst_diff();
		void get_size();
		ll get_sum();
		void solve();
};
void Sam::clear(){
	last=cnt=1;
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
//	for (;'a'<=s[n] && s[n]<='z';n++);
	n=strlen(s);
	for (int i=0;i<n;++i) extend(s[i]-'a');
	for (int i=1;i<=cnt;++i) minlen[i]=maxlen[link[i]]+1;
//	get_size();
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
ll Sam::get_sum(){
}
void Sam::solve(){
	printll(get_sum());
	printf("%s", output);
}
Sam sam;
char st[N];
int main(){
	for (int _read();_;_--){
		scanf("%s", st);
		//fread(st,1,N/2,stdin);
		sam.build(st);
		sam.solve(); 
	}
	return 0;
}

