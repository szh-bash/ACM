#include<bits/stdc++.h>
using namespace std;
const int maxn=5009;
const int lim=5000;
const int inf=1e9;

int n;
int sum;
bitset<maxn>f[2][maxn];

int calc(int x,int y,int z){
	return max(max(x,y),z)-min(min(x,y),z);
}

int a,b,c;
int q[maxn];

int p[maxn];
int vis[maxn];
int g[409][maxn]; 
vector<int>A,B,C;

vector<int>D;
int cmp(int i,int j){
	return q[i]>q[j];
}
int find(int t){
	D.clear();
	int nn=0;
	for(int i=1;i<=n;++i){
		if(!vis[i])p[++nn]=i;
	}
	if(rand()%2)sort(p+1,p+1+nn,cmp);
	if(rand()%2)random_shuffle(p+1,p+1+nn);
	
	memset(g,0,sizeof(g));g[0][0]=1;
	for(int i=1;i<=nn;++i){
		for(int j=0;j<q[p[i]];++j)g[i][j]=g[i-1][j];
		for(int j=q[p[i]];j<=lim;++j){
			g[i][j]=g[i-1][j]|g[i-1][j-q[p[i]]];
		}
	}
	if(!g[nn][t])return 0;
	int k=t;
	for(int i=nn;i>=1;--i){
		if(g[i-1][k-q[p[i]]]){
			k-=q[p[i]];D.push_back(p[i]);vis[p[i]]=1;
		}
	}
	return 1;
}
int check(){
	A.clear();B.clear();C.clear();
	for(int i=1;i<=n;++i)vis[i]=0;
	if(!find(a))return 0;
	A=D;
	if(!find(b))return 0;
	B=D;
	if(!find(c))return 0;
	C=D;
	return 1;
}
int main(){
	srand(time(0));
	scanf("%d",&n);
	f[0][0].set(0,1);
	for(int i=1;i<=n;++i){
		int x=(i&1)^1,y=i&1;
		for(int j=0;j<=lim;++j)f[y][j].reset();
		int t;scanf("%d",&t);
//		int t=rand()%30;
		sum+=t;q[i]=t;
		for(int j=0;j<=lim;++j){
			if(j+t<=lim)f[y][j+t]|=f[x][j];
			f[y][j]|=(f[x][j]<<t);
			f[y][j]|=f[x][j];
		}
	}
	int ans=inf;
	for(int i=0;i<=lim;++i){
		for(int j=0;j<=lim;++j){
			if(f[n&1][i][j]==1){
				int tmp=calc(i,j,sum-i-j);
				if(tmp<ans){
					ans=tmp;a=i;b=j;c=sum-i-j;
				}
			}
		}
	}
	printf("%d\n",ans);
	for(;;){
		if(check())break;
	}
	printf("%d ",A.size());
	for(int i=0;i<A.size();++i)printf("%d ",A[i]);
	printf("\n");
	
	printf("%d ",B.size());
	for(int i=0;i<B.size();++i)printf("%d ",B[i]);
	printf("\n");
	
	printf("%d ",C.size());
	for(int i=0;i<C.size();++i)printf("%d ",C[i]);
	printf("\n");
	return 0;
}
