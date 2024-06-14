#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void dfs(int curr, int color, vector<int> &visited, vector<vector<int>> &adj) {
    if (visited[curr]) return;
    visited[curr] = color;
    for (auto s : adj[curr]) {
        dfs(s, color, visited, adj);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> temp(k);
        for (int j = 0; j < k; j++) cin >> temp[j];
        for (int j = 1; j < k; j++) {
            adj[temp[j - 1]].push_back(temp[j]);
            adj[temp[j]].push_back(temp[j - 1]);
        }
    }

    // int i = 1;
    // for (auto s : adj) {
    //     cerr << i++ << " : ";
    //     for (auto k : s) cerr << k << " ";
    //     cerr << endl;
    // }

    vector<int> colors(n + 1);
    int color = 1;
    for (int i = 1; i <= n; i++) {
        if (colors[i]) continue;

        // for (auto s : colors) cerr << s << " ";
        // cerr << endl;

        dfs(i, color, colors, adj);
        color++;
    }

    map<int, int> freq;
    for (int i = 1; i <= n; i++) freq[colors[i]]++;
    for (int i = 1; i <= n; i++) cout << freq[colors[i]] << " ";
    cout << endl;
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

