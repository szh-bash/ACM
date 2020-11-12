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
#include <unordered_map>
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int main(){
    freopen("data.in","w",stdout);
    srand(unsigned(time(NULL)));
    for (int _=2;_;_--){
        int m=15, n=rand()%((1<<m)-1)+1;
        // int m=100000, n=100000;
        cout<<n<<' '<<m<<endl;
        for (int i=1;i<=n;i++) cout<<rand()%m+1<<' ';
        cout<<endl;
    }
    return 0;
}