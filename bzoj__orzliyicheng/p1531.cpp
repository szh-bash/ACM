#include<iostream>
#include<cstdio>
#include<list>
using namespace std;

const int MAX_N = 200;
const int MAX_K = 20000;
const int NIESKONCZONOSC = 1000000000;

int n,k;
int b[MAX_N + 1],c[MAX_N + 1];
int R[MAX_K + 1];
int M[MAX_K + 1];

void odczyt()
{
  int i;
  scanf("%d",&n);
  for(i = 0;i < n;i++)
    scanf("%d",&b[i]);
  for(i = 0;i < n;i++)
    scanf("%d",&c[i]);
  scanf("%d",&k);
}

void inicjuj()
{
  R[0] = 0;
  for(int i = 1;i <= k;i++)
    R[i] = NIESKONCZONOSC;
}

void aktualizuj(int nr)
{
  list<int> kolejka;
  for(int r = 0;r < b[nr];r++)
  {
    kolejka.clear();
    int i = 0;
    while (r + i*b[nr] <= k)
    {
      M[i] = R[r + i*b[nr]] - i;
      while (!kolejka.empty() && M[kolejka.back()] >= M[i])
        kolejka.pop_back();
      kolejka.push_back(i);
      R[r + i*b[nr]] = M[kolejka.front()] + i;
      if (kolejka.front() == i - c[nr])
        kolejka.pop_front();
      i++;
    }
  }
}
int main()
{
  odczyt();
  inicjuj();
  for(int i = 0;i < n;i++)
    aktualizuj(i);
  printf("%d\n",R[k]);
  return 0;
}
