#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        degree[a]++;
        degree[b]++;
    }

    vector<bool> color(n + 1);

    function<void(int, int, bool)> dfs;
    dfs = [&](int curr, int parent, bool col) {
        color[curr] = col;
        for (auto s : adj[curr]) {
            if (s == parent) continue;
            dfs(s, curr, !col);
        }
    };

    dfs(1, 0, 0);

    vector<int> answer(n + 1);
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            answer[i] = degree[i];
        }
        else answer[i] = -degree[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

