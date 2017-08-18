#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int fa[1000];
int father(int x){return fa[x]==x?x:fa[x]=father(fa[x]);}
int main(){
	srand(unsigned(time(NULL)));
	freopen("1.in","w",stdout);
	int T=1, n=50, m=2;
	while (T--){
		cout<<n<<endl;
		int l=rand()%n+1, r=rand()%n+1;
		cout<<min(l,r)<<' '<<max(l,r)<<endl;
		for (int i=1;i<=n;i++) fa[i]=i;
		for (int i=1;i<n;i++){
			while (1){
				int u=rand()%n+1, v=rand()%n+1, w=rand()%10;
				while (u==v) v=rand()%n+1;
				if (father(u)!=father(v)){
					cout<<u<<' '<<v<<' '<<w<<endl;
					fa[fa[u]]=fa[v];
					break;
				}
			}
		}
	}
	return 0;
}
