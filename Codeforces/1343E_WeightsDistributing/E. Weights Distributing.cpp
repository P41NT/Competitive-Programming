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
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    vector<int> weights(m + 1);
    for (int i = 1; i <= m; i++) cin >> weights[i];

    vector<int> pref(m + 1);
    sort(weights.begin(), weights.end());
    partial_sum(weights.begin(), weights.end(), pref.begin());

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    const int inf = 1e18;
    vector<int> dista(n + 1, inf);
    vector<int> distb(n + 1, inf);
    vector<int> distc(n + 1, inf);

    debug(adj);


    debug(weights);
    debug(pref);

    dista[a] = distb[b] = distc[c] = 0;

    auto bfs = [&](int start, vector<int> &dist) {
        dist[start] = 0;
        queue<int> bfs;
        bfs.push(start);
        vector<int> visited(n + 1);

        visited[start] = true;

        while (bfs.size()) {
            auto curr = bfs.front();
            bfs.pop();
            for (auto s : adj[curr]) {
                if (visited[s]) continue;
                visited[s] = true;
                dist[s] = dist[curr] + 1;
                bfs.push(s);
            }
        }
    };

    bfs(a, dista);
    bfs(b, distb);
    bfs(c, distc);

    debug(dista);
    debug(distb);
    debug(distc);

    int ans = inf;
    for (int i = 1; i <= n; i++) {
        int doub = distb[i];
        int sing = dista[i] + distc[i];

        if (doub + sing > m) continue;


        int answer = pref[doub + sing] + pref[doub];
        debug(i, sing, doub, answer);
        ans = min(ans, answer);
    }

    cout << ans << endl;
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

