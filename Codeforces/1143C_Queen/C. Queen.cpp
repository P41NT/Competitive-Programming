#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int


void dfs(int curr, vector<int> &ans, vector<int> &respect, vector<int> &parent,
        vector<vector<int>> &adj) {
    int r = 1;
    for (auto s : adj[curr]) {
        if (s == parent[curr]) continue;
        r &= respect[s];
    }
    if (r && respect[curr]) ans.push_back(curr);

    for (auto s : adj[curr]) dfs(s, ans, respect, parent, adj);
}

void solve() {
    int n;
    cin >> n;

    int root = 0;
    vector<int> respect(n + 1);
    vector<vector<int>> adj(n + 1);
    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++) {
        int p, r;
        cin >> p >> r;
        parent[i] = p;
        respect[i] = r;
        if (p == -1) root = i;
        else adj[p].push_back(i);
    }

    vector<int> ans;
    dfs(root, ans, respect, parent, adj);

    sort(ans.begin(), ans.end());

    if (ans.size() == 0) ans.push_back(-1);
    for (auto s : ans) cout << s << " ";
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

