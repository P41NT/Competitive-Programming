#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <atcoder/segtree>

using namespace std;
using namespace __gnu_pbds;
using namespace atcoder;

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

int op(int a, int b) {
    return gcd(a, b);
}
int e() {
    return (int)0;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) { cin >> arr[i]; }

    vector<int> diff(n - 1);
    for (int i = 1; i < n; i++) { diff[i - 1] = abs(arr[i] - arr[i - 1]); }

    segtree<int, op, e> seg(diff);

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == r) { cout << 0 << " "; }
        else {
            int answer = seg.prod(l, r);
            cout << answer << " ";
        }
    }
    cout << endl;
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

