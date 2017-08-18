#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m, k;
int main(){
    freopen("p1537.in","w",stdout);
    srand(time(NULL));
    n=rand()%5+1;m=rand()%5+1;k=rand()% min(6,(n*m))+1;
    cout<<n<<' '<<m<<' '<<k<<endl;
    for (int i=1;i<=k;i++)
        cout<<rand()%n+1<<' '<<rand()%m+1<<' '<<rand()%10+1<<endl;
    return 0;
}
