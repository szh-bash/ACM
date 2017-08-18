#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int l[101], r[101], x, ans[101], n, root;
int find(int x){
    while (r[x]) x=l[x];
    if (!l[x]) return x;
    return l[l[x]] ? x : l[x];
}
void delet(int x){
     int p=root, fa=root;
     while (p!=x){
           swap(l[p],r[p]);
           if (r[p]==x) fa=p;
           p=r[p];
     }
     if (root==x){
                  root=l[x];
                  return ;
                  }
     r[fa]=l[x];
     
}
int main(){
    scanf("%d", &n);
    for (int i=1;i<=n;i++){
        scanf("%d", &x);
        if (x>=100) r[x-100]=i;else l[x]=i;
    }
    for (int i=1;i<=n;i++){
        x=find(root);
        delet(x);
        ans[i]=x; 
    }
    printf("%d", root);
    for (int i=n;i>=1;i--) printf(" %d", ans[i]);printf("\n");
    return 0;
}
