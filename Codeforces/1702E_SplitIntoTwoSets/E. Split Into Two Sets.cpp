#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool dfs(int clock, int curr, int parent, vector<set<int>> &adj, vector<int> &visited) {
    // cerr << curr << " " << parent << " " << clock << endl;
    visited[curr] = clock;

    for (auto s : adj[curr]) {
        if (s == parent) continue;
        if (visited[s]) {
            // cerr << clock << " " << curr << " " << parent << " " << s << " " << visited[s] << endl;
            if ((clock - visited[s]) % 2 == 0) {
                // cerr << clock << " " << curr << " " << parent << " " << s << " " << visited[s] << endl;
                return false;
            }
            continue;
        }
        dfs(clock + 1, s, curr, adj, visited);
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> temp(n + 1);

    bool possible = true;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        temp[a].push_back(i);
        temp[b].push_back(i);
        if (a == b) possible = false;
        if (temp[a].size() > 2) possible = false;
        if (temp[b].size() > 2) possible = false;
    }


    // for (int i = 0; i <= n; i++) {
    //     cerr << i << " => ";
    //     for (auto s : temp[i])
    //         cerr << s << " ";
    //     cerr << endl;
    // }
    // cerr << endl;

    if (!possible) {
        cout << "NO" << endl;
        return;
    }

    vector<set<int>> adj(n);
    for (int i = 1; i <= n; i++) {
        adj[temp[i][0]].insert(temp[i][1]);
        adj[temp[i][1]].insert(temp[i][0]);
    }

    vector<int> visited(n);
    bool ans = true;

    // for (int i = 0; i < n; i++) {
    //     cerr << i << " -> ";
    //     for (auto s : adj[i])
    //         cerr << s << " ";
    //     cerr << endl;
    // }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        if (!dfs(1, i, -1, adj, visited)) {
            ans = false;
            break;
        }
    }

    cout << (ans ? "YES" : "NO") << endl;
    // cerr << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    // int tc = 1;
	int t = 1;
	cin >> t;
	while ( t-- ) {
		solve();
        // cerr << tc++ << endl;
	}
}

