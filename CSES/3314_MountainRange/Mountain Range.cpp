#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/segtree.hpp>

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

int op(int a, int b) {
    return max(a, b);
}
int e() {
    return INT_MIN;
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<pair<int, int>> temp(n);

    atcoder::segtree<int, op, e> dp(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        temp[i] = {arr[i], i};
    }

    sort(temp.begin(), temp.end());

    vector<int> greaterLeft(n, -1);
    vector<int> greaterRight(n, n);

    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > st.top().first) {
            st.pop();
        }
        if (!st.empty()) {
            greaterLeft[i] = st.top().second;
        }
        st.push({arr[i], i});
    }

    while (st.size()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] > st.top().first) {
            st.pop();
        }
        if (!st.empty()) {
            greaterRight[i] = st.top().second;
        }
        st.push({arr[i], i});
    }

    debug(greaterLeft);
    debug(greaterRight);

    for (int i = 0; i < n; i++) {
        dp.set(i, 1);
    }

    for (auto [val, ind] : temp) {
        int mx = dp.get(ind);
        mx = max(mx, 1 + dp.prod(greaterLeft[ind] + 1, ind));
        mx = max(mx, 1 + dp.prod(ind + 1, greaterRight[ind]));

        dp.set(ind, mx);
    }

    for (int i = 0; i < n; i++ ){
        cerr << dp.get(i) << " ";
    }
    cerr << endl;

    cout << dp.all_prod() << endl;
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

