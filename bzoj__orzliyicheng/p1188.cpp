#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int t,n, a[30], sg[30], ans;
int get_SG(int x){
	if (sg[x]!=-1) return sg[x];
	int mark[100];
	memset(mark,0,sizeof(mark));
	for (int i=x+1;i<=n;i++)
		for (int j=i;j<=n;j++)
			mark[get_SG(i)^get_SG(j)]=x;
	for (int i=0;;i++) if (mark[i]!=x) return sg[x]=i;
}
int main(){
	scanf("%d", &t);
	while (t){
		t--;
		memset(sg,-1,sizeof(sg));
		scanf("%d", &n);sg[n]=0;
		for (int i=1;i<=n;i++) scanf("%d", &a[i]), a[i]&=1;
		ans=0;
		for (int i=1;i<=n;i++) if (a[i]) ans^=get_SG(i);
		if (!ans){puts("-1 -1 -1");cout<<0<<endl;continue;}
		int tot=0;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j;k<=n;k++)
					if (!(ans^get_SG(i)^get_SG(j)^get_SG(k))){
						++tot;
						if (tot==1) printf("%d %d %d\n", i-1, j-1, k-1);
					}
		printf("%d\n", tot);
	}
	return 0;
}
