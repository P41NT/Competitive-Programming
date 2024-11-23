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
    int n, k, p;
    cin >> n >> k >> p;

    vector<int> arr(n);
    vector<int> keys(k);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < k; i++) cin >> keys[i];

    sort(arr.begin(), arr.end());
    sort(keys.begin(), keys.end());
    debug(arr, keys);

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));

    const int inf = 1e18;
    function<int(int, int)> recur;
    recur = [&](int curr, int required) -> int{
        if (required == n) return dp[curr][required] = 0;
        if (curr == k) return dp[curr][required] = inf; 

        if (dp[curr][required] != -1) return dp[curr][required];

        int option1 = max(abs(arr[required] - keys[curr]) + abs(keys[curr] - p), 
                        recur(curr + 1, required + 1));
        int option2 = recur(curr + 1, required);
        debug(curr, required, option1, option2);

        int answer = min(option1, option2);
        return dp[curr][required] = answer;
    };

    int answer = recur(0, 0);
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

