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


    vector<vector<pair<char, int>>> arr(n, vector<pair<char, int>>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> arr[i][j].first >> arr[i][j].second;
        }
    }

    debug("done");

    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    function<int(int, int)> recur;
    recur = [&](int i, int j) -> int {
        if (dp[i][j] != -1) return dp[i][j];
        int currmul = (arr[i][j].first == '+' ? 1 : arr[i][j].second);
        if (i == n - 1) return dp[i][j] = currmul;
        int extra = (currmul - 1);
        return dp[i][j] = recur(i + 1, j) + extra * max(recur(i + 1, 0), recur(i + 1, 1));
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cerr << recur(i, j) << " ";
        }
        cerr << endl;
    }
    cerr << endl;

    int answer = 0;
    int extra = 2;
    for (int i = 0; i < n; i++) {
        if (i != 0) answer += extra * max(recur(i, 0), recur(i, 1));
        else answer += recur(0, 0) + recur(0, 1);
        extra = 0;
        if (arr[i][0].first == '+') extra += arr[i][0].second;
        if (arr[i][1].first == '+') extra += arr[i][1].second;
        debug(extra);
    }
    answer += extra;

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

