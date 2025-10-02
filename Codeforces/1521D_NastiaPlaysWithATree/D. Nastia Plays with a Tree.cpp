#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/lazysegtree.hpp>
#include <atcoder/segtree.hpp>
#include <atcoder/modint.hpp>
#include <atcoder/dsu.hpp>

// recursive derrangement formula d(n) = (n - 1) * (d(n - 1) + d(n - 2));

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);

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

    vector<vector<int>> dp(n + 1, vector<int>(2));

    vector<int> decision(n + 1);

    function<int(int, int, int)> dfs;
    dfs = [&](int curr, int parent, int deg) -> int {
        if (parent != 0 && adj[curr].size() <= 2 && deg == 2) {
            return INT_MAX;
        } 
        else if (parent == 0 && adj[curr].size() <= 1 && deg == 2) {
            return INT_MAX;
        }
        if (adj[curr].size() == 1) return 0;

        int answer = 0;
        for (auto s : adj[curr]) {
            if (s == parent) continue;
            int c1 = dfs(s, curr, 1);
            int c2 = dfs(s, curr, 2) + 1;

            int mn = min(c1, c2);

            if (mn == c1) decision[s] = 1;
            else decision[s] = 2;

            answer += mn;
        }

        if (parent == 0) {
            if (deg == 1) return (adj[curr].size() - 1 + answer);
            return (adj[curr].size() - 2 + answer);
        }

        if (deg == 1) return (adj[curr].size() - 2 + answer);
        return (adj[curr].size() - 3 + answer);
    };
    
    if (adj[1].size() == 1) decision[1] = 1;
    else decision[1] = 2;

    vector<tuple<int, int, int, int>> ans;

    vector<int> leaf

    function<void(int, int)> dfs2;
    dfs2 = [&](int curr, int parent) {
        for (auto s : adj[curr]) {
            if (s == parent) continue;
        }
    };

    int answer = min(dfs(1, 0, 1), dfs(1, 0, 2));
    cout << answer << endl;

    cerr << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

