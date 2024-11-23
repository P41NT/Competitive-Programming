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
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> hot(k + 1);
    vector<int> cold(k + 1);

    for (int i = 1; i <= k; i++) cin >> cold[i];
    for (int i = 1; i <= k; i++) cin >> hot[i];

    if (n == 1) {
        cout << cold[arr[0]] << endl;
        return;
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    // function<int(int, int)> recur;
    // recur = [&](int i, int prev) -> int {
    //     if (i == n) return 0;
    //
    //     if (dp[i][prev] != -1) return dp[i][prev];
    //
    //     int option1 = ((arr[i] == prev) ? hot[arr[i]] : cold[arr[i]]) + 
    //                     recur(i + 1, arr[i - 1]);
    //     int option2 = ((arr[i] == arr[i - 1]) ? hot[arr[i]] : cold[arr[i]]) + 
    //                     recur(i + 1, prev);
    //
    //     int answer = min(option1, option2);
    //     return dp[i][prev] = answer;
    // };

    debug(dp);

    for (int i = n - 1; i >= 1; i--) {
        for (int j = k; j >= 0; j--) {
            int option1 = ((arr[i] == j) ? hot[arr[i]] : cold[arr[i]]) + dp[i + 1][arr[i - 1]];
            int option2 = ((arr[i] == arr[i - 1]) ? hot[arr[i]] : cold[arr[i]]) + dp[i + 1][j];

            dp[i][j] = min(option1, option2);
        }
    }


    int answer = cold[arr[0]] + dp[1][0];
    debug(dp);
    cout << answer << endl;
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

