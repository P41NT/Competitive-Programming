#include <bits/stdc++.h>
#include <cstdio>
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
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    int mx1 = 0;
    int sm1 = 0;
    for (int i = 1; i <= n; i++) {
        mx1 = max(mx1, arr[i]);
        sm1 += arr[i];
        int curr = (i * mx1) - sm1;
        dp[i][0] = curr;

        debug(curr);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int mx = arr[i];
            int sum = arr[i];
            int answer = INT_MAX;
            for (int p = i - 1; p >= 0; p--) {
                int tot = mx * (i - p);
                int curr = tot - sum + dp[p][j - 1];
                debug(i, j, p, tot, sum, curr);
                answer = min(answer, curr);

                mx = max(mx, arr[p]);
                sum += arr[p];
            }

            dp[i][j] = answer;
        }
    }

    cout << dp[n][k] << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

