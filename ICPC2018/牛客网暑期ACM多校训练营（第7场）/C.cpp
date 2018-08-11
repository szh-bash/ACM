#include<bits/stdc++.h>
 
using namespace std;
#define left ll
int n,step,num;
char s[1<<19];
int f[18][1<<17];
int now[18][1<<19],left;
int b[210];
int ans;
void dfs(int depth,int len)
{
    if (depth==step)
    {
        int res=0;
        ans+=len; 
        for (int i=0;i<len;i++)
            res=res*2+now[depth][i];
        f[left][res]++;
        return;
    }  
    for (int i=0;i<len;i+=2)
        now[depth+1][i/2]=now[depth][i]&now[depth][i+1];
    ans+=len/2;
    dfs(depth+1, len/2);
    for (int i=0;i<len;i+=2)
        now[depth+1][i/2]=now[depth][i]|now[depth][i+1];
    ans+=len/2;
    dfs(depth+1, len/2);
    for (int i=0;i<len;i+=2)
        now[depth+1][i/2]=now[depth][i]^now[depth][i+1];
    ans+=len/2;
    dfs(depth+1,len/2);
}
int main()
{
    scanf("%d",&n);
    num=1<<n;
    //scanf("%s",s);
    step=min(n,14);
    for (int i=0;i<num;i++)
        now[0][i]=s[i]-'\0';
    left=n-step;
    dfs(0,num);
    cout<<ans<<endl;
    return 0;
    for (int i=left;i;i--)
        for (int j=0;j<1<<(1<<left);j++)
        {
            int len=1<<i,res=0;
            for (int k=0,x=j;k<len;k++)
                b[k]=x%2,x/=2;
            for (int k=0;k<len;k+=2)
                res=res*2+(b[k]&b[k+1]);
            f[i-1][res]+=f[i][j];
            res=0;
            for (int k=0;k<len;k+=2)
                res=res*2+(b[k]|b[k+1]);
            f[i-1][res]+=f[i][j];
            res=0;
            for (int k=0;k<len;k+=2)
                res=res*2+(b[k]^b[k+1]);
            f[i-1][res]+=f[i][j];
        }
    printf("%d\n",f[0][1]);
    return 0;
}
