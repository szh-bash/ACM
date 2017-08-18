#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N 225
inline int in(int x=0,char ch=getchar(),int v=1){
    while(ch!='-'&&(ch>'9'||ch<'0')) ch=getchar();if(ch=='-') v=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();return x*v;}
int sg[N][N];
int GetSG(int n,int m){
    if(sg[n][m]!=-1) return sg[n][m];
    bool b[N];memset(b,0,sizeof(b));
    for(int i=1;i<n;i++) b[GetSG(n-i,i)]=1;
    for(int i=1;i<m;i++) b[GetSG(i,m-i)]=1;
    for(int i=0;;i++) if(!b[i]) return sg[n][m]=i;
}
int main(){
//  freopen("std.out","w",stdout);
    int t,n,m,a,b,ans;memset(sg,-1,sizeof(sg));sg[1][1]=0,sg[2][1]=sg[1][2]=1;
    n=30,m=30;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++)
            printf("%d%c",GetSG(i,j)," \n"[j==m]);
    return 0;
}
