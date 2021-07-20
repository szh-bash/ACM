    #include <cstdio>
    #include <cstdlib>
    #include <iostream>
    #include <algorithm>
    using namespace std;
    #define T 500005
    int n, m, k, ans[T], nex[T*2], a[T];
    int read(){
        int p=0, q=1;
        char ch=getchar();
        while (ch<'0' || ch>'9') ch=getchar();
        while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
        return p;
    }
    int main(){
        n=read(), k=read(), m=read();
        for (int i=1;i<=m;i++){
            int u=read(), v=read();
        }
        int t=n*k;
        for (int i=1;i<=t;i++)
            a[i]=read();
        for (int i=t;i;i--) 
            nex[i+n]=nex[a[i]],
            nex[a[i]]=i+n;
        for (int i=1;i<=k;i++)
            for (int j=1;j<=n;j++)
                ans[nex[j]-n]=i,
                nex[j]=nex[nex[j]];
        for (int i=1;i<=t;i++) printf("%d%s", ans[i], i==t?"\n":" "); 
        return 0;
    }