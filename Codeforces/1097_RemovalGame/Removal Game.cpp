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

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>> dp(n, vector<int>(n, -1));

    function<int(int, int)> recur;
    recur = [&](int i, int j) -> int {
        int turnsDone = n - (j - i + 1);
        int turn = (turnsDone % 2);
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (turn == 0) {
            if (j - i + 1 == 0) return 0;
            if (j - i + 1 == 1) return dp[i][j] = arr[i];
            return dp[i][j] = max(arr[i] + recur(i + 1, j), arr[j] + recur(i, j - 1));
        }
        else {
            if (j - i + 1 == 0) return 0;
            if (j - i + 1 == 1) return dp[i][j] = 0;
            return dp[i][j] = min(recur(i + 1, j), recur(i, j - 1));
        }
    };

    int answer = recur(0, n - 1);
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

