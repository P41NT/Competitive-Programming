#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/CompetitiveProgramming/debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> vertical(n - 1, vector<int>(m));
    vector<vector<int>> horizontal(n, vector<int>(m - 1));

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m - 1; j++) 
            cin >> horizontal[i][j];

    for (int i = 0; i < n - 1; i++) 
        for (int j = 0; j < m; j++) 
            cin >> vertical[i][j];

    if (k & 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) 
                cout << -1 << " ";
            cout << endl;
        }
        return;
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1)));

    for (int t = 2; t <= k; t += 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j][t] = INT_MAX;
                if (i < n - 1)  dp[i][j][t] = min(dp[i][j][t], 2 * vertical[i][j] + dp[i + 1][j][t - 2]);
                if (i > 0)      dp[i][j][t] = min(dp[i][j][t], 2 * vertical[i - 1][j] + dp[i - 1][j][t - 2]);
                if (j < m - 1)  dp[i][j][t] = min(dp[i][j][t], 2 * horizontal[i][j] + dp[i][j + 1][t - 2]);
                if (j > 0)      dp[i][j][t] = min(dp[i][j][t], 2 * horizontal[i][j - 1] + dp[i][j - 1][t - 2]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cout << dp[i][j][k] << " ";
        cout << endl;
    }
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
	while (t--) {
        solve();
	}
}

