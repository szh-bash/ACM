#include <cstdio>
#include <cstring>

using namespace std;

int capacity[52][52];//global variables are automatically initialized to zero
int E;

#define MN(x,y) ((x) < (y) ? (x) : (y))

int main(void)
{
	scanf("%i", &E);
	for(int i = 0 ; i < E ; i++)
	{
		char a,b;
		int c;
		scanf("%*c%c%*c%c%i", &a, &b, &c);
		if(a >= 'a' && a <= 'z')
			a += 'Z' + 1 - 'a';
		if(b >= 'a' && b <= 'z')
			b += 'Z' + 1 - 'a';
		capacity[a - 'A'][b - 'A'] += c;
		capacity[b - 'A'][a - 'A'] += c;
	}

	bool changed;//flag to tell us if the graph has changed this iteration
	do
	{
		changed = false;
		for(int i = 0 ; i < 52 ; i++)
		if(i != 0 && i != 25)
		{
			int first = -1;
			int second = -1;
			bool bad = false;
			for(int j = 0 ; j < 52 ; j++)
			{
				if(capacity[i][j] != 0)
				{
					if(first == -1)
						first = j;
					else if(second == -1)
						second = j;
					else
						bad = true;
				}
			}
//bad is set if vertex i has more than three pipes connected to it
			if(bad)continue;
			if(second != -1)//use the first simplification rule
			{
				capacity[first][second] += MN(capacity[first][i], capacity[i][second]);
				capacity[second][first] += MN(capacity[first][i], capacity[i][second]);
				capacity[first][i] = 0;
				capacity[second][i] = 0;
				capacity[i][first] = 0;
				capacity[i][second] = 0;

				changed = true;
			}
			else if(first != -1)//use the third simplification rule
			{
				capacity[first][i] = capacity[i][first] = 0;
				changed = true;
			}
		}
	}while(changed);

	printf("%i\n", capacity[0][25]);

	return 0;
}
