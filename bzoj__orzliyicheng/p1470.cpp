#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
const int N = 50005;

int stone[N];
int n,t,ans;

void combine(int k)
{
    int tmp = stone[k] + stone[k-1];
    ans += tmp;
    for(int i=k;i<t-1;i++)
        stone[i] = stone[i+1];
    t--;
    int j = 0;
    for(j=k-1;j>0 && stone[j-1] < tmp;j--)
        stone[j] = stone[j-1];
    stone[j] = tmp;
    while(j >= 2 && stone[j] >= stone[j-2])
    {
        int d = t - j;
        combine(j-1);
        j = t - d;
    }
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 0) break;
        for(int i=0;i<n;i++)
            scanf("%d",stone+i);
        t = 1;
        ans = 0;
        for(int i=1;i<n;i++)
        {
            stone[t++] = stone[i];
            while(t >= 3 && stone[t-3] <= stone[t-1])
                combine(t-2);
        }
        while(t > 1) combine(t-1);
        printf("%d\n",ans);
    }
    return 0;
}

