#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    map<pair<int, int>, int> edges;
    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edge;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edge.push_back({a, b});
    }

    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1 && 
                !edges.count({i, adj[i][0]}) && !edges.count({adj[i][0], i})) {
            edges[{i, adj[i][0]}] = k++;
        }
        if (k == 3) break;
    }

    for (auto s : edge) {
        if (!edges.count({s.first, s.second}) && !edges.count({s.second, s.first})){
            edges[{s.first, s.second}] = k++;
        }
    }

    for (auto s : edge) {
        if (edges.count({s.first, s.second})) cout << edges[{s.first, s.second}] << endl;
        else cout << edges[{s.second, s.first}] << endl;
    }
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

