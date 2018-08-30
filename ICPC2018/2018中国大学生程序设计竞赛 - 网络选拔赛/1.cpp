#include <bits/stdc++.h>
#define N 100100
#define LL long long
#define mp make_pair
using namespace std;

multiset < pair <int , int > > a;
LL v[N];
int n;

void work()
{
    LL ans=0,sum; a.clear();
    scanf("%d",&n); sum=n;
    for (int i=1;i<=n;i++) scanf("%d",&v[i]),ans+=v[i];
    for (int i=1;i<=n;i++)
    {
        a.insert(mp(v[i],-i));
        pair<int,int> tmp=*a.begin();
        ans-=tmp.first;
        a.erase(a.begin());
        if (tmp.second>0) sum++;
        else  {sum--; a.insert(mp(tmp.first,-tmp.second));}
    }
    cout<<ans<<' '<<sum<<endl;
}

int main()
{
    int cas; scanf("%d",&cas);
    for (int i=1;i<=cas;i++) work();
}
