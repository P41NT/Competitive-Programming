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

const int maxn = 1e3;
vector<int> pre(maxn + 5, INT_MAX);

void precompute() {
    pre[1] = 0;
    for (int i = 1; i <= maxn; i++) {
        for (int x = 1; x <= i; x++) {
            int next = i + i / x;
            if (next <= maxn) pre[next] = min(pre[next], pre[i] + 1);
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> b(n);
    vector<int> c(n);

    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    if (k > 12 * n) {
        int answer = accumulate(c.begin(), c.end(), 0ll);
        cout << answer << endl;
        return;
    }

    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++) arr[i + 1] = pre[b[i]];

    debug(arr);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - arr[i] >= 0) {
                dp[i][j] = max(dp[i][j], c[i - 1] + dp[i - 1][j - arr[i]]);
            }
        }
    }

    debug(dp);
    cout << dp[n][k] << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    precompute();

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

