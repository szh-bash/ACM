#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
struct zsm{
       int u,v,w;
}l[10000004];
int n,a[200000],cnt=0,ma,fa[200000],num[200000];
long long ans=0;
bool f[1000005];
void bfs(int x)
{
     int b[7];
     int tmp=x;
     int len=0;
     while (x){
         len++;
         b[len]=x%10;
         x=x/10;
     }
     //cout<<ma<<' '<<cnt<<endl;
     b[0]=b[len];b[len+1]=b[1];
     for (int i=1;i<=len;i++)
       for (int j=1;j<=len;j++)
         if (i!=j){
             int q=0;
             for (int k=len;k>=1;k--)
               if (k==i) q=q*10+b[j];
               else if (k==j) q=q*10+b[i];
                    else q=q*10+b[k];
             if (f[q]==0){n++;a[n]=q;f[q]=1;}
             if ((q>0)&&(q!=tmp)){
                 cnt++;
                 l[cnt].u=q;l[cnt].v=tmp;l[cnt].w=((b[i]&b[j])+(b[i]^b[j]))*2;
             }
   //  cout<<ma<<' '<<cnt<<endl;
         }
     for (int i=1;i<=len+1;i++){
         if ((b[i]<=b[i-1])&&(len+1<=ma))
           for (int k=b[i];k<=b[i-1];k++){
               int q=0;
               for (int j=len;j>=i;j--)  q=q*10+b[j];
               q=q*10+k;
               for (int j=i-1;j>=1;j--)  q=q*10+b[j];
               if (f[q]==0){n++;a[n]=q;f[q]=1;}
               if ((q>0)&&(q!=tmp)){
                   cnt+=1;
                   l[cnt].u=q;l[cnt].v=tmp;l[cnt].w=k+(b[i-1]&b[i])+(b[i-1]^b[i]);
               }
     //cout<<ma<<' '<<cnt<<endl;
           }
         int q=0;
         if ((i!=len+1)&&(len>1)&&(b[i-1]>=b[i])&&(b[i]>=b[i+1])){
           for (int j=len;j>=1;j--)  if (j!=i)q=q*10+b[j];
           if (f[q]==0){n++;a[n]=q;f[q]=1;}
           if ((q>0)&&(q!=tmp)){
               cnt++;
               l[cnt].u=q;l[cnt].v=tmp;l[cnt].w=b[i]+(b[i-1]&b[i+1])+(b[i-1]^b[i+1]);
           }
    // cout<<tmp<<' '<<ma<<endl;
         }
     }
}
int cmp(zsm a,zsm b)
{
    return a.w<b.w;
}
int father(int x)
{
    if (fa[x]==x) return x;
    fa[x]=father(fa[x]);
    return fa[x];
}
void uni(int a,int b,int w)
{
     ans+=w;
     num[fa[b]]+=num[fa[a]];
     fa[fa[a]]=fa[b];
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d", &n);
    memset(f,0,sizeof(f));
    f[0]=1;
    for (int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        f[a[i]]=1;
        int p=1,pp=1;
        while (a[i]>=pp){
              pp*=10;
              p+=1;
              }
        if (p-1>ma) ma=p-1;
    }
    for (int i=1;i<=n;i++) fa[a[i]]=a[1];
    num[a[1]]=n;
    for (int i=1;i<=n;i++)  bfs(a[i]);
    for (int i=1;i<=n;i++) if (fa[a[i]]==0) fa[a[i]]=a[i];
    for (int i=2;i<=n;i++) if(fa[a[i]]==a[i]) num[a[i]]=1;
    sort(l+1,l+cnt+1,cmp);
    for (int i=1;i<=cnt;i++)
        if (father(l[i].u)!=father(l[i].v)){
            uni(l[i].u,l[i].v,l[i].w);
            if (num[fa[l[i].v]]==n) break;
        }
    cout<<ans<<endl;
//    system("pause");
    return 0;
}
