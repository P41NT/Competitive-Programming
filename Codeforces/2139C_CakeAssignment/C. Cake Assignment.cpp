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

void solve() {
    int k, x;
    cin >> k >> x;

    int t = x;
    int n = k;
    while ((t & 1) == 0) {
        t = t >> 1;
        n--;
    }

    int a = (1ll << k);
    int b = (1ll << k);

    vector<int> answer;

    for (int i = 1; i <= n; i++) {
        if (t & (1ll << i)) {
            answer.push_back(2);
            b += a / 2;
            a /= 2;
        }
        else {
            answer.push_back(1);
            a += b / 2;
            b /= 2;
        }
    }

    cout << answer.size() << endl;
    for (auto s : answer) cout << s << " ";
    cout << endl;

    debug(a, b, x);
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

