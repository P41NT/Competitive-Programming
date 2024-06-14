#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void dfs(int curr, vector<vector<pair<int, int>>> &adj, vector<int> &visited, 
        vector<int> &group) {
    group.push_back(curr);
    visited[curr] = true;
    for (auto s : adj[curr]) {
        if (s.second == 1) continue;
        if (visited[s.first]) continue;
        dfs(s.first, adj, visited, group);
    }
}

int modpower(int a, int r, int mod) {
    int ans = 1;
    a = a % mod;
    if (a == 0) return 0;
    while (r) {
        if (r & 1) ans = (ans * a) % mod;
        r = r >> 1;
        a = (a * a) % mod;
    }
    return ans % mod;
}

const int mod = 1e9+7;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<vector<int>> groups;
    vector<int> visited(n + 1);

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        groups.push_back({});
        dfs(i, adj, visited, groups.back());
    }

    int ans = modpower(n, k, mod);
    for (auto s : groups) {
        ans -= modpower(s.size(), k, mod);
        ans += mod;
        ans %= mod;
    }
    cout << ans << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while ( t-- ) {
		solve();
	}
}

