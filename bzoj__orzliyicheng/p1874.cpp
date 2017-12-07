#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int sum, sg[1011], a[1011], f[1011], n, m, ma, flag[1011];
void getsg(){
	for (int x=1;x<=ma;x++){
		for (int i=1;f[i]<=x && i<=m;i++)
			flag[sg[x-f[i]]]=x;
		for (int i=0;i<=ma;i++) 
			if (flag[i]!=x){
				sg[x]=i;
			 	break;
			}
	}
}
int main(){
	scanf("%d", &n);
	for (int i=1;i<=n;i++) scanf("%d", &a[i]), ma=max(ma,a[i]);
	scanf("%d", &m);
	for (int i=1;i<=m;i++) scanf("%d", &f[i]);
	ma+=10;
	getsg();
	for (int i=1;i<=n;i++) sum^=sg[a[i]];
	if (!sum){cout<<"NO"<<endl;return 0;}
	cout<<"YES"<<endl;
	for (int i=1;i<=n;i++){
		int tmp=sum^sg[a[i]];
		for (int j=1;f[j]<=a[i] && j<=m;j++)
			if (!(tmp^sg[a[i]-f[j]])){
				cout<<i<<' '<<f[j]<<endl;
				return 0;
			}
	}
	return 0;
}
