#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
struct zsm{
	int a, b;
	long long c;
}l[40100];
int n;
long long ans;
bool cmp(zsm a, zsm b){return a.c>b.c;}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d%d%d",&l[i].a, &l[i].b, &l[i].c);
	sort(l+1,l+1+n,cmp);
	for (int i=1;i<=n;i++){
		int sum1=0, sum2=0, flag=1;
		for (int j=l[i].b;j;j--) sum1+=c[j];
		for (int j=l[i].a-1;j;j--) sum2+=c[j];
		if (sum1-sum2==l[i].b-l[i].a+1) continue;
		ans+=l[i].c*(l[i].b-l[i].a+1-(sum1+sum2));
		while (flag){
			int p, le=l[i].a-1, ri=l[i].b+1, mid;
			while (le<ri-1){
				mid=le+ri>>1;
				p=0;
				for (int j=mid;j;j--) p+=c[j];
				if (p-sum2==mid-l[i].a+1) le=mid;
					else ri=mid;
			}
			for (int j=r2;j<=n;j++)	
		}
	}
	return 0;
}
