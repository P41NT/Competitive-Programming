#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/modint.hpp>

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

using mi = atcoder::modint1000000007;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    debug(adj);

    vector<int> depth(n + 1);
    function<void(int, int)> dfs;
    dfs = [&](int curr, int parent) {
        depth[curr] = 1;
        for (auto s : adj[curr]) {
            if (s == parent) continue;
            dfs(s, curr);
            depth[curr] = max(depth[curr], depth[s] + 1);
        }
    };

    dfs(1, -1);

    mi ans = 0;
    for (int i = 1; i <= n; i++) ans += depth[i];

    ans *= ((mi)2).pow(n - 1);

    cout << ans.val() << endl;
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

