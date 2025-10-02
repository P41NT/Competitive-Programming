#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/segtree.hpp>

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

struct s_lca {
    int node;
    int depth;
};

s_lca op_lca(s_lca a, s_lca b) {
    if (a.depth <= b.depth) {
        return a;
    }
    return b;
}

s_lca e_lca() {
    return {-1, INT_MAX};
}

int op_q(int a, int b) {
    return a + b;
}

int e_q() {
    return 0;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<pair<int, int>> edges(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        edges[i + 1] = {u, v};
    }


    vector<int> tin(n + 1);
    vector<int> tout(n + 1);
    int timer = 0;

    vector<int> weight(n + 1);

    vector<s_lca> tour;
    vector<int> first(n + 1);

    vector<int> depth(n + 1);

    function<void(int, int)> dfs;
    dfs = [&](int curr, int parent) {
        tour.push_back({curr, depth[curr]});
        first[curr] = tour.size() - 1;

        tin[curr] = timer++;
        for (auto [s, w] : adj[curr]) {
            if (s == parent) continue;
            depth[s] = depth[curr] + 1;
            weight[s] = w;
            dfs(s, curr);
            tour.push_back({curr, depth[curr]});
        }
        tout[curr] = timer++;
    };

    dfs(1, 0);

    debug(tin);
    debug(tout);
    debug(weight);

    vector<int> p(2 * n + 1);

    for (int i = 1; i <= n; i++) {
        p[tin[i]] += weight[i];
        p[tout[i]] -= weight[i];
    }

    atcoder::segtree<s_lca, op_lca, e_lca> seg_lca(tour);
    atcoder::segtree<int, op_q, e_q> seg_q(p);

    debug(p);

    int q;
    cin >> q;

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 1) {
            auto [u, v] = edges[a];

            debug(u, v);

            int x = depth[u] > depth[v] ? u : v;
            debug(x, a, b);

            seg_q.set(tin[x], b);
            seg_q.set(tout[x], -b);
        }
        else {
            // find lca
            if (first[a] > first[b]) swap(a, b);
            s_lca lca = seg_lca.prod(first[a], first[b] + 1);
            debug(a, b, lca.node);

            int lca_ans = seg_q.prod(0, tin[lca.node] + 1);
            int ans1 = seg_q.prod(0, tin[a] + 1);
            int ans2 = seg_q.prod(0, tin[b] + 1);

            debug(ans1, ans2, lca_ans);

            int answer = ans1 + ans2 - 2 * lca_ans;
            cout << answer << endl;
        }
    }
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

