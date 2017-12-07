#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 100010
#define INF (ll)1000000000*1000000000*2
typedef long long ll;
using namespace std;
char s0[100]="What are you doing at the end of the world? Are you busy? Will you save us?";
char s1[100]="What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
char ans[20];
int n, q;
ll k, f[N];
int main(){
	//cout<<s1<<endl;
	//cout<<strlen(s1)<<endl;
	f[0]=strlen(s0);
	for (int i=1;i<=N-5;i++)
		if (f[i-1]>=INF) f[i]=INF;
		else f[i]=f[i-1]*2+64+4;
	//for (int i=0;i<=100;i++) cout<<f[i]<<endl;
	cin>>q;
	for (int i=1;i<=q;i++){
		cin>>n>>k;
		if (f[n]<k){
			ans[i]='.';
			continue;
		}
		int le=0, ri=n;
		while (le<ri){
			int mid=le+ri>>1;
			if ((n-mid)*34+f[mid]>=k) ri=mid;else le=mid+1;
		}
		//cout<<le<<endl;
		if ((n-le)*34>=k){
			k=(k-1)%34+1;
			ans[i]=s1[k-1];
			continue;
		}
		k-=(n-le)*34;
		if (!le){
			ans[i]=s0[k-1];
			continue;
		}
		int flag=0;
		for (int j=le;j;j--)
			if (34>=k){
				ans[i]=s1[k-1];
				flag=1;
				break;
			}
			else
				if (34+f[j-1]>=k){
					k-=34;
				}
				else
					if (66+f[j-1]>=k){
						k-=34+f[j-1];
						ans[i]=s1[34+k-1];
						flag=1;
						break;
					}
					else
						if (66+2*f[j-1]>=k){
							k-=66+f[j-1];
						}
						else{
							k-=66+2*f[j-1];
							flag=1;
							ans[i]=s1[65+k];
							break;
						}
		if (!flag) ans[i]=s0[k-1];
	}
	for (int i=1;i<=q;i++) cout<<ans[i];cout<<endl;
	return 0;
}
