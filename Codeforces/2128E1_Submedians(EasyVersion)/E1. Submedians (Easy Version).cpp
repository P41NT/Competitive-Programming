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
template<class T>
using ordered_multiset_p = tree<
    pair<T,int>, null_type, less<pair<T,int>>,
    rb_tree_tag, tree_order_statistics_node_update>;

// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (k == n) {
        ordered_multiset<int> os;
        for (int i = 0; i < k; i++) {
            os.insert(arr[i]);
        }
        cout << *os.find_by_order(n / 2) << " " << 1 << " " << k << endl;
    }
    else {
        if (k & 1) k++;

        ordered_multiset_p<int> os;
        int uid = 0;
        for (int i = 0; i < k; i++) {
            os.insert({arr[i], uid++});
        }

        debug(os);

        int answer = os.find_by_order(k / 2)->first;
        int lb = 1, rb = k;

        for (int i = k; i < n; i++) {
            debug(i);
            os.insert({arr[i], uid++});
            debug(arr[i - k], *os.lower_bound({arr[i - k], -1}));
            os.erase(os.lower_bound({arr[i - k], -1}));

            debug(os);

            int curr = os.find_by_order(k / 2)->first;
            if (curr > answer) {
                answer = curr;
                lb = i + 2 - k;
                rb = i + 1;
            }
        }

        cout << answer << " " << lb << " " << rb << endl;
        cerr << endl;
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

