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
#define N 1000000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m, k, cnt, ct, num[N], flag[N], nex[N], nu[N], q[N], ans[N], x[N], y[N], d[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v, int no){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;num[cnt]=no;
}
int main(){
	cnt=n=read();m=read();k=read();
	for (int i=1;i<=m;i++){
		x[i]=read();y[i]=read();
		add(x[i], y[i], i);
		add(y[i], x[i], i);
		d[x[i]]++;
		d[y[i]]++;
	}
	for (int i=1;i<=n;i++)
		if (d[i]<k) q[++ct]=i, flag[i]=1;
	for (int i=1;i<=ct;i++)
		for (int j=nex[q[i]];j;j=nex[j])
			if (--d[nu[j]]<k && !flag[nu[j]]) q[++ct]=nu[j], flag[nu[j]]=1;
	for (int i=1;i<=n;i++) ans[m]+=flag[i]^1;
	for (int i=m;i>1;i--){
		ans[i-1]=ans[i];
		if (!flag[x[i]] && !flag[y[i]]){
			int tp=ct;
			if (--d[x[i]]<k) q[++ct]=x[i], flag[x[i]]=1, ans[i-1]--;
			if (--d[y[i]]<k) q[++ct]=y[i], flag[y[i]]=1, ans[i-1]--;
			//cout<<x[i]<<' '<<d[x[i]]<<' '<<y[i]<<' '<<d[y[i]]<<endl;
			for (int j=tp+1;j<=ct;j++)
				for (int p=nex[q[j]];p;p=nex[p])
					if (num[p]<i && --d[nu[p]]<k && !flag[nu[p]])
						q[++ct]=nu[p], flag[nu[p]]=1, ans[i-1]--;
		}
	}
	for (int i=1;i<=m;i++) printf("%d\n", ans[i]);
    return 0;
}
