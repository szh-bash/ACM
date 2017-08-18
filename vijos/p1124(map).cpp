#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, len1[10], len2[10], ans;
char s1[30], s2[30], a[10][30], b[10][30], l1[500][60],  l2[500][60];
map <string, int> f;
int main(){
    scanf("%s %s\n", s1, s2);
    while (scanf("%s", a[++n])!=EOF) {
        scanf("%s", b[n]);
        len1[n]=strlen(a[n]);
        len2[n]=strlen(b[n]);
    }
    n--;
    f[s1]=1;f[s2]=-1;
    for (int i=0;i<strlen(s1);i++) l1[1][i]=s1[i];
    for (int i=0;i<strlen(s2);i++) l2[1][i]=s2[i];
    int le1=1, ri1=1, le2=1, ri2=1;
    for (int i=2;i<=6;i++){
        int tr=ri1;
        for (int j=le1;j<=tr;j++){
            int leng=strlen(l1[j]);
            for (int k=1;k<=n;k++)
                for (int p=0;p<=leng-len1[k];p++){
                    char ss[60];
                    for (int q=0;q<len1[k];q++) ss[q]=l1[j][p+q];
                    int flag=1;
                    for (int q=0;q<len1[k];q++)
                        if (ss[q]!=a[k][q]) flag=0;
                    if (flag){
                        for (int q=strlen(ss)-1;q>0;q--)
                            ss[q]='\0';
                        for (int q=0;q<p;q++) ss[q]=l1[j][q];
                        for (int q=0;q<len2[k];q++) ss[p+q]=b[k][q];
                        for (int q=p+len1[k];q<leng;q++) ss[len2[k]+q-len1[k]]=l1[j][q];
                        if (f[ss]<0){
                            ans=i-f[ss]-2;
                            if (ans>10) cout<<"NO ANSWER!"<<endl;
                                else cout<<ans<<endl;
                            return 0;
                        }
                        if (!f[ss]){
                            f[ss]=i;
                            ri1++;
                            for (int i=0;i<strlen(ss);i++) l1[ri1][i]=ss[i];
                        }
                    }
                }
        }
        le1=tr+1;
        tr=ri2;
        for (int j=le2;j<=tr;j++){
            int leng=strlen(l2[j]);
            for (int k=1;k<=n;k++)
                for (int p=0;p<=leng-len2[k];p++){
                    char ss[60];
                    for (int q=0;q<len2[k];q++) ss[q]=l2[j][p+q];
                    int flag=1;
                    for (int q=0;q<len2[k];q++)
                        if (ss[q]!=b[k][q]) flag=0;
                    if (flag){
                        for (int q=strlen(ss)-1;q>0;q--)
                            ss[q]='\0';
                        for (int q=0;q<p;q++) ss[q]=l2[j][q];
                        for (int q=0;q<len1[k];q++) ss[p+q]=a[k][q];
                        for (int q=p+len2[k];q<leng;q++) ss[len1[k]+q-len2[k]]=l2[j][q];
                            if (f[ss]>0){
                            ans=i+f[ss]-2;
                            if (ans>10) cout<<"NO ANSWER!"<<endl;
                                else cout<<ans<<endl;
                            return 0;
                        }
                        if (!f[ss]){
                            f[ss]=-i;
                            ri2++;
                            for (int i=0;i<strlen(ss);i++) l2[ri2][i]=ss[i];
                        }
                    }
                }
        }
        le2=tr+1;
        if (le1>ri1 || le2>ri2) break;
    }
    cout<<"NO ANSWER!"<<endl;
    return 0;
}
