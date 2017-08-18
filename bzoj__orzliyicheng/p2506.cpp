#include <cstdio>
using namespace std;
char str[3000000],*p=str,*o=str;
int n,m,ans[300000],a[1000000],in[2000000][4],*ins[2000000],s[101][100],u[10001],rka[100001],*rk=rka+1;
inline int getint(){
    int re=0;
    while(*p<'0'||*p>'9')p++;
    while(*p>='0'&&*p<='9')re=re*10+*p++-48;
    return re;
}void print(int x){
    char buf[5],*b=buf;
    if(!x)*o++=48;
    else{while(x)*b++=x%10+48,x/=10;
    while(b--!=buf)*o++=*b;}
    *o++='\n';
}main(){
    int i=-1,r,P,k,t=-1,max;fread(p,1,3000000,stdin);n=getint()-1;
    for(m=getint()<<1;i++!=n;a[i]=getint());
    for(i=-1;++i!=m;in[i][3]=i){
        rk[in[i][0]=getint()-2]++;r=getint()-1;in[i][1]=P=getint();in[i][2]=k=getint();in[i][3]=i;
        rk[in[++i][0]=r]++;in[i][1]=P;in[i][2]=k;
    }for(i=-1;i++!=n;rk[i]+=rk[i-1]);
    for(i=-1;++i!=m;ins[--rk[in[i][0]]]=in[i]);
    for(i=-1,max=0;++i!=m;){
        while(t<ins[i][0]){
            u[a[++t]]++;
            if(a[t]>max)max=a[t];
            for(k=0;k++!=100;s[k][a[t]%k]++);
        }if(ins[i][1]<=100)ans[ins[i][3]]=s[ins[i][1]][ins[i][2]];
        else for(k=ins[i][2]-ins[i][1];(k+=ins[i][1])<=max;)ans[ins[i][3]]+=u[k];
    }for(i=-2;(i+=2)!=m;)print(ans[i^1]-ans[i]);
    *--o=0;return puts(str),0;
}
