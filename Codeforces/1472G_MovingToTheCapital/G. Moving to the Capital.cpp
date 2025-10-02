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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    queue<int> bfs;

    bfs.push(1);
    vector<int> dist(n + 1);
    dist[1] = 0;

    vector<bool> visited(n + 1);
    visited[1] = true;

    while (!bfs.empty()) {
        int curr = bfs.front();
        bfs.pop();

        for (auto s : adj[curr]) {
            if (visited[s]) continue;
            visited[s] = true;
            dist[s] = dist[curr] + 1;
            bfs.push(s);
        }

        debug(bfs);
    }

    debug(dist);
    
    vector<int> dp(n + 1, -1);
    dp[1] = 0;

    function<int(int)> recur;
    recur = [&](int curr) -> int {
        if (dp[curr] != -1) return dp[curr];

        int answer = dist[curr];
        for (auto s : adj[curr]) {
            answer = min(answer, dist[s]);
        }

        debug(curr, answer);

        for (auto s : adj[curr]) { 
            if (dist[s] > dist[curr]) {
                debug(curr, s);
                answer = min(answer, recur(s));
            }
        }

        return dp[curr] = answer;
    };

    for (int i = 1; i <= n; i++) {
        cout << recur(i) << " ";
    }
    cout << endl;
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

