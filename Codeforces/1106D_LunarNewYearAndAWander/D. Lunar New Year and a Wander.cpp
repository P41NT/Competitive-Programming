#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

int n, m;

void solve() {
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    vector<int> visited(n + 1);
    vector<int> ans;
    vector<int> added(n + 1);

    pq.push(1);

    while (!pq.empty()) {
        int curr = pq.top(); pq.pop();
        visited[curr] = 1;
        added[curr] = 1;
        ans.push_back(curr);
        for (auto s : adj[curr]) 
            if (!visited[s] && !added[s]) {
                pq.push(s);
                added[s] = 1;
            }
    }

    for (auto s : ans) 
        cout << s << " ";
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

