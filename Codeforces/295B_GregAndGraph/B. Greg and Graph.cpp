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

    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }

    vector<int> order(n + 1);
    for (int i = 1; i <= n; i++) cin >> order[n - i + 1];

    const int inf = 1e12;
    vector<vector<int>> dp = adj;

    vector<int> answers;
    for (int k = 1; k <= n; k++) {
        int currAnswer = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][order[k]] + dp[order[k]][j]);
            }
        }

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                currAnswer += dp[order[i]][order[j]];
            }
        }
        answers.push_back(currAnswer);
    }

    std::reverse(answers.begin(), answers.end());
    for (auto s : answers) std::cout << s << " ";
    std::cout << endl;
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

