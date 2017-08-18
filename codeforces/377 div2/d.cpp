#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[110000], d[110000], b[110000], f[110000];
bool cmp(int x, int y){return f[x]<f[y];}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) scanf("%d", &d[i]);
	for (int i=1;i<=m;i++) scanf("%d", &a[i]);
	int le=0, ri=n+1, mid, flag, tot;
	while (le<ri-1){
		mid=le+ri>>1;
		memset(f,0,sizeof(f));
		for (int i=1;i<=mid;i++)
			f[d[i]]=i;
		for (int i=1;i<=m;i++) b[i]=i;
		sort(b+1,b+1+m,cmp);
		flag=1;
		tot=0;
		for (int i=1;i<=m;i++){
			tot+=a[b[i]]+1;
			if (tot>f[b[i]]){
				flag=0;
				break;
			}
		}
		if (flag) ri=mid;else le=mid;
	}
	if (ri==n+1) cout<<-1<<endl;
	else cout<<ri<<endl;
	return 0;
}
