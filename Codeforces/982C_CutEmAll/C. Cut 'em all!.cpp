#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

int dfs(int curr, int parent, vector<vector<int>> &adj, int &ans) {
    int size = 1;
    for (auto s : adj[curr]) {
        if (s == parent) continue;
        size += dfs(s, curr, adj, ans);
    }
    if (size % 2 == 0 && parent != -1) ans++;
    return size;
}

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

    if (n % 2 == 1) {
        cout << "-1" << endl;
        return;
    }

    int ans = 0;
    dfs(1, -1, adj, ans);

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

