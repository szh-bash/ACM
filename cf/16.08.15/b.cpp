#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct zsm{
    long long d;
    int c;
}b[30];
int a[100010][30], mo=1e9+7, n, sum, c[30];
char s[100010];
bool cmp(zsm x,zsm y){return x.d<y.d;}
int main(){
    while(scanf("%d ",&n)!=EOF){
        sum++;
        int ma=0;
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for(int i=0;i<26;i++) b[i].d=0, b[i].c=i;
        for(int k=1;k<=n;k++){
            scanf("%s",s);
            int l=strlen(s);
            if (l>1) c[s[0]-'a']=1;
            ma = max(ma,l);
            for(int i=0;i<l;i++) a[l-i][s[i]-'a']++;
        }
        for(int i=ma;i;i--)
            for(int j=0;j<26;j++)
                b[j].d = (b[j].d*26+a[i][j])%mo;
        sort(b,b+26,cmp);
        int t, j=25;
        for(int i=0;i<26;i++)
            if(!c[b[i].c]){t=i;break;}
        long long ans=0;
        for(int i=25;i>=0;i--)
        if (t!=i){
            ans = (ans+b[i].d*j)%mo;
            j--;
        }
        cout<<"Case #"<<sum<<": "<<ans<<endl;
    }
    return 0;
}
