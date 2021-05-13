#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;
#define M 25
#define N 50005
int m=20;
int n=50000;
int a[M][M], f[N];
int dx[]={-1,+1,0,0};
int dy[]={0,0,-1,+1};
void set_map(){
    // int i=10, j=1;
    // int up=2, down=8, le=2, ri=10;
    int i=20, j=1;
    int up=1, down=18, le=2, ri=20;
    while(up<=down || le<=ri){
        for (;j<ri;j++)
            a[i][j]=1;
        for (;i>up;i--)
            a[i][j]=1;
        for (;j>le;j--)
            a[i][j]=1;
        for (;i<down;i++)
            a[i][j]=1;
        a[i][j]=1;
        up+=2, down-=2, le+=2, ri-=2;
    }
}
void set_map1(){
    for (int i=1;i<=m;i++)
        if (i&1)
            for(int j=1;j<=m;j++)
                a[i][j]=1;
        else
            a[i][1*((i/2)&1)+m*(((i/2)&1)^1)]=1;
}
void set_map2(){
    for (int i=1;i<=m;i++)
        if (i&1)
            for(int j=1;j<=m-2;j++)
                a[i][j]=1;
        else
            a[i][1*((i/2)&1)+(m-2)*(((i/2)&1)^1)]=1;
    for (int i=1;i<=m;i++)
        a[i][m]=1;
    a[1][m-1]=1;
}
void set_map3(){
    for (int i=1;i<m-1;i++)
        if (i&1)
            for(int j=1;j<=m;j++)
                a[i][j]=1;
        else
            a[i][1*((i/2)&1)+m*(((i/2)&1)^1)]=1;
    for (int j=1;j<=m;j++)
        if (j&1)
            a[m][j]=a[m-1][j]=1;
        else a[m][j]=1;
    // for (int j=4;j<=m;j++)
    //     if ((j&1)==0)
    //         a[m-2][j]=1;
}
void set_map4(){
    for (int i=1;i<m-3;i++)
        if (i&1)
            for(int j=1;j<=m;j++)
                a[i][j]=1;
        else
            a[i][1*((i/2)&1)+m*(((i/2)&1)^1)]=1;
    for (int j=1;j<=m;j++)
        if ((j&1)==0)
            for (int k=1;k<=4;k++)
                a[m-k+1][j]=1;
        else a[m][j]=1;
    
    // for (int i=1;i<=m;i++)
    //     for (int j=1;j<=m/2;j++)
    //         swap(a[i][j], a[i][m-j+1]);
    for (int i=1;i<=m/2;i++)
        for (int j=1;j<=m;j++)
            swap(a[i][j], a[m-i+1][j]);
}
void set_map5(){
    for (int i=1;i<m-1;i++)
        if (i&1)
            for(int j=1;j<=m;j++)
                a[i][j]=1;
        else
            a[i][1*((i/2)&1)+m*(((i/2)&1)^1)]=1;
    for (int j=1;j<=m;j++)
        if ((j&1))
            for (int k=1;k<=2;k++)
                a[m-k+1][j]=1;
        else a[m][j]=1;
    
    // for (int i=1;i<=m;i++)
    //     for (int j=1;j<=m/2;j++)
    //         swap(a[i][j], a[i][m-j+1]);
    for (int i=1;i<=m/2;i++)
        for (int j=1;j<=m;j++)
            swap(a[i][j], a[m-i+1][j]);
    for (int j=0;j<m/4+1;j++)
        a[2][m-j*2]=1,
        a[2][m-j*2-1]=0;
}
void get(int &x, int &y){
    for (int j=1;j<=n;j++)
        if (a[x+dx[f[j]]][y+dy[f[j]]])
            x+=dx[f[j]],
            y+=dy[f[j]];
}
int check(){
    int sx=-1, sy=-1;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]){
                int u=i, v=j;
                get(u,v);
                if (sx<0)
                    sx=u,
                    sy=v;
                else
                    if (sx!=u || sy!=v){
                        return 1;
                    }
            }
    // cout<<sx<<' '<<sy<<endl;
    return 0;
}
void print(){
    for (int i=1;i<m+1;i++){
        for (int j=1;j<m+1;j++) printf("%d",a[i][j]);
        puts("");
    }
}
int main(){
    // 随机数种子
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937_64 rand_num(seed);	 // 大随机数
    cout<<20<<' '<<20<<endl;
    set_map5();
    print();
    // return 0;
    int T=100;
    double ans=0;
    int ansT=0;
    for (int t=1;t<=T;t++){
        for (int j=1;j<=n;j++) f[j]=rand_num()%4;
        int res = check();
        printf("%d: %d\n", t, res);
        ans+=res;
        ansT+=res;
    }
    printf("%d/%d\n", ansT, T);
    cout<<ans/T<<endl;
    return 0;
}
// 11111111111111111111
// 10101010010101010101
// 10000000000000000000
// 11111111111111111111
// 00000000000000000001
// 11111111111111111111
// 10000000000000000000
// 11111111111111111111
// 00000000000000000001
// 11111111111111111111
// 10000000000000000000
// 11111111111111111111
// 00000000000000000001
// 11111111111111111111
// 10000000000000000000
// 11111111111111111111
// 00000000000000000001
// 11111111111111111111
// 10000000000000000000
// 11111111111111111111