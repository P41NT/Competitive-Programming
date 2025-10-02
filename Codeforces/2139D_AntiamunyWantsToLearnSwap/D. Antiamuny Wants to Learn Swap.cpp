#include <atcoder/segtree.hpp>
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

// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);


int op(int x, int y) {
    return min(x, y);
}
int e() {
    return 1e12;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> prevLarge(n, -1);
    vector<int> nextSmall(n, n);

    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        while (st.size() && arr[i] >= st.top().first) {
            st.pop();
        } 
        if (st.size()) {
            prevLarge[i] = st.top().second;
        }
        st.push({arr[i], i});
    }

    while (st.size()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (st.size() && arr[i] <= st.top().first) {
            st.pop();
        } 
        if (st.size()) {
            nextSmall[i] = st.top().second;
        }
        st.push({arr[i], i});
    }

    vector<int> nextInd(n, n);
    for (int i = 0; i < n; i++) {
        if (prevLarge[i] == -1 || nextSmall[i] == n) continue;
        nextInd[prevLarge[i]] = min(nextInd[prevLarge[i]], nextSmall[i]);
    }

    debug(nextInd);

    atcoder::segtree<int, op, e> segs(nextInd);

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        int x = segs.prod(l, r + 1);
        if (x <= r) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
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

