#include <bits/stdc++.h>
#include <climits>
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
    string a;
    string b;
    string c;
    cin >> a >> b >> c;
    
    int n = a.size();
    int m = b.size();

    int t = c.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    function<int(int, int)> recur;
    recur = [&](int i, int j) -> int {
        if (i == n && j == m) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int curr = i + j;
        int answer = INT_MAX;
        if (i != n) answer = min(answer, recur(i + 1, j) + (a[i] != c[curr]));
        if (j != m) answer = min(answer, recur(i, j + 1) + (b[j] != c[curr]));
        return dp[i][j] = answer;
    };

    int ans = recur(0, 0);
    debug(dp);
    cout << ans << endl;
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

