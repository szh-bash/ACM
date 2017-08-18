#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define pp 1048575
using namespace std;
long long x;
int a[500], q[500];
int main(){
	int n;
	memset(q,1,sizeof(q));
	for (int i=0;i<=pp;i++){
		long long v=i;
		for (int j=1;j<70;j++){
			int tot=0;
			for (int k=0;k<20;k++)
				if (v & (1<<k)) tot++;
			q[j]=q[j]& tot;
			v=(v*487237+1011807)%pp;
		}
	}
	for (int i=1;i<=70;i++) if (q[i]) cout<<i<<endl;
	int ans=n;
	while (n!=-1){
		int tot=0;
			for (int k=0;k<20;k++)
				if (x & (1<<k)) tot++;
		if (tot%2) {
			if (n>200) cout<<1<<endl;
			else
				if (n*2<=200) cout<<n<<endl;
					else cout<<(200-n)<<endl;
		}
		else{
			if (n>200) cout<<n-200<<endl;else cout<<1<<endl;
		}
		x=(x*487237+1011807)%pp;
		cin>>n;
	}
	return 0;
}
