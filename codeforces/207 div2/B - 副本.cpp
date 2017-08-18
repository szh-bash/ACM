#include<cstdio>
#include<iostream>
using namespace std;
int p[5], c[5], n, m, f[900000];
int main()
{
    scanf("%d%d", &n, &m);
    int tmp, t;
    for (int i=1;i<=m;i++){
        scanf("%d%d%d", &c[1], &c[2], &c[3]);
        p[1]=1;p[2]=2;p[3]=3;
        if (!f[c[1]] && !f[c[2]] && !f[c[3]]){
                  f[c[1]]=1;f[c[2]]=2;f[c[3]]=3;
                  }
        else{
             if (f[c[1]]) t=1;
             if (f[c[2]]) t=2;
             if (f[c[3]]) t=3;
             tmp=p[t];p[t]=p[f[c[t]]];p[f[c[t]]]=tmp;
             f[c[1]]=p[1];
             f[c[2]]=p[2];
             f[c[3]]=p[3];
             }
             
    }
    for (int i=1;i<n;i++) printf("%d ", f[i]);
    cout<<f[n]<<endl;
    return 0;
}
