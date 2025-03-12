#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>


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
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    int sm = accumulate(arr.begin(), arr.end(), 0ll);

    int time = arr[0];
    int carry = 1e12;
    int pref = 0;
    for (int i = 0; i < n; i++) {
        pref += arr[i];
        int req = (pref / (i + 1) + (pref % (i + 1) != 0));
        time = max(time, req);
    }

    debug(time);

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;

        if (x < time) cout << -1 << endl;
        else cout << sm / x + (sm % x != 0) << endl;
    }
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

