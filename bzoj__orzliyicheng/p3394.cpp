#include <iostream>

using namespace std;

#define MAX 500

int p,mat[MAX][MAX],f,favorite[MAX],best;

// read file
void fRead()
{
	int c;
	cin >> p >> f >> c;
	// read favourite pastures
	for (int i=0; i<f; favorite[i++]--)
		cin >> favorite[i];
	int a,b,d;
	// read cowpaths
	for (int i=0; i<c; i++)
	{
		cin >> a >> b >> d;
		mat[--a][--b]=d,mat[b][a]=d;
	}
}

// write file
void fWrite()
{
	cout << best << "\n";
}

void solve()
{
	// Floyd-Warshall all shortest path
	for (int i=0; i<p; i++)
		for (int j=0; j<p; j++)
			if (mat[j][i])
				for (int k=0; k<p; k++)
					if (mat[i][k] && (!mat[j][k] || mat[j][k]>mat[j][i]+mat[i][k]))
							mat[j][k]=mat[j][i]+mat[i][k];
	for (int i=0; i<p; i++) mat[i][i]=0;

	// find best pasture
	int bestsum=1000000000;
	for (int i=0; i<p; i++)
	{
		// calculate the total distance
		//	from the current pasture to favourite pastures
		int sum=0;
		for (int j=0; j<f; sum+=mat[i][favorite[j++]]);
		if (bestsum>sum) bestsum=sum,best=i+1;	// update if it is a better pasture
	}
}

int main(void)
{
	fRead();
	solve();
	fWrite();
}
