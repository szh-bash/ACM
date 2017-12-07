#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#define mo 100000009
using namespace std;
int pr[1000000],tot=0;
int bo[10000000]={0},g[10000000];
void sieve(int n){
    g[1]=1;
    for (int i=2;i<=n;i++){
        if (!bo[i])pr[++tot]=i,g[i]=1-i;
        for (int j=1;j<=tot && pr[j]*i<=n;j++){
            bo[i*pr[j]]=1;
            if(i%pr[j]==0){g[i*pr[j]]=g[i];break;}
            else g[i*pr[j]]=g[i]*(1-pr[j])%mo;
        }
    }
}
inline int su(int a,int b){
    return (((long long)a*(a+1)/2)%mo)*(((long long)b*(b+1)/2)%mo)%mo;
}
int main(){
    sieve(10000000);
    g[0]=0;for (int i=1;i<=10000000;i++)g[i]=(g[i-1]+1ll*g[i]*i)%mo;
    int tes;
    scanf("%d",&tes);
    while(tes--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        int nex;
        int ans=0;
        for (int i=1;i<=a;i=nex+1){
            nex=min(a/(a/i),b/(b/i));
            ans=(ans+(long long)su(a/i,b/i)*(g[nex]-g[i-1]))%mo;
        }
        if(ans<0)ans+=mo;
        printf("%d\n",ans);
    }
    return 0;
}

