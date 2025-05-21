#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

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

vector<int> hashes(1e6 + 5, 0);

void preprocess() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i <= 1e6; i++) {
        hashes[i] = uniform_int_distribution<int>(1, LONG_MAX - 5)(rng);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> pref(n + 1);

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] ^ hashes[arr[i]];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = pref[r] ^ pref[l - 1];

        if (ans == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    preprocess();

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

