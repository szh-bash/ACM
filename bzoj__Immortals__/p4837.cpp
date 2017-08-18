#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long ans, cnt, T, y, n, q, x1, a, b, p, head, tail;
int f[1100000], nex[1100000], pre[1100000];
int main(){
	cin>>T;
	while (T--){
		cin>>n>>q;
		cin>>x1>>a>>b>>p;
		memset(nex,0,sizeof(nex));
		memset(pre,0,sizeof(pre));
		memset(f,0,sizeof(f));
		head=tail=ans=x1;
		f[x1]=1;
		cnt=1;
		pre[x1]=nex[x1]=x1;
		y=x1;
		for (int i=2;i<=q;i++){
			x1=(a*x1+b)%p;
			if (f[x1]){
				if (head==x1) head=nex[head];
				pre[nex[x1]]=pre[x1];
				nex[pre[x1]]=nex[x1];
				nex[x1]=nex[tail];nex[tail]=x1;
				pre[x1]=tail;
				tail=x1;
				pre[head]=tail;
			}
			else{
				if (cnt==n){
					y-=head;
					f[head]=0;
					nex[tail]=x1;
					pre[x1]=tail;
					nex[x1]=head;
					pre[head]=x1;
					tail=x1;
					
					int hea=nex[head];
					nex[pre[head]]=nex[head];
					pre[nex[head]]=pre[head];
					head=hea;
				}
				else{
					pre[x1]=tail;
					nex[x1]=head;
					nex[tail]=x1;
					tail=x1;
					pre[head]=x1;
					cnt++;
				}
				y+=x1;
				f[x1]=1;
			}
			ans=(ans+y*i)%((unsigned long long)-1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
