#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, len, px, cnt, head[100], o[100], next[100], va[100], l[100], p[100], f[100], fa[100];
long double  q[100], a[100][100], b[100][100];
int read(){
	char ch=getchar();
	int p=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void chen(){
	memset(b,0,sizeof(b));
	for (int i=0;i<=cnt;i++)
		for (int j=0;j<=cnt;j++)
			b[i][0]+=q[j]*a[j][i];
	for (int i=0;i<=cnt;i++)
		q[i]=b[i][0];
}
void zichen(){
	memset(b,0,sizeof(b));
	for (int i=0;i<=cnt;i++)
		for (int j=0;j<=cnt;j++)
			for (int k=0;k<=cnt;k++)
				b[i][j]+=a[i][k]*a[k][j];
	for (int i=0;i<=cnt;i++)
		for (int j=0;j<=cnt;j++)
			a[i][j]=b[i][j];
}
void power(int t){
	while (t){
		if (t&1) chen();
		zichen();
		t/=2;
	}
}
int main(){
	n=read();len=read();px=read();
	long double pi=(long double)1/px;
	for (int i=1;i<=n;i++){
		char s[20];
		scanf("%s", s);
		int l=strlen(s), k=0;
		for (int j=0;j<l;j++){
			int m=head[k];
			while (m){
				if (va[m]==s[j]-'a') break;
				m=next[m];
			}
			if (!m){
				next[++cnt]=head[k];
				head[k]=cnt;
				va[cnt]=s[j]-'a';
				k=cnt;
			}
			else k=m;
		}
		f[k]=1;
	}
	cnt++;
	int le=0, ri=1;
	while (le<ri){
		int u=l[++le];
		for (int j=head[u];j;j=next[j]) {l[++ri]=j;fa[j]=u;}
		if (fa[u]){
			int k=p[fa[u]];
			while (k>=0){
				int j=head[k];
				for (;j;j=next[j])
					if (va[j]==va[u]) break;
				if (j) {k=j;break;}
				if (!k) break;
				k=p[k];
			}
			p[u]=k;
			f[u]|=f[p[u]]; 
		}
		memset(o,0,sizeof(o));
		for (int v=u;v;v=p[v]){
			for (int j=head[v];j;j=next[j]){
				if (!f[j]) a[u][j]+=pi;else a[u][0]+=pi, a[u][cnt]+=pi;
				o[va[j]]++;
			}
		}
		for (int j=head[0];j;j=next[j]){
				if (!f[j]) a[u][j]+=pi;else a[u][0]+=pi, a[u][cnt]+=pi;
				o[va[j]]++;
			}
		for (int j=0;j<px;j++)
			if (!o[j]) a[u][0]+=pi;
	}
	a[cnt][cnt]=1;
	q[0]=1;
	power(len);
	cout<<q[cnt]<<' '<<a[0][cnt]<<endl;
	return 0;
}
