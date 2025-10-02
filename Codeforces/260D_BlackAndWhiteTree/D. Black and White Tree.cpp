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

    vector<int> white;
    vector<int> black;

    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i++) {
        int c, x;
        cin >> c >> x;
        arr[i] = x;

        if (c) black.push_back(i);
        else white.push_back(i);
    }

    debug(arr);
    debug(white);
    debug(black);

    int i = 0, j = 0;
    while (i < white.size() && j < black.size()) {
        int u = white[i], v = black[j];
        int w = min(arr[u], arr[v]);

        debug(u, v);

        cout << u << " " << v << " " << w << endl;

        arr[u] -= w;
        arr[v] -= w;

        if (!arr[u] && i < white.size() - 1) i++;
        else {
            j++;
            if (j == black.size()) break;
        }
    }
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

