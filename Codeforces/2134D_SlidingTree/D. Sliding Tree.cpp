#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

    vector<int> degree(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);

        degree[a]++;
        degree[b]++;
    }

    int node = -1;
    for (int i = 1; i <= n; i++) {
        if (degree[i] > 2) {
            node = i;
        }
    }

    if (node == -1) {
        cout << -1 << endl;
        return;
    }

    function<int(int, int)> dfs;
    dfs = [&](int curr, int parent) -> int {
        int d = 1;
        for (auto s : adj[curr]) {
            if (s == parent) continue;
            d += max(d, dfs(s, curr) + 1);
        }
        return d;
    };

    int minNode = 0;
    int minD = 1e12;

    for (auto s : adj[node]) {
        int d = dfs(s, node);
        if (d < minD) {
            minNode = s;
            minD = d;
        }
    }

    int maxNode = 0;
    int maxD = -1;

    for (auto s : adj[node]) {
        int d = dfs(s, node);
        if (d > maxD) {
            maxNode = s;
            maxD = d;
        }
    }

    cout << maxNode << " " << node << " " << minNode << endl;
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

