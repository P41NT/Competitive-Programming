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
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (n % 2 == 0) arr.push_back(0);

    debug(arr);

    int counter = 0;
    for (int i = 1; i < n; i += 2) {
        if (arr[i] < arr[i - 1] + arr[i + 1]) {
            int diff = arr[i - 1] + arr[i + 1] - arr[i];
            debug(i, diff);
            counter += diff;

            int sub = min(arr[i + 1], diff);
            diff -= sub;
            arr[i + 1] -= sub;
            arr[i - 1] -= diff;
        }

        debug(arr);
    }

    debug(arr);

    cout << counter << endl;
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

