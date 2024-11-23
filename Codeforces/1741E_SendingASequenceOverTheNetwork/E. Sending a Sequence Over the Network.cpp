#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <pthread.h>

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

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n + 2);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<bool> dp(n + 2);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        debug(i, i - arr[i] - 1);
        if (i - arr[i] - 1 >= 0) 
            dp[i] = dp[i] | dp[i - arr[i] - 1];
        if (i + arr[i] <= n) 
            dp[i + arr[i]] = dp[i + arr[i]] | dp[i - 1];
    }

    debug(dp);

    cout << (dp[n] ? "YES" : "NO") << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

