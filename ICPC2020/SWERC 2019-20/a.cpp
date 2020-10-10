#include<bits/stdc++.h>
using namespace std;
const int maxn=1009;
const int inf=1e9;
 
int n,B;
 
int d[maxn][maxn];
int C[maxn],T;
 
int b[maxn][maxn];
 
int f[109][maxn];
 
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){
		x=_x;y=_y;
	}
	void input(){
		cin>>x>>y;
	}
	int length_up_round(){
		return ceil(sqrt(x*x+y*y));
	}
	bool operator == (const Point &rhs){
		return (x==rhs.x)&&(y==rhs.y);
	}
};
Point operator - (Point a,Point b){
	return Point(a.x-b.x,a.y-b.y);
}
Point p[maxn],ps,pt;
 
int g[maxn][maxn];
 
int main(){
	ps.input();pt.input();
	cin>>B;
	cin>>C[0];
	cin>>T;
	for(int i=1;i<=T;++i)cin>>C[i];
	cin>>n;p[n+1]=ps;p[n+2]=pt;
	
	
	for(int i=1;i<=n+2;++i){
		for(int j=1;j<=n+2;++j){
			if(i>n||j>n)g[i][j]=C[0];
			else if (i==j) g[i][j]=0;
			else g[i][j]=inf;
		}
	}
	for(int i=1;i<=n;++i){
		p[i].input();
		int l;cin>>l;
		while(l--){
			int j,t;cin>>j>>t;++j;
			if(C[t]<g[i][j])g[j][i]=g[i][j]=C[t];
		}
	}
	
	n+=2;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			d[i][j]=(p[i]-p[j]).length_up_round();
			if(g[i][j]==inf)b[i][j]=inf;
			else b[i][j]=d[i][j]*g[i][j];
		}
	}
	
	
	for (int i=0;i<=B;i++)
		for (int j=1;j<=n;j++) f[i][j]=inf;
	f[0][n-1]=0;
	for(int i=0;i<=B;++i){
		for(int j=1;j<=n;++j){
			if (i) f[i][j]=f[i-1][j];
			for(int k=1;k<=n;++k){
				if(d[j][k]>i)continue;
				f[i][j]=min(f[i][j],f[i-d[j][k]][k]+b[j][k]);
			}
		}
	}
	int ans=inf;
	for(int i=1;i<=n;++i){
		if(p[i]==p[n])ans=min(ans,f[B][i]);
	}
	if(ans==inf){
		cout<<-1<<endl;
	}else{
		cout<<ans<<endl;
	}
	return 0;
}
