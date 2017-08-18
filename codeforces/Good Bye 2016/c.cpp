#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define INF 99999999
using namespace std;
int n, c[200100], d[200100], p, ma, mi, d1, d2, div1, div2, flag;
int main(){
	cin>>n;
	ma=div2=-INF;
	mi=div1=INF;
	flag=1;
	for (int i=1;i<=n;i++) scanf("%d%d", &c[i], &d[i]);
	for (int i=0;i<=n;i++){
		p+=c[i];
		if (i==n) break;
		d[i]=d[i+1];
		if (p>ma) ma=p, d1=d[i];
		if (p<mi) mi=p, d2=d[i];
		if (d[i]==1) div1=min(div1,p);
		else div2=max(div2,p);
		if (div2>=div1){
			flag=0;
			break;
		}
	}
	if (!flag) cout<<"Impossible"<<endl;
	else 
		if (d2==1) cout<<"Infinity"<<endl;
		else
			if (d1==2) cout<<(1899-(ma-p))<<endl;
			else cout<<(1899+p-div2)<<endl;
	return 0;
}
