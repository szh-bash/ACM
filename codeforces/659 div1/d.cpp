#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
#define N 300
int n, m, a[N][N], row[N], col[N], s, ans[N][N];
int r[N], c[N], tag[N];
int r_flag[N], r_le[N], r_ri[N];
int c_flag[N], c_le[N], c_ri[N];
void upd(int x, int y){
	cout<<s<<' '<<x<<' '<<y<<endl;
	ans[x][y]=s;
	if (!r_flag[x]) r_le[x]=r_ri[x]=y, r_flag[x]=1;
	else r_le[x]=min(r_le[x],y), r_ri[x]=max(r_ri[x],y);
	if (!c_flag[y]) c_le[y]=c_ri[y]=x, c_flag[y]=1;
	else c_le[y]=min(c_le[y],x), c_ri[y]=max(c_ri[y],x);
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=read(),
			row[i]=max(row[i], a[i][j]),
			col[j]=max(col[j], a[i][j]);
	for (s=n*m;s;s--){
		r[0]=c[0]=0;
		int tr=0, tc=0;
		for (int i=1;i<=n;i++)
			if (row[i]==s) tr=i;
			else if (row[i]>s) r[++r[0]]=i;
		for (int i=1;i<=m;i++)
			if (col[i]==s) tc=i;
			else if (col[i]>s) c[++c[0]]=i;
		if (tr) r[0]=1, r[1]=tr;
		if (tc) c[0]=1, c[1]=tc;
		for (int i=1;i<=m;i++) tag[i]=0;
		for (int i=1;i<=c[0];i++) tag[c[i]]=1;
		int flag=0;
		for (int i=1;i<=r[0];i++){
			if (!r_flag[r[i]]){
				for (int j=1;j<=c[0];j++){
					int y=c[j];
					if (!c_flag[y] || c_le[y]-1==r[i] || c_ri[y]+1==r[i]){
						flag=1;
						upd(r[i],y);
						break;
					}
				}
			}
			else{
				int le=r_le[r[i]]-1;
				int ri=r_ri[r[i]]+1;
				if (tag[le] && (!c_flag[le] || c_le[le]-1==r[i] || c_ri[le]+1==r[i])){
					flag=1;
					upd(r[i],le);
				}
				else if (tag[ri] && (!c_flag[ri] || c_le[ri]-1==r[i] || c_ri[ri]+1==r[i])){
					flag=1;
					upd(r[i],ri);
				}
			}
			if (flag) break;
		}
		if (!flag) {
			puts("-1");
			return 0;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) printf("%d%s", ans[i][j], (j==m?"\n":" "));
	return 0;
}
