#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void dfs(int curr, int prev,  vector<vector<pair<int, int>>> &adj, vector<int> &level, vector<int> &visited) {
    visited[curr] = true;
    for (auto s : adj[curr]) {
        if (visited[s.first]) continue;
        level[s.first] = level[curr];
        if (s.second < prev) level[s.first]++;
        dfs(s.first, s.second, adj, level, visited);
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> arr(n + 1);
    vector<int> level(n + 1);
    vector<int> visited(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back({v, i});
        arr[v].push_back({u, i});
    }

    dfs(1, 0, arr, level, visited);

    int mx = 0;
    for (int i = 0; i <= n; i++) mx = max(mx, level[i]);

    cout << mx + 1 << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while ( t-- ) {
		solve();
	}
}

