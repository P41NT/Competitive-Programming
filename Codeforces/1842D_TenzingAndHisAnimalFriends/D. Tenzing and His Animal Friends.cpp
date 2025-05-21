#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ostream>

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
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    const int inf = 1e12;
    vector<int> dist(n + 1, inf);
    dist[1] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, curr] = pq.top();
        pq.pop();
        if (dist[curr] != -d) continue;

        for (auto [next, weight] : adj[curr]) {
            if (dist[curr] + weight < dist[next]) {
                dist[next] = dist[curr] + weight;
                pq.push({-dist[next], next});
            }
        }
    }

    if (dist[n] == inf) {
        cout << "inf" << endl;
        return;
    }

    string answer = "";
    for (int i = 0; i < n; i++) answer += "0";

    vector<int> order(n);
    for (int i = 1; i <= n; i++) order[i - 1] = i;
    sort(order.begin(), order.end(), [&](int a, int b) {
            if (dist[a] == dist[b]) return a < b;
            return dist[a] < dist[b];
            });

    vector<pair<string, int>> ans;

    for (int i = 0; i < n - 1; i++) {
        if (order[i] == n) break;
        int dist1 = dist[order[i]];
        int dist2 = dist[order[i + 1]];
        answer[order[i] - 1] = '1';
        int req = dist2 - dist1;
        ans.push_back({answer, req});
    }

    cout << dist[n] << " " << ans.size() << endl;
    for (auto [s, t] : ans) cout << s << " " << t << endl;
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

