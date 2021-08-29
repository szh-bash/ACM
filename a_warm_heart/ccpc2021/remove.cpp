#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

struct IO
{
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
    IO() : p1(buf), p2(buf), pp(pbuf)
    {
    }
    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
    inline char gc()
    {
        if (p1 == p2)
            p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }
    inline bool blank(char ch)
    {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    template <class T>
    inline void read(T &x)
    {
        register double tmp = 1;
        register bool sign = 0;
        x = 0;
        register char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-')
                sign = 1;
        for (; isdigit(ch); ch = gc())
            x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign)
            x = -x;
    }
    inline void read(char *s)
    {
        register char ch = gc();
        for (; blank(ch); ch = gc())
            ;
        for (; !blank(ch); ch = gc())
            *s++ = ch;
        *s = 0;
    }
    inline void read(char &c)
    {
        for (c = gc(); blank(c); c = gc())
            ;
    }
    inline void push(const char &c)
    {
        if (pp - pbuf == MAXSIZE)
            fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
    }
    template <class T>
    inline void write(T x)
    {
        if (x < 0)
            x = -x, push('-');
        static T sta[35];
        T top = 0;
        do
        {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top)
            push(sta[--top] + '0');
    }
    template <class T>
    inline void write(T x, char lastChar)
    {
        write(x), push(lastChar);
    }
} io;

const int oo = 0x3f3f3f3f, MAXN = 2000000, MAXP = 100000;

struct List
{
    List *prev, *next;
    int value;
    List() : value(0), prev(nullptr), next(nullptr) {}
    List(int _v) : value(_v), prev(nullptr), next(nullptr) {}
    void add(List *e)
    {
        if (next != nullptr)
            next->prev = e;
        e->next = next;
        next = e;
        e->prev = this;
    }
    void del()
    {
        if (prev != nullptr)
            prev->next = next;
        if (next != nullptr)
            next->prev = prev;
    }
} elements[MAXP + 5], Head, Tail;

int T, N, P, F[MAXN + 5], A[MAXP + 5], isUsed[MAXN + 5], ID[MAXP + 5];
bool isPrime[MAXN + 5];
array<int, 8> factors[MAXN + 5];
u64 ans;
int main()
{
    fill(isPrime + 2, isPrime + MAXN, true);
    for (int i = 2; i <= MAXN; ++i)
        if (isPrime[i])
        {
            factors[i][factors[i][0] = 1] = i;
            for (int j = i * 2; j <= MAXN; j += i)
            {
                factors[j][++factors[j][0]] = i;
                isPrime[j] = false;
            }
        }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    io.read(T);
    while (T--)
    {
        io.read(N);
        io.read(P);
        for (int i = 1; i <= P; ++i)
            io.read(A[i]);
        sort(A + 1, A + P + 1);
        for (int i = 1; i <= P; ++i)
            isUsed[A[i]] = i;
        F[0] = 0;
        int n = 1;
        for (; n < A[P]; ++n)
            F[n] = 1;
        for (int i = 1; i <= P; ++i)
            elements[i] = List(n - n % A[i]), ID[i] = i;
        sort(ID + 1, ID + P + 1, [&](int a, int b)
             { return elements[a].value < elements[b].value; });
        Head = Tail = List();
        Head.add(&Tail);
        for (int i = 1; i <= P; ++i)
            Tail.prev->add(&elements[ID[i]]);
        for (; n <= N; ++n)
        {
            for (int i = 1; i <= factors[n][0]; ++i)
            {
                int p = isUsed[factors[n][i]];
                if (!p)
                    continue;
                elements[p].del();
                elements[p].value = n;
                Tail.prev->add(&elements[p]);
            }
            F[n] = Head.next->value < n ? F[Head.next->value] + 1 : oo;
        }
        /*
        for (int i = 1; i <= N; ++i)
            cout << F[i] << ' ';
        cout << endl;
        */
        ans = 0;
        u64 tmp = 1;
        for (int n = N; n >= 1; --n)
        {
            ans += (F[n] < oo ? F[n] : 0) * tmp;
            tmp *= 23333;
        }
        io.write(ans, '\n');
        for (int i = 1; i <= P; ++i)
            isUsed[A[i]] = 0;
    }
}