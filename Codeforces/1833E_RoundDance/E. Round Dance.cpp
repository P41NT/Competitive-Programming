#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool dfs(int i, int parent, vector<set<int>> &adj, vector<bool> &visited) {
    visited[i] = true;
    // for (auto s : adj[i]) {
    //     cerr << i << " ";
    //     for (auto s : adj[i]) cerr << s << " ";
    //     cerr << endl;
    // }
    for (auto s : adj[i]) {
        // cerr << i << " " << s << " " << visited[s] << endl;
        if (!visited[s]) {
            if (dfs(s, i, adj, visited)) return true;
        }
        else if (s != parent) return true;
        // cerr << i << " " << s << " after" << endl;
    }
    // cerr << i << endl;
    return false;
}

void solve() {
    int n;
    cin >> n;

    vector<set<int>> adj(n + 1);
    vector<bool> visited(n + 1);

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        adj[k].insert(i);
        adj[i].insert(k);
    }

    // for (int i = 1; i <= n; i++) {
    //     cerr << i << " : " ;
    //     for (auto s : adj[i]) cerr << s << " ";
    //     cerr << endl;
    // }

    int open = 0, closed = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        if (dfs(i, -1, adj, visited)) closed++;
        else open++;
    }
    cout << closed + min(open, 1ll) << " " << closed + open << endl;
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

