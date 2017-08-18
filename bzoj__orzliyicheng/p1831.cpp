#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1061109567;
int a[10005],da[10005][105],xi[10005][105],p[10005],f[10005][100],n,k,m=0,An=0;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(!~a[i]) p[++m]=i;
    }for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++) da[i][j]=da[i-1][j];
        if(~a[i-1]) for(int j=1;j<a[i-1];j++) da[i][j]++;
    }for(int i=n-1;i;i--){
        for(int j=1;j<=k;j++) xi[i][j]=xi[i+1][j];
        if(~a[i+1]) for(int j=a[i+1]+1;j<=k;j++) xi[i][j]++;
    }for(int i=1;i<=n;i++) if(~a[i]) An+=da[i][a[i]];
    memset(f,63,sizeof(f));
    for(int i=1;i<=k;i++) f[1][i]=da[p[1]][i]+xi[p[1]][i];
    for(int i=2;i<=m;i++) for(int j=1;j<=k;j++) for(int o=1;o<=j;o++)
        f[i][j]=min(f[i][j],f[i-1][o]+da[p[i]][j]+xi[p[i]][j]);
    int An2=inf;  for(int i=1;i<=k;i++) An2=min(An2,f[m][i]);
    An2=(An2==inf)?0:An2;
    printf("%d\n",An+An2); return 0;
}
