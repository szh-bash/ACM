#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define INF 2000000
using namespace std;
int n, k, u, v, vv, w, f[100010], ans[100010];
int read(){
	char ch=getchar();
	int p=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	n=read();
	v=read();
    for (int i=1;i<=n;i++){
    	w=read();
    	k=read();
        for (int j=0;j<=v-w;++j)
            f[j]=ans[j];
        for (;k;--k){
        	u=read();vv=read();
            for (int j=v-w;j>=u;--j)
                f[j]=max(f[j],f[j-u]+vv);
        }
        for (int j=w;j<=v;++j)
            ans[j]=max(ans[j],f[j-w]);
    }
    cout<<ans[v]<<endl;
    return 0;
}

