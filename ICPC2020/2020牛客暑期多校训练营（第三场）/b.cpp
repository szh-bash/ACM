#include <bits/stdc++.h>
using namespace std;
char s[3000000];
int n, x, sum = -1;
char o;
int main()
{
	scanf("%s%d", s, &n);
    int len=strlen(s);
    char op[2];
    for (int i = 0; i < n; ++i)
    {
    	
        scanf("%s%d", op, &x);
        if (op[0] == 'M')
        {
            sum = (sum + x) % len;
        }
        else
        {
            printf("%c\n", s[((x + sum) % len + len) % len]);
        }
    }
}
