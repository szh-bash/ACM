#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 2000000
int flag[N];
int main(){
    int cnt=0;
    int zs=0;
    for (int i=2;i<N && zs<100000;i++)
        if (!flag[i]){
            zs++;
            for (int j=2;j*i<N;j++)
                flag[i*j]=1,
                cnt++;
        }
    cout<<cnt<<endl;
    return 0;
}