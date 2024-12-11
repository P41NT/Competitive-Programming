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
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    const int inf = 1e16;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    function<int(int, int)> recur;
    recur = [&](int i, int k) -> int{
        debug(i, k);
        if (k >= n) return 0;
        if (i == n) return inf;

        if (dp[i][k] != -1) return dp[i][k];

        int option1 = recur(i + 1, k);
        int option2 = recur(i + 1, k + arr[i].first + 1 );
        if (option2 != inf) option2 += arr[i].second;

        return dp[i][k] = min(option1, option2);
    };

    int ans = recur(0, 0);
    cout << ans << endl;
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

