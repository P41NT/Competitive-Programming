#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #ifndef ONLINE_JUDGE
// #include "../debug.cpp"
// #define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
// #else
#define debug(...)
#define debugArr(...)
// #endif

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));

    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= n; k++) {
                if (i == n) {
                    if (j != 0) dp[i][j][k] = INT_MAX;
                    else if (k == arr[i]) dp[i][j][k] = 0;
                    else dp[i][j][k] = 1;
                }
                else {
                    int ans = INT_MAX;
                    if (j != 0) ans = min(ans, dp[i + 1][j - 1][0]);
                    ans = min(ans, dp[i + 1][j][k + 1]);
                    ans += (k == arr[i] ? 0 : 1);

                    dp[i][j][k] = ans;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dp[1][i][0] << endl;
    }

    // function<int(int, int, int)> recur;
    // recur = [&](int i, int j, int k) -> int {
    //     if (dp[i][j][k] != -1) return dp[i][j][k];
    //     if (i == n) {
    //         if (j != 0) return INT_MAX;
    //         if (k == arr[i]) return 0;
    //         return 1;
    //     }
    //     int ans = INT_MAX;
    //     if (j != 0) ans = min(ans, recur(i + 1, j - 1, 0));
    //     ans = min(ans, recur(i + 1, j, k + 1));
    //
    //     ans += (k == arr[i] ? 0 : 1);
    //
    //     // return dp[i][j][k] = ans;
    //     return ans;
    // };

    // for (int t = 0; t < n; t++) {
    //     cout << recur(1, t, 0) << endl;
    // }
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

