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
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    function<int(int, int)> recur;
    recur = [&](int i, int j) -> int {
        if (j == i - 1) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int answer = 1 + recur(i + 1, j);
        for (int k = i + 1; k <= j; k++) {
            if (s[k] == s[i]) {
                int curr = recur(i + 1, k - 1) + recur(k, j);
                answer = min(answer, curr);
            }
        }
        return dp[i][j] = answer;
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

