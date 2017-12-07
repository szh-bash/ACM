#include<cstdio>
#include<cstring>
#include<algorithm>
int c,g,i,j,k,a[30],x,con=10000,v;long long min,max,b[2][20000];
int main(){
    for(scanf("%d%d",&c,&g),i=1;i<=c;i++)scanf("%d",&a[i]);
    std::sort(a+1,a+1+c);
    for(scanf("%d",&x),i=1;i<=c;i++)b[0][a[i]*x+con]=1;
    for(min=a[1]*x,max=a[c]*x,j=1;j<g;j++){
        memset(b[j&1],0,sizeof(b[j&1]));
        for(scanf("%d",&x),i=1;i<=c;i++)
        for(v=x*a[i],k=min;k<=max;k++)
        b[j&1][k+v+con]+=b[~j&1][k+con];
        min+=a[1]*x,max+=a[c]*x;
    }
    printf("%lld\n",b[~j&1][con]);
}
