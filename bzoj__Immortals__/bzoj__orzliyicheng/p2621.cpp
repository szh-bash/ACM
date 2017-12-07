#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
struct zsm{
	int a,b;
}f[1000000];
int n, w, a[100];
int main(){
	scanf("%d%d", &n, &w);
	for (int i=0;i<n;i++) scanf("%d", &a[i]);
	for (int i=1;i<(1<<n);i++){
		f[i].a=n;
		f[i].b=0;
		for (int j=0;j<n;j++)
			if (i & (1<<j))
				if (f[i^(1<<j)].b>=a[j] && f[i^(1<<j)].a<f[i].a){
					f[i].a=f[i^(1<<j)].a;
					f[i].b=f[i^(1<<j)].b-a[j];
				}
				else
					if(f[i^(1<<j)].b>=a[j] && f[i^(1<<j)].b-a[j]>f[i].b && f[i^(1<<j)].a==f[i].a){
						f[i].a=f[i^(1<<j)].a;
						f[i].b=f[i^(1<<j)].b-a[j];
					}
					else
						if (f[i^(1<<j)].b<a[j] && f[i^(1<<j)].a+1<f[i].a){
							f[i].a=f[i^(1<<j)].a+1;
							f[i].b=w+f[i^(1<<j)].b-a[j];
						}
						else
							if (f[i^(1<<j)].b<a[j] && f[i^(1<<j)].a+1==f[i].a && w+f[i^(1<<j)].b-a[j]>f[i].b){
								f[i].a=f[i^(1<<j)].a+1;
								f[i].b=w+f[i^(1<<j)].b-a[j];
							}
		//cout<<i<<' '<<f[i].a<<' '<<f[i].b<<endl;
	}
	cout<<f[(1<<n)-1].a<<endl;
	return 0;
}
