#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/dsu.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace atcoder;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/Compocode/debug.cpp"
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

    dsu d1(n + 1);
    dsu d2(n + 1);

    vector<pair<int, int>> edges1;
    vector<pair<int, int>> edges2;

    int m1, m2;
    cin >> m1 >> m2;

    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        edges1.push_back({u, v});
    }

    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        edges2.push_back({u, v});
        d2.merge(u, v);
    }

    int answer = 0;

    for (auto [u, v] : edges1) {
        if (d2.same(u, v)) {
            d1.merge(u, v);
        }
        else answer++;
    }

    for (auto [u, v] : edges2) {
        if (!d1.same(u, v)) {
            d1.merge(u, v);
            answer++;
        }
    }

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

