#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/modint.hpp>

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

using mi = atcoder::modint998244353;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<vector<mi>> dp(n, vector<mi>(2));
    dp[n - 1][1] = 1;
    dp[n - 1][0] = 1;

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] <= a[i + 1] && b[i] <= b[i + 1]) {
            dp[i][0] += dp[i + 1][0];
            dp[i][1] += dp[i + 1][1];
        }
        if (a[i] <= b[i + 1] && b[i] <= a[i + 1]) {
            dp[i][0] += dp[i + 1][1];
            dp[i][1] += dp[i + 1][0];
        }
    }

    cout << (dp[0][0] + dp[0][1]).val() << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

