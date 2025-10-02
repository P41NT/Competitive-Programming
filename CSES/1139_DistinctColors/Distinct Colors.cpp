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

// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);

void solve() {
    int n;
    cin >> n;

    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<set<int>> count(n + 1);

    vector<int> answer(n + 1);

    function<void(int, int)> dfs;
    dfs = [&](int curr, int parent) {
        count[curr].insert(c[curr]);

        for (auto s : adj[curr]) {
            if (s != parent) {
                dfs(s, curr);
                if (count[s].size() > count[curr].size()) {
                    swap(count[s], count[curr]);
                }
                for (auto t : count[s]) {
                    count[curr].insert(t);
                }
            }
        }

        debug(curr, count[curr]);

        answer[curr] = count[curr].size();
    };

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

