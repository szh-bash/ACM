#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<cmath>
using namespace std;
int N,L;
char str[105];
bool vis[255];
void work4()
{
	for(int i=1;i<=3;++i)
	{
		for(int j=0;j<L-1;++j) printf("%c",str[j]);
		printf("%d\n",i);
	}
}
int main()
{
	scanf("%s",str); L=strlen(str);
	if(str[L-1]=='4') work4();
	else{
		for(;L>=2;--L)
		{
			if(!vis[str[L-1]])
			{
				vis[str[L-1]]=true;
				for(int i=0;i<L-1;++i)
					printf("%c",str[i]);
				printf("4\n");
			}
		}
	}
}
