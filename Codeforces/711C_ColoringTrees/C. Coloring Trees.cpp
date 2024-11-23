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

const int INF = 1e18;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, m, t;
    cin >> n >> m >> t;

    vector<int> arr(n);
    vector<vector<int>> cost(n, vector<int>(m + 1));

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) 
        for (int j = 1; j <= m; j++)
            cin >> cost[i][j];

    for (int i = 0; i < n; i++) cost[i][arr[i]] = 0;
    debug(cost);

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m + 1, vector<int>(t + 1, -1)));

    function<int(int, int, int)> recur;
    recur = [&](int i, int j, int k) -> int {
        if (arr[i] != 0 && arr[i] != j) return INF;
        if (i == 0) {
            if (k == 1) return dp[i][j][k] = cost[0][j];
            return dp[i][j][k] = INF;
        }
        if (dp[i][j][k] != -1) return dp[i][j][k];
        if (k == 0) return dp[i][j][k] = INF;


        int answer = recur(i - 1, j, k);
        for (int j2 = 1; j2 <= m; j2++) {
            if (j == j2) continue;
            answer = min(answer, recur(i - 1, j2, k - 1));
        }

        if (answer == INF) return dp[i][j][k] = answer;
        answer += cost[i][j];
        debug(i, j, k, answer);

        return dp[i][j][k] = answer;
    };

    int answer = INF;
    for (int j = 1; j <= m; j++) {
        answer = min(answer, recur(n - 1, j, t));
    }

    if (answer == INF) cout << -1 << endl;
    else cout << answer << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

