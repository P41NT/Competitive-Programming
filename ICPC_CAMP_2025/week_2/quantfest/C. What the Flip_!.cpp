#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// recursive derrangement formula d(n) = (n - 1) * (d(n - 1) + d(n - 2));

#include <atcoder/modint.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);

using mi = atcoder::modint1000000007;

void solve() {
    int n;
    cin >> n;

    vector<vector<mi>> dp(n + 1, vector<mi>(2));
    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][1];
                if (i - 2 >= 0)  
                    dp[i][j] += dp[i - 2][1];
            }
            else {
                dp[i][j] = dp[i - 1][0];
            }
        }
    }

    mi answer = dp[n][0] + dp[n][1];

    cout << answer.val() << endl;
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

