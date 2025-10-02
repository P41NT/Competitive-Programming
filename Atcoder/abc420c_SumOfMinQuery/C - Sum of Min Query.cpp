#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// recursive derrangement formula d(n) = (n - 1) * (d(n - 1) + d(n - 2));

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
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    vector<int> brr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> brr[i];

    int sm = 0;
    for (int i = 0; i < n; i++) {
        sm += min(arr[i], brr[i]);
    }

    while (q--) {
        char c; int x, v;
        cin >> c >> x >> v;
        x--;

        if (c == 'A') {
            sm -= min(arr[x], brr[x]);
            arr[x] = v;
            sm += min(arr[x], brr[x]);
        }
        if (c == 'B') {
            sm -= min(arr[x], brr[x]);
            brr[x] = v;
            sm += min(arr[x], brr[x]);
        }

        cout << sm << endl;
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

