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

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        st.insert(arr[i]);
    }

    int g = abs(arr[n - 1] - arr[0]);
    for (int i = 1; i < n; i++) {
        int diff = abs(arr[i] - arr[i - 1]);
        g = gcd(g, diff);
    }

    debug(g);

    int mx = *max_element(arr.begin(), arr.end());

    debug(mx);

    if (g == 0) {
        cout << n << endl;
        return;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (mx - arr[i]) / g;
    }

    int curr = mx;
    while (st.count(curr)) curr -= g;

    ans += (mx - curr) / g;
    cout << ans << endl;
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

