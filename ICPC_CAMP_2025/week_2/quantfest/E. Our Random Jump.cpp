#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <complex.h>
#include <iomanip>

// recursive derrangement formula d(n) = (n - 1) * (d(n - 1) + d(n - 2));

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "debug.cpp"
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

    int a, b;
    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        int x; cin >> x;
        arr[x] = 1;
    }
    for (int i  = 0; i < b; i++) {
        int x; cin >> x;
        arr[x] = 2;
    }

    vector<std::complex<double>> dp(n + 1);

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) dp[i] = 0;
        else if (arr[i] == 2) dp[i] = 1;
    }

    std::complex<double> curr = {0, 0};
    for (int i = n - 1; i >= 1; i--) {
        if (arr[i] != 1 && arr[i] != 2)
            dp[i] = (curr) / double(n - i) + complex<double>(0, 1) / complex<double>(n - i, 0);
        curr += dp[i];
    }

    double dp1 = (dp[1].real()) / (1 - dp[1].imag());

    cout << setprecision(10) << dp1 << endl;
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

