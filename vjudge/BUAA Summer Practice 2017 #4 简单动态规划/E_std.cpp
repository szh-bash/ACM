#include <cstdio>
#include <cctype>
#include <cstring>

const int MAXN = 4010;
const int MAXM = 810;

int n, m,a[MAXN][MAXN],b[MAXN][MAXN],w[MAXN][MAXN];
int f[MAXM][MAXN];
int s[MAXM][MAXN];

void input(int &num)
{
    num = 0;
    char c;
    do
    {
        c = getchar();
    } while (!isdigit(c));
    while (isdigit(c))
    {
        num = num * 10 + c - '0';
        c = getchar();
    }
}

int main()
{
    //freopen("F:\\rush.txt", "r", stdin);
	memset(f, 127 / 3, sizeof(f));
	printf("%d\n",f[0][0]);
    input(n); input(m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            input(a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)//矩阵前缀和
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)//后面加上重复减去的部分。除2就是花费
            w[i][j] = (a[j][j] - a[i - 1][j] - a[j][i - 1] + a[i - 1][i - 1]) / 2;
   
    for (int i = 1; i <= n; i++)
        f[1][i] = w[1][i], s[1][n] = 0;
    for (int i = 2; i <= m; i++)
    {
        s[i][n + 1] = n;
        for (int j = n; j >= i; j--)
        {
            for (int k = s[i - 1][j]; k <= s[i][j + 1]; k++)
                if (f[i][j] > f[i - 1][k] + w[k + 1][j])
                    f[i][j] = f[i - 1][k] + w[k + 1][j], s[i][j] = k;//更改决策量。
        }
    }
    printf("%d\n", f[m][n]);
    return 0;
}
