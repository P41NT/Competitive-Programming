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

using mi = atcoder::modint1000000007;

void solve() {
    int n;
    cin >> n;

    vector<vector<bool>> arr(n + 1, vector<bool>(n));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x) arr[i][j] = true;
        }
    }

    vector<mi> dp((1ll << n));
    dp[0] = 1;

    vector<mi> newdp((1ll << n));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j]) {
                for (int k = 0; k < (1ll << n); k++) {
                    if ((k & (1ll << j)) == 0) {
                        newdp[k | (1ll << j)]  += dp[k];
                    }
                }
            }
        }
        dp = newdp;
        newdp = vector<mi>(1ll << n);
    }

    cout << dp[(1ll << n) - 1].val() << endl;
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

