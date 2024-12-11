#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/CompetitiveProgramming/debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;

    vector<int> degree(n + 1);
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        degree[a]++;
        degree[b]++;
    }

    vector<int> par(n + 1);

    function<void(int, int)> dfs1;
    dfs1 = [&](int curr, int parent) {
        par[curr] = parent;
        for (auto s : adj[curr]) {
            if (s == parent) continue;
            dfs1(s, curr);
        }
    };

    dfs1(1, -1);

    vector<vector<int>> dp(n + 1, vector<int> (4, -1));

    int answer = -1;

    function<int(int, int)> dfs;
    dfs = [&](int curr, int parent) -> int {
        int mx1 = 0;
        int mx2 = 0;
        for (auto s : adj[curr]) {
            if (s == parent) continue;
            int mxx = dfs(s, curr);
            if (mxx > mx1) {
                mx2 = mx1;
                mx1 = mxx;
            }
            else if (mxx > mx2) { 
                mx2 = mxx; 
            }
        }
        debug(mx1, mx2, curr);
        answer = max(answer, mx1 + mx2 + (degree[curr] - 2));
        return mx1 + degree[curr] - 2;
    };

    dfs(1, -1);
    cout << answer + 2 << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

