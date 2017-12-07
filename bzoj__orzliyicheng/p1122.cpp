#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define REP(i,n) for( int i = 0; i<int(n); ++i)
#define FOR(i,a,b) for (int i = a ;i<=int(b); ++i)
using namespace std;
const int MAX=1100*1000;
const int inf=2*1000*1000*1000+100;
char input[MAX];
int height[MAX];
int kolejka[MAX][2];
int minimum[MAX];
int n,p,q,x,y,h=0,k,M,opt=inf,r,m,kol_pocz=0,kol_kon=0;
char ch;
int main(){
    scanf("%d %d %d %d %d\n",&n,&p,&q,&x,&y);
    fgets(input,MAX,stdin);
    height[0]=0;
    kol_pocz=1;
    kolejka[0][0]=0;
    kolejka[0][1]=0;
    REP(i,n){
        if (input[i]=='+') h++; else h--;
        while ((kol_pocz>kol_kon)&&(h<=kolejka[kol_pocz-1][0])) kol_pocz--;
        kolejka[kol_pocz][0]=h; kolejka[kol_pocz++][1]=i;
        height[i+1]=h;
    }
    FOR(i,n,2*n-1){
        if (input[i-n]=='+') h++; else h--;
        if (kolejka[kol_kon][1]<i+1-n) kol_kon++;
        while ((kol_pocz>kol_kon)&&(h<=kolejka[kol_pocz-1][0])) kol_pocz--;
        kolejka[kol_pocz][0]=h; kolejka[kol_pocz++][1]=i;
        minimum[i-n+1]=p+kolejka[kol_kon][0]-height[i-n+1];
    }
    FOR(i,1,n){
        M=(minimum[i]>0)?0:(-minimum[i]);
        M+=(M&1);
        if (q-p>height[n]+M) k=(q-p-height[n])>>1; else k=M+((height[n]-(q-p))>>1);
        r=y*(n-i)+x*k;
        if (r<opt) opt=r;
    }
    printf("%d\n",opt);
    return 0;
}
