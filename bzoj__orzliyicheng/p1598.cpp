#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int nb_paturages, nb_chemins, nb_itineraires;
vector<int> plus_court[1001];
vector<int> suiv      [1001];
vector<int> poids     [1001];

int main() {
    scanf( "%d %d %d", &nb_paturages, &nb_chemins, &nb_itineraires);
    // making the reverse graph
    for (int chem = 0; chem < nb_chemins ; chem++) {
        int dep, arr, pds;
        scanf ("%d %d %d", &dep, &arr, &pds);
        suiv [arr].push_back (dep);
        poids[arr].push_back (pds);
    }
    plus_court[1].push_back (0);
    for (int pat = 1; pat <= nb_paturages ; pat++) {
        sort (plus_court[pat].begin(), plus_court[pat].end());
        // exploring the current node for all  the shortest path
        for (int id = 0; id < plus_court[pat].size() &&
				id < nb_itineraires; id++) {
            int tps = plus_court[pat][id];
            for (int id1 = 0; id1 < suiv[pat].size() ; id1++)
                plus_court[suiv[pat][id1]].push_back (tps + poids[pat][id1]);
        }
        // printing all the shortest path
        if (pat == nb_paturages)
            for (int id = 0; id < nb_itineraires ; id++)
                if (id < plus_court[pat].size())
                    printf ("%d\n", plus_court[pat][id]);
                            else
                    printf ("-1\n");
            plus_court[pat].clear();
    }
    return 0;
}
