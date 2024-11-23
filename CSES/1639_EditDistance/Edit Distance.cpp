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
    string s, t;
    cin >> s >> t;

    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));

    function<int(int, int)> recur;
    recur = [&](int i, int j) -> int{
        if (dp[i][j] != -1) return dp[i][j];

        if (i == s.size() && j == t.size()) return dp[i][j] = 0;
        if (i == s.size()) return dp[i][j] = 1 + recur(i, j + 1);
        if (j == t.size()) return dp[i][j] = 1 + recur(i + 1, 1);


        if (s[i] == t[j]) return dp[i][j] = recur(i + 1, j + 1);
        int mn = recur(i + 1, j + 1);
        mn = min(mn, min(recur(i + 1, j), recur(i, j + 1)));

        int answer = 1 + mn;
        debug(i, j, answer);

        return dp[i][j] = answer;
    };

    cout << recur(0, 0) << endl;
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

