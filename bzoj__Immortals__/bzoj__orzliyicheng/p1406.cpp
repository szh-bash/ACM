#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, flag=0;
int main(){
	scanf("%d", &n);
	for (int i=0;i<n-1;i++)
		if ((long long)i*(i+2)%n==0) cout<<i+1<<endl, flag=1;
	if (!flag) cout<<"None"<<endl;
	return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
using namespace std;
int n,a,b,x,p;
set<int> S;
int main()
{
    scanf("%d",&n);
    p=int(sqrt(n));
    for (a=1;a<=p;a++) if (n%a==0)
    {
        b=n/a;
        for (x=1;x<=n;x+=b)
            if ((x+1)%a==0)
                S.insert(x);
        for (x=b-1;x<=n;x+=b)
            if ((x-1)%a==0)
                S.insert(x);
    }
    while (!S.empty())
    {
        printf("%d\n",*S.begin());
        S.erase(S.begin());
    }
    return 0;
}
