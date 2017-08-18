#include <cmath> 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
	char s[201000], va[201000];
int n, ls, root, size[3001000], cnt, l[3001000], r[3001000], fa[3001000];
void zig(int t){
    int f1=fa[t];
    fa[t]=fa[f1];
    fa[f1]=t;
    l[f1]=r[t];
    r[t]=f1;
    size[f1]=size[l[f1]]+size[r[f1]]+1;
    size[t]=size[l[t]]+size[r[t]]+1;
    if (l[f1]) fa[l[f1]]=f1;
}
void zag(int t){
    int f1=fa[t];
    fa[t]=fa[f1];
    fa[f1]=t;
    r[f1]=l[t];
    l[t]=f1;
    size[f1]=size[l[f1]]+size[r[f1]]+1;
    size[t]=size[l[t]]+size[r[t]]+1;
    if (r[f1]) fa[r[f1]]=f1;
}
void splay(int t){
    int f1=fa[t], f2=fa[f1], tf=fa[f2];
    while (f2){
        if (l[tf]==f2) l[tf]=t;else r[tf]=t;
        if (l[f2]==f1)
              if (l[f1]==t){
                        zig(f1);zig(t);
                        }
              else{
                   zag(t);zig(t);
                   }
        else
               if (l[f1]==t){
                         zig(t);zag(t);
                         }
               else{
                    zag(f1);zag(t);
                    }
           f1=fa[t]=tf;f2=fa[f1];tf=fa[f2];
    }
    root=t;
    if (!f1) return;
    if (l[f1]==t) zig(t);else zag(t);
}
int query(int t, int rk){
	while (1){
	if (size[l[t]]>=rk) t=l[t];
	else
		if (size[l[t]]+1==rk) return t;
		else {rk=rk-size[l[t]]-1;t=r[t];}
	}
}
int main(){
	scanf("%s", &s);
	ls=strlen(s);
	size[1]=1;
	root=1;
	cnt=1;
    for (int i=0;i<ls;i++){
        int j=root;
    	while (r[j]) size[j]++, j=r[j];
    	r[j]=++cnt;fa[cnt]=j;size[cnt]=1;va[cnt]=s[i];size[j]++;
        splay(cnt);
    }
	scanf("%s", &s);
    while (s[0]!='E'){
    	int k, j, j2;
    	if (s[0]=='I'){
    		scanf("%s%d", &s, &k);
    		ls=strlen(s);
    		for (int i=0;i<ls;i++){
    			k++;
    			j=query(root,k);
    			splay(j);
    			va[++cnt]=s[i];size[cnt]++;
    			if (!r[j]) r[j]=cnt, fa[cnt]=j, size[j]++;
    			else{
    				j2=query(root,k+1);
    				splay(j2);
    				splay(j);
    				l[j2]=cnt;
    				fa[cnt]=j2;
    				size[j]++;size[j2]++;
    			}
    			splay(cnt);
    		}
    	}
    	else
    		if (s[0]=='P'){
    			int le, ri;
    			scanf("%d%d", &le, &ri);
    			le+=2;ri+=2;
    			for (int i=le;i<=ri;i++){
    				int x=query(root,i);
					printf("%c", va[x]);
					splay(x);
				}
    			puts("");
			}
    	scanf("%s", &s);
    }
    return 0;
}

