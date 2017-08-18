#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, k, ans=-10000000, f[300], a[300], s[300];
int main(){
	scanf("%d%d", &n, &k);
	for (int i=1;i<=n;i++) scanf("%d", &a[i]), s[i]=s[i-1]+a[i];
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++){
			int q=min(j-i+1,n-j+i-1), tp=s[j]-s[i-1];q=min(q,k);
			memset(f,0,sizeof(f));
			for (int l=i;l<=j;l++) f[l]=1;
			for (int w=1;w<=q;w++){
				int fx=-10000000, fn=10000000, p1, p2;
				for (int l=i;l<=j;l++)
					if (a[l]<fn && f[l]==1) fn=a[l], p1=l;
				for (int l=1;l<=n;l++)
					if (!f[l] && a[l]>fx) fx=a[l], p2=l;
				//if (i==2 && j==9)
				//cout<<fx<<' '<<fn<<' '<<p1<<' '<<p2<<' '<<w<<' '<<q<<endl;
				if (fx>fn) f[p1]=f[p2]=-1;else break;
				tp+=fx-fn;
			}
			ans=max(ans,tp);
		}
	cout<<ans<<endl;
	return 0;
}
