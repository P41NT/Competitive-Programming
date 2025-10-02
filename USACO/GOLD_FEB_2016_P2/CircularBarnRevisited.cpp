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
    int n, k;
    cin >> n >> k;

    deque<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    const int inf = INT64_MAX;
    int fin_ans = inf;

    int tries = n;
    while (tries--) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, inf));
        dp[0][n] = 0;

        for (int door = 1; door <= k; door++) {
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (int j = i + 1; j <= n; j++) {
                    cnt += arr[j - 1] * (j - i - 1);
                    int next = dp[door - 1][j];
                    if (next < inf) { next += cnt; }
                    dp[door][i] = min(dp[door][i], next);
                }
            }
        }

        fin_ans = min(fin_ans, dp[k][0]);
        arr.push_back(arr.front());
        arr.pop_front();
    }

    cout << fin_ans << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

