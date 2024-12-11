#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/CompetitiveProgramming/debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, k;
    cin >> n >> k;
    
    if (k == 1) {
        cout << 0 << endl;
        return;
    }

    vector<int> arr(n + 1);
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    dp[0] = 0;
    // dp[1] = arr[1];
    multiset<int> os;
    // int sm = arr[1];
    int sm = 0;
    for (int i = 1; i <= n; i++) {
        os.insert(arr[i]);
        sm += arr[i];
        dp[i] = dp[i - 1] + arr[i];

        if (i - k >= 0) {
            if (i - k > 0) os.erase(os.find(arr[i - k]));
            sm -= arr[i - k];
            dp[i] = min(dp[i - k] + sm - *os.begin(), dp[i]);
        }
        debug(os, sm);
    }

    debug(dp);

    cout << dp[n] << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

