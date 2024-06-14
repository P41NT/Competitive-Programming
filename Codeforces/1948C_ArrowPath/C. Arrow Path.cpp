#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

int n;
bool dfs(int curr, vector<bool>& visited, vector<vector<int>>& adj) {
    // cerr << curr << " ";
    if (curr == 2 * n - 1) return true;
    if (visited[curr]) return false;
    visited[curr] = true;

    bool ans = false;
    for (auto s : adj[curr]) 
        ans |= dfs(s, visited, adj);

    return ans;
}

void solve() {
    string a;
    string b;
    
    cin >> n;
    cin >> a >> b;

    // map<pair<int, int>, vector<pair<int, int>>> adj;
    vector<vector<int>> adj(2 * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            bool odd = (i + j) & 1;
            int id = (i + (j?n:0));
            // cerr << i << " " << j << " " << id << endl;

            auto &node = adj[id];
            if (!odd) {
                if (i != 0) node.push_back(id - 1);
                if (i != n - 1) node.push_back(id + 1);
                if (j == 0) node.push_back(id + n);
                if (j == 1) node.push_back(id - n);
            }
            else {
                if (j == 0) {
                    if (a[i] == '<') node.push_back(id - 1);
                    else node.push_back(id + 1);
                }
                if (j == 1) {
                    if (b[i] == '<') node.push_back(id - 1);
                    else node.push_back(id + 1);
                }
            }
        }
    }
    // map<pair<int, int>, bool> visited;
    vector<bool> visited(2 * n);

    // for (int i = 0; i < 2 * n; i++) {
    //     cerr << i << ":";
    //     for (auto k : adj[i]) 
    //         cerr << k << " ";
    //     cerr << endl;
    // }
    // cerr << endl;

    cout << (dfs(0, visited, adj) ? "YES" : "NO") << endl;
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

