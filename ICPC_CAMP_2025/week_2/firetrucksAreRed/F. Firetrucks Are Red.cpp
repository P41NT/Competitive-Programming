#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

    map<int, vector<int>> adj;

    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;

        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            adj[i].push_back(x + n);
            adj[x + n].push_back(i);
        }
    }

    map<int, bool> visited;
    map<int, int> parent;
    parent[1] = 0;
    visited[1] = true;

    function<void(int)> dfs;
    dfs = [&](int curr) {
        for (auto s : adj[curr]) {
            if (visited[s]) continue;
            visited[s] = true;
            parent[s] = curr;
            dfs(s);
        }
    };

    dfs(1);

    vector<tuple<int, int, int>> answer;
    for (int i = 2; i <= n; i++) {
        answer.push_back({i, parent[parent[i]], parent[i] - n});
        if (!visited[i]) {
            cout << "impossible" << endl;
            return;
        }
    }

    for (auto [a, b, c] : answer) {
        cout << a << " " << b << " " << c << endl;
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

