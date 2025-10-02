#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/lazysegtree.hpp>
#include <atcoder/segtree.hpp>
#include <atcoder/modint.hpp>
#include <atcoder/dsu.hpp>

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
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);
    for (int i = 0; i <= n; i++) cin >> arr[i];

    vector<int> temp(n + 1);
    while (k--) {
        double x;
        cin >> x;

        for (int i = 0; i <= n; i++) {
            temp[i] = arr[i] - x * i * 10;
        }

        debug(temp);

        stack<pair<int, int>> st;
        int answer = -1;

        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (temp[i + 1] >= temp[i]) {
                ok = true;
                break;
            }
        }

        if (!ok) {
            cout << -1 << endl;
            return;
        }

        st.push({temp[n], n});
        for (int i = n - 1; i >= 0; i--) {
            debug(st);
            while (!st.empty() && temp[i] > st.top().first) st.pop();
            if (!st.empty()) {
                answer = max(answer, st.top().second - i);
                debug(st.top().second, i);
            }
            if (st.empty() || st.top().first != temp[i]) st.push({temp[i], i});
        }

        cout << answer << endl;
        cerr << endl;
    }
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

