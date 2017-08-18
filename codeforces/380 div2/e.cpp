#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, s, ans, f[610000], a[610000], ma, tot;
int main(){
	cin>>n>>s;
	for (int i=1;i<=n;i++) scanf("%d", &a[i]), f[a[i]]++, ma=max(ma,a[i]);
	if (a[s]) ans++, f[0]++, tot++, f[a[s]]--;
	for (int i=1;i<=n;i++)
		if (i!=s && !a[i]){
			f[0]--;
			ans++;
		}
	for (int j=1;j<=ma;j++){
		tot+=f[j]==0;
		if (!f[j] && tot>ans){
			while (ma>=j && !f[ma]) ma--;
			if (ma>j) ans++, f[ma]--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
