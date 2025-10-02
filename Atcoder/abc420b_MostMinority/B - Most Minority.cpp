#include <algorithm>
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
    int n, m;
    cin >> n >> m;

    vector<string> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> count(n);

    for (int j = 0; j < m; j++) {
        int count0 = 0, count1 = 0;
        vector<int> zero, one;
        for (int i = 0; i < n; i++) {
            if (arr[i][j] == '1') zero.push_back(i);
            if (arr[i][j] == '0') one.push_back(i);
        }

        if (zero.size() > one.size()) {
            for (auto s : one) {
                count[s]++;
            }
        }
        else {
            for (auto s : zero) {
                count[s]++;
            }
        }
    }

    debug(count);

    int mx = *max_element(count.begin(), count.end());

    for (int i = 0; i < n; i++) {
        if (count[i] == mx) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
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

