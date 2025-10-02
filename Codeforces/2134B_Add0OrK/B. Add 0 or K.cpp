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
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    debug(n, k);

    if (k & 1) {
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 1) {
                arr[i] += k;
            }
        }

    }
    else if (k == 2) {
        for (int i = 0; i < n; i++) {
            while (arr[i] % 3 != 0) {
                arr[i] += 2;
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            int t = arr[i] % (k - 1);
            arr[i] += (k - 1 - t) * k;
        }
    }
    for (auto s : arr) {
        cout << s << " ";
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

