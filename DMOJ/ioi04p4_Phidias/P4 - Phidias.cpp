#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int w, h;
    cin >> w >> h;

    int n;
    cin >> n;

    vector<pair<int, int>> tiles(n);

    for (int i = 0; i < n; i++) cin >> tiles[i].first >> tiles[i].second;

    vector<vector<int>> dp(w + 1, vector<int>(h + 1));

    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
            dp[i][j] = i * j;
        }
    }
    for (auto [x, y] : tiles) dp[x][y] = 0;

    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            for (int t = 1; t <= i; t++) {
                dp[i][j] = min(dp[i][j], dp[t][j] + dp[i - t][j]);
            }
            for (int t = 1; t <= j; t++) {
                dp[i][j] = min(dp[i][j], dp[i][t] + dp[i][j - t]);
            }
        }
    }

    cout << dp[w][h] << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

