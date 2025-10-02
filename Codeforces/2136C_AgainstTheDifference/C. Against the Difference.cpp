#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// recursive derrangement formula d(n) = (n - 1) * (d(n - 1) + d(n - 2));

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

// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    map<int, vector<int>> mp;

    for (int i = 1; i <= n; i++) {
        mp[arr[i]].push_back(i);
    }

    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        auto &check = mp[arr[i]];
        int curr_ind = lower_bound(check.begin(), check.end(), i) - check.begin();
        if (curr_ind - arr[i] + 1 < 0) {
            continue;
        }
        int prev_ind = check[curr_ind - arr[i] + 1] - 1;
        dp[i] = max(dp[i], arr[i] + dp[prev_ind]);
    }

    cout << dp[n] << endl;
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

