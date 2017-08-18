#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m, q, v[1010][1010], a[1010][1010], x1, y1, x2, y2, h, w, t, f[2000000], c[1010][1010], d[1010][1010];
int re(){
	char ch=getchar();
	int p=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	//cout<<(1&(-1))<<endl;
	scanf("%d%d%d", &n, &m, &q);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) v[i][j]=re(), a[i][j]=(i-1)*m+j, f[a[i][j]]=v[i][j];
	for (int i=1;i<=q;i++){
		//scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &h, &w);
		x1=re();
		y1=re();
		x2=re();
		y2=re();
		w=re();
		h=re();
		int tx=x2-x1;
		int ty=y2-y1;
		for (int j=x1;j<=n;j+=j&(-j))
			for (int k=y1;k<=m;k+=k&(-k))
				c[j][k]+=tx, d[j][k]+=ty;
		for (int j=x1+w;j<=n;j+=j&(-j))
			for (int k=y1+h;k<=m;k+=k&(-k))
				c[j][k]+=tx, d[j][k]+=ty;
				
				
		for (int j=x1+w;j<=n;j+=j&(-j))
			for (int k=y1;k<=m;k+=k&(-k))
				c[j][k]-=tx, d[j][k]-=ty;
		for (int j=x1;j<=n;j+=j&(-j))
			for (int k=y1+h;k<=m;k+=k&(-k))
				c[j][k]-=tx, d[j][k]-=ty;
				
				
		for (int j=x2;j<=n;j+=j&(-j))
			for (int k=y2;k<=m;k+=k&(-k))
				c[j][k]-=tx, d[j][k]-=ty;
		for (int j=x2+w;j<=n;j+=j&(-j))
			for (int k=y2+h;k<=m;k+=k&(-k))
				c[j][k]-=tx, d[j][k]-=ty;
				
				
		for (int j=x2+w;j<=n;j+=j&(-j))
			for (int k=y2;k<=m;k+=k&(-k))
				c[j][k]+=tx, d[j][k]+=ty;
		for (int j=x2;j<=n;j+=j&(-j))
			for (int k=y2+h;k<=m;k+=k&(-k))
				c[j][k]+=tx, d[j][k]+=ty;
				
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int v=0, v2=0;
			for (int k=i;k;k-=k&(-k))
				for (int p=j;p;p-=p&(-p))
				 v+=c[k][p], v2+=d[k][p];
			//printf("%d ", f[a[i][j]+v*m+v2]);
			//cout<<v<<' '<<v2<<' '<<endl;
			cout<<a[i][j]+v*m+v2<<' ';
		}
		printf("\n");
	}
				
	}
/*	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) cout<<c[i][j]<<' ';
		cout<<endl;
	}*/
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int v=0, v2=0;
			for (int k=i;k;k-=k&(-k))
				for (int p=j;p;p-=p&(-p))
				 v+=c[k][p], v2+=d[k][p];
			//printf("%d ", f[a[i][j]+v*m+v2]);
			//cout<<v<<' '<<v2<<' '<<endl;
			cout<<a[i][j]+v*m+v2<<' ';
		}
		printf("\n");
	}
	return 0;
}
