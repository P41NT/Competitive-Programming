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
#define debugAar(...)
#endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> in(n);
    for (int i = 0; i < n; i++) cin >> in[i];

    while (q--) {
        int k; cin >> k;

        vector<int> arr = in;

        debug(arr);

        int answer = 0;
        for (int bit = 61; bit >= 0; bit--) {
            int mask = (1ull << bit);
            int cost = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] & mask) continue;
                int rem = (mask - 1) & arr[i];
                if (mask - rem > k) {
                    cost = k + 1;
                    break;
                }
                cost += mask - rem;
                if (cost > k) {
                    cost = k + 1;
                    break;
                }
            }
            if (cost <= k) {
                k -= cost;
                answer |= mask;
                for (int i = 0; i < n; i++) {
                    if (arr[i] & mask) continue;
                    int rem = (mask - 1) & arr[i];
                    cost += mask - rem;
                    arr[i] += mask - rem;
                }
            }
            debug(arr);
        }

        cout << answer << endl;
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

