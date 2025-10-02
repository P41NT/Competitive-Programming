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

void solve() {
    int n, x;
    cin >> n >> x;

    const int inf = 1e12;

    vector<int> arr(n);
    vector<int> dp(1ll << n, inf);
    vector<int> smal(1ll << n, inf);

    for (int i = 0; i < n; i++) cin >> arr[i];

    dp[0] = 0;
    smal[0] = 0;

    vector<int> sm(1ll << n, 0);
    for (int bitmask = 0; bitmask < (1ll << n); bitmask++) {
        for (int j = 0; j < n; j++) {
            if (bitmask & (1ll << j)) {
                int currrides = dp[bitmask ^ (1ll << j)];
                int nextsmal = smal[bitmask ^ (1ll << j)] + arr[j];

                if (nextsmal > x) {
                    currrides++;
                    nextsmal = arr[j];
                }

                if (currrides < dp[bitmask] || (currrides == dp[bitmask] && nextsmal < smal[bitmask])) {
                    dp[bitmask] = currrides;
                    smal[bitmask] = nextsmal;
                }
            }
        }
    }

    cout << dp[(1ll << n) - 1] + 1 << endl;
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

