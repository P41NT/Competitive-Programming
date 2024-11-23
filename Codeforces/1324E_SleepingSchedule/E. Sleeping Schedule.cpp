#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
    int n, h, l , r;
    cin >> n >> h >> l >> r;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + arr[i];

    vector<vector<int>> dp(n + 5, vector<int>(n + 5, -1));
    function<int(int, int)> recur;
    recur = [&](int i, int rem) -> int {
        if (i == n + 1) return 0;
        if (dp[i][rem] != -1) return dp[i][rem];

        int curr = (pref[i] - rem) % (h);
        int answer = (curr >= l && curr <= r);
        answer += max(recur(i + 1, rem + 1), recur(i + 1, rem));
        return dp[i][rem] = answer;
    };

    int answer = recur(0, 0);
    if (0 >= l && 0 <= r) answer--;
    cout << answer << endl;
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

