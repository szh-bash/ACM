#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int cnt, q, f[9100000], le[9100000], ri[9100000];
int main(){
	scanf("%d", &q);
	getchar();
	cnt=1;
	int t=1;
	for (int i=29;i>=0;i--) f[t]=1, le[t]=++cnt, t=cnt;
	f[cnt]=1;
	for (int i=1;i<=q;i++){
		char ch;
		int x, t=1;
		scanf("%c %d", &ch, &x);getchar();
		//cout<<ch<<' '<<x<<' '<<i<<endl;
		if (ch=='+'){
			f[t]++;
			for (int j=29;j>=0;j--){
				int v=(1<<j)&x;
				if (v){
					if (!ri[t]) ri[t]=++cnt;
					t=ri[t];
				}
				else{
					if (!le[t]) le[t]=++cnt;
					t=le[t];
				}
				f[t]++;
			}
		}
		if (ch=='-'){
			f[t]--;
			for (int j=29;j>=0;j--){
				int v=(1<<j)&x;
				if (v) t=ri[t]; else t=le[t];
				f[t]--;
			}
		}
		if (ch=='?'){
			int ans=0;
			for (int j=29;j>=0;j--){
				int v=(1<<j)&x;
				if (v){
					if (le[t] && f[le[t]]) ans+=(1<<j), t=le[t];
					else t=ri[t];
				}
				else{
					if (ri[t] && f[ri[t]]) ans+=(1<<j), t=ri[t];
					else t=le[t];
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
