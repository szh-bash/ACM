#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m, p[1010], py[1010];
char a[1010][1010];
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin>>n>>m;getchar();
    int tot=0, tx=1, ty=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            a[i][j]=getchar();
            if (a[i][j]=='*') p[i]++, py[i]=j, tot++, tx=i, ty=j;
        }
        getchar();
    }
    if (tot<=1){
                cout<<"YES"<<endl;
                cout<<tx<<' '<<ty<<endl;
                return 0;
                }
    int f1=0;
    for (int i=1;i<=n;i++){
        int f2=0, tmp=0;
        for (int j=1;j<=n;j++){
            if (j==i) continue;
            if (p[j]>1){f2=1;break;}
            if (!tmp) tmp=py[j];
                else
                    if (tmp!=py[j] && p[j]==1) {f2=1;break;}
        }
        if (f2) continue;
        if (!tmp) tmp=1;
        cout<<"YES"<<endl;
        cout<<i<<' '<<tmp<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}
