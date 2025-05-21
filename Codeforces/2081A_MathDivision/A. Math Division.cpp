#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/modint.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/Compocode/debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

using mi = atcoder::modint1000000007;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<mi>> dp(n, vector<mi>(2));
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) / (mi)2 + 1;
        }
        else {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) / (mi)2 + 1;
            dp[i][1] = dp[i - 1][1] + 1;
        }
    }

    cout << dp[n - 1][0].val() << endl;
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

