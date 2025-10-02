#include <atcoder/modint.hpp>
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

using mi = atcoder::modint1000000007;

void solve() {
    int n;
    cin >> n;

    vector<string> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    // vector<vector<vector<int>>> dp(251, vector<vector<int>>(251, vector<int>(251)));
    vector<vector<mi>> dp(500, vector<mi>(500));
    vector<vector<mi>> dp2(500, vector<mi>(500));

    if (arr[0][0] != arr[n - 1][n - 1]) {
        cout << 0 << endl;
        return;
    }

    dp[0][n - 1] = 1;
    // dp[l][i][j] = dp[l - 1][i + 1][j - 1] + dp[l - 1][i][j - 1] + dp[l - 1][i + 1][j] + dp[l - 1][i][j];
    
    for (int t = 1; t < n; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > j) continue;

                int i2 = t - i;
                int j2 = n - 1 - (t - (n - 1 - j));

                if (i2 < 0 || j2 >= n) continue;

                if (arr[i][i2] != arr[j][j2]) {
                    dp2[i][j] = 0;
                    continue;
                }

                // dp2[i][j] = dp[i - 1][j] + dp[i][j + 1] + dp[i - 1][j + 1] + dp[i][j];
                dp2[i][j] += dp[i][j];
                if (i - 1 >= 0) dp2[i][j] += dp[i - 1][j];
                if (j + 1 < n) dp2[i][j] += dp[i][j + 1];
                if (i - 1 >= 0 && j + 1 < n) dp2[i][j] += dp[i - 1][j + 1];

                // debug(i, i2, j, j2, dp2[i][j], dp[i][j]);
            }
        }
        dp = dp2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp2[i][j] = 0;
            }
        }
    }

    mi answer = 0;
    for (int i = 0; i < n; i++) {
        answer += dp[i][i];
    }

    cout << answer.val() << endl;
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

