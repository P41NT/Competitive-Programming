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
    int n, q;
    cin >> n >> q;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < q; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
        adj[b].push_back({a, x});
    }

    vector<int> answer(n + 1);
    for (int bit = 0; bit < 60; bit++) {
        vector<bool> curr(n + 1, 1);
        vector<bool> set(n + 1, false);
        int mask = (1ll << bit);
        for (int i = 1; i <= n; i++) {
            for (auto s : adj[i]) {
                if ((s.second & mask) == 0) {
                    curr[i] = 0;
                    set[i] = true;
                    break;
                }
                if (s.first == i) {
                    set[i] = true;
                    curr[i] = s.second;
                }
            }
        }
        debug(curr);
        debug(set);
        for (int i = 1; i <= n; i++) {
            if (set[i]) continue;
            for (auto s : adj[i]) {
                if (set[s.first] == true && curr[s.first] == 0) {
                    set[i] = true;
                    curr[i] = 1;
                }
            }
            debug(i);
            debug(set);
            if (!set[i]) {
                curr[i] = 0;
                set[i] = true;
                for (auto s : adj[i]) {
                    curr[s.first] = 1;
                    set[s.first] = true;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            answer[i] = answer[i] | ((1ll << bit) * curr[i]);
        }
    }

    for (int i = 1; i <= n; i++) cout << answer[i] << " ";
    cout << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

