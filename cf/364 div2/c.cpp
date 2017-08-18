#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a[110000], f[1000], ans, tot;
int main(){
    cin>>n;getchar();
    for (int i=1;i<=n;i++){
        char ch=getchar();
        a[i]=ch-'0';
        if (!f[a[i]]) {tot++;f[a[i]]=1;}
    }
    memset(f,0,sizeof(f));
    ans=n;
    int j=1, sum=0;
    for (int i=1;i<=n;i++){
        if (!f[a[i]]){
                      sum++;
                      f[a[i]]++;
                      }
        else f[a[i]]++;
        if (sum==tot){
                      ans=min(ans,i-j+1);
                      while (sum==tot){
                            f[a[j]]--;
                            if (!f[a[j]]) {sum--;j++;break;}
                            else ans=min(ans,i-j);
                            j++;
                            }
                      }
        
    }
    cout<<ans<<endl;
    return 0;
}
