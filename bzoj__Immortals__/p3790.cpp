#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define INF 999999
#define N 500000
using namespace std;
int len, cnt, le, ri, p[N], f[N];
char s[N], ss[N];
struct qlz{
	int le, ri;
	bool operator <(const qlz v){
		return ri<v.ri;
	}
}l[N];
bool cmp(qlz a,qlz b){return a<b;}
void build(int t, int l, int r){
	if (l==r){
		f[t]=l?INF:0;
		return;
	}
	int mid=l+r>>1;
	build(t<<1,l,mid);
	build((t<<1)+1,mid+1,r);
	f[t]=min(f[t<<1],f[(t<<1)+1]);
}
int query(int t, int l, int r){
	if (le<=l && r<=ri) return f[t];
	int mid=l+r>>1, tmp=INF;
	if (le<=mid) tmp=query(t<<1,l,mid);
	if (ri>mid) tmp=min(tmp,query((t<<1)+1,mid+1,r));
	return tmp;
}
void update(int t,int l, int r, int v){
	if (l==r){
		f[t]=p[v];
		return;
	}
	int mid=l+r>>1;
	if (v<=mid) update(t<<1,l,mid,v);
	if (v>mid) update((t<<1)+1,mid+1,r,v);
	f[t]=min(f[t<<1],f[(t<<1)+1]);
}
int main(){
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	while (~scanf("%s", ss)){
		len=strlen(ss);
		for (int i=0;i<len;i++)
			s[i*2]='#', s[i*2+1]=ss[i];
		s[(len=len*2+1)-1]='#';
		cnt=0;
		int mr=0, pos=0;
		memset(p,0,sizeof(p));
		for (int i=0;i<len;i++){
			if (i>=mr) p[i]=1;
			else p[i]=min(mr-i+1,p[pos*2-i]);
			for (;i+p[i]<len && i>=p[i] && s[i+p[i]]==s[i-p[i]];++p[i]);
			if (i&1 || p[i]>1)
					l[++cnt].le=i-p[i]+2>>1, l[cnt].ri=i+p[i]-2>>1;
			if (i+p[i]-1>mr) {
				mr=i+p[i]-1;
				pos=i;
			}
		}
		len/=2;
		sort(l+1,l+1+cnt,cmp);
		build(1,0,len);
		p[0]=0;
		for (int i=1;i<=len;i++) p[i]=INF;

		for (int i=1;i<=cnt;i++){
			le=l[i].le, ri=l[i].ri;
			p[ri+1]=min(p[ri+1],query(1,0,len)+1);
			update(1,0,len,ri+1);
		}
		cout<<p[len]-1<<endl;
	}
	return 0;
}
