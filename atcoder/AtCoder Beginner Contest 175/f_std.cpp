#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<long long>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using VVVVI = vector<VVVI>;

const ll INF = 1002003004005006007LL;

bool is_palin(string& s, int from, int to){
    for(; from < to; from++, to--) {
        if (s[from] != s[to]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<ll> c(n);
    rep(i, n) cin >> s[i] >> c[i];
    VVVI dp(n, VVI(22, VI(2, INF)));
    priority_queue<tuple<ll, int, int, bool>, vector<tuple<ll, int, int, bool>>, greater<tuple<ll, int, int, bool>>> q;
    rep(si, n) {
        dp[si][0][0] = c[si];
        q.emplace(c[si], si, 0, 0);
    }
    ll ans = INF;
    while(!q.empty()) {
        int si, i;
        bool t;
        ll cost;
        tie(cost, si, i, t) = q.top(); q.pop();
        if(dp[si][i][t] != cost) continue;
        if (t == 0) {
            if(is_palin(s[si], i, s[si].size()-1)) {
                chmin(ans, cost)
                continue;
            }
            rep(ri, n) {
                int i1 = i, i2 = s[ri].size()-1;
                bool ok = true;
                while(i1 < s[si].size() && i2 >= 0) {
                    if (s[si][i1] != s[ri][i2]) {
                        ok = false;
                        break;
                    }
                    i1++; i2--;
                }
                if (!ok) continue;
                ll nc = cost + c[ri];
                if (i1 < s[si].size()) {
                    if (nc < dp[si][i1][0]) {
                        dp[si][i1][0] = nc;
                        q.emplace(nc, si, i1, 0);
                    }
                } else if (i2 >= 0) {
                    if (nc < dp[ri][i2][1]) {
                        dp[ri][i2][1] = nc;
                        q.emplace(nc, ri, i2, 1);
                    }
                } else {
                    chmin(ans, nc);
                }
            }
        } else {
            if(is_palin(s[si], 0, i)) {
                chmin(ans, cost)
                continue;
            }
            rep(ri, n) {
                int i1 = i, i2 = 0;
                bool ok = true;
                while(i1 >= 0 && i2 < s[ri].size()) {
                    if (s[si][i1] != s[ri][i2]) {
                        ok = false;
                        break;
                    }
                    i1--; i2++;
                }
                if (!ok) continue;
                ll nc = cost + c[ri];
                if (i1 >= 0) {
                    if (nc < dp[si][i1][1]) {
                        dp[si][i1][1] = nc;
                        q.emplace(nc, si, i1, 1);
                    }
                } else if (i2 < s[ri].size()) {
                    if (nc < dp[ri][i2][0]) {
                        dp[ri][i2][0] = nc;
                        q.emplace(nc, ri, i2, 0);
                    }
                } else {
                    chmin(ans, nc);
                }
            }
        }
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;
}
