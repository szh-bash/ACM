#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;  
int main()  
{  
//freopen("1.out","w",stdout);
    int n, a[60][60];  
    cin>>n;
    int tot=1;
    int i=1;
    int j=n/2+1, ti, tj;
    memset(a,0,sizeof(a));
    while (tot<=n*n){
    	//cout<<tot<<' '<<i<<' '<<j<<endl;
    	a[i][j]=tot;
    	tot++;
    	ti=i-1;
    	tj=j+1;
    	if (!ti) ti=n;
    	if (tj>n) tj=1;
    	if (a[ti][tj]) ti=i+1,tj=j;
    	if (ti>n) ti=1;
    	i=ti;j=tj;
    }
    for (int i=1;i<=n;i++){
    	for (int j=1;j<=n;j++) cout<<a[i][j]<<' ';
    	cout<<endl;
    }
    return 0;  
}  
