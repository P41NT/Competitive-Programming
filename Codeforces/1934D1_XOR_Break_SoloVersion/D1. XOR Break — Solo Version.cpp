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

void solve() {
    int n, m;
    cin >> n >> m;

    if (m > n) {
        cout << -1 << endl;
        return;
    }

    if ((n ^ m) < n && m < n) {
        cout << 1 << endl;
        cout << n << " " << m << endl;
        return;
    }

    int t = (n & m) ^ n;
    while (__builtin_popcount(t) > 1) {
        t ^= (t) & (-t);
    }

    debug(t);

    int inter = (t - 1) | (n ^ t);
    debug(inter);

    if (inter >= n || (inter ^ n) >= n) {
        cout << -1 << endl;
        return;
    }
    if (m >= inter || (m ^ inter) >= inter) {
        cout << -1 << endl;
        return;
    }

    cout << 2 << endl;
    cout << n << " " << inter << " " << m << endl;
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

