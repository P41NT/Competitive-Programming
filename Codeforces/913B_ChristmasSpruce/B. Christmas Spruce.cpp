#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/CompetitiveProgramming/debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
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
    vector<bool> isLeaf(n + 1, true);
    vector<vector<int>> adj(n + 1);

    for (int i = 2; i <= n; i++) {
        int parent; cin >> parent;
        degree[parent]++;
        isLeaf[parent] = false;

        adj[parent].push_back(i);
    }


    for (int i = 1; i <= n; i++) {
        if (isLeaf[i]) continue;
        int leafcount = 0;
        for (auto s : adj[i]) if (isLeaf[s]) leafcount++;
        if (leafcount < 3) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
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

