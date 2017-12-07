#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, le[11000], ri[11000], ls;
char s[2100000], ss[2100000], sss[3];
int min(int a, int b){return a<b?a:b;}
int main(){
	freopen("1.in","r",stdin);
    scanf("%d%d",&n, &m);
    ls=-1;
    getchar();
    for (int i=1;i<=n;i++){
    	//scanf("%s", ss);
    	gets(ss);
    	for (int j=0;j<strlen(ss);j++)
    		s[ls+j+1]=ss[j];
    	le[i]=ls+1;
    	ri[i]=ls=strlen(s)-1;
    }
    for (int i=1;i<=m;i++){
    	scanf("%s", ss);
    	if (ss[0]=='M'){
    		int x, y;
    		scanf("%d%d%s", &x, &y, sss);
    		s[le[x]+y-1]=sss[0];
    	}
    	else
    	if (ss[0]=='Q'){
    		int p=-1, x;
    		scanf("%d%s", &x, sss);
    		for (int j=le[x];j<=ri[x];j++)
    			if (s[j]==sss[0]){ p=j-le[x]+1;break;}
    		printf("%d\n", p);
    	}
    	else
    	if (ss[0]=='C'){
    		int f=0, x, y;
    		scanf("%d%d", &x, &y);
    		int l1=ri[x]-le[x]+1,l2=ri[y]-le[y]+1;
    		for (int j=0;j<min(l1,l2);j++)
    			if (s[le[x]+j]<s[le[y]+j]) {f=-1;break;}
    			else
    				if (s[le[x]+j]>s[le[y]+j]) {f=1;break;}
    		if (!f && l1<l2) f=-1;
    		if (!f && l1>l2) f=1;
    		printf("%d\n", f);
    	}
    }
	return 0;
}
