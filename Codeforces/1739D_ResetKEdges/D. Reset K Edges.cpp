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
    int n, k;
    cin >> n >> k;

    vector<int> parent(n + 1);
    
    for (int i = 2; i <= n; i++) cin >> parent[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        adj[i].push_back(parent[i]);
        adj[parent[i]].push_back(i);
    }

    auto chk = [&](int mid) -> bool{
        vector<int> depth(n + 1);
        vector<bool> mark(n + 1);

        int remaining = k;
        function<void(int, int)> dfs;
        dfs = [&](int curr, int parent) {
            depth[curr] = 0;
            for (auto s : adj[curr]) {
                if (s == parent) continue;
                dfs(s, curr);
                if (mark[s]) continue;
                depth[curr] = max(depth[curr], depth[s] + 1);
            }
            if (curr != 1 && parent != 1 && depth[curr] + 1 >= mid) {
                depth[curr] = 0;
                mark[curr] = true;
                remaining--;
            }
            debug(mid, curr, depth[curr], remaining);
        };

        dfs(1, 0);
        if (remaining < 0) return false;
        return true;
    };

    int lower = 1, higher = n;
    int answer = n;
    while (lower <= higher) {
        int mid = (lower + higher) >> 1;
        if (chk(mid)) {
            higher = mid - 1;
            answer = min(answer, mid);
        }
        else {
            lower = mid + 1;
        }
    }
    
    cerr << endl;
    cout << answer << endl;
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

