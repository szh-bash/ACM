#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
    scanf("%d", &T);
    while (T){
          T--;
          scanf("%d%d%d", &a, &b, &d);
    }
    return 0;
}
#include <algorithm>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;i++)
const int maxn=50000+10;
using namespace std;
int P[maxn]={};
int get(int i){ 
    int s=1; 
    for(int x=2;x*x<=i;x++)
            if(i%x==0) { 
                       i/=x;if(i%x==0)return 0; 
                       s*=-1; 
                       } 
            if(i>1)s*=-1; 
            return s;
    }
int main(){ 
    for(int i=1;i<=maxn;i++)P[i]=P[i-1]+get(i); 
    int a,b,k,n;scanf("%d",&n); 
    rep(i,n) { 
             scanf("%d%d%d",&a,&b,&k);
             a/=k;b/=k; 
             if(a>b)swap(a,b); 
             int ans=0; 
             for(int t=1;t<=a;t++) { 
                     int m=min(a/(a/t),b/(b/t))-t; 
                     ans+=(P[t+m]-P[t-1])*(a/t)*(b/t); 
                     t+=m; 
             } 
    printf("%d\n",ans); 
    }
    return 0;
}
