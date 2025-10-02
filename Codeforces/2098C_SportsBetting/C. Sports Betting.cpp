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
    int n;
    cin >> n;

    vector<int> arr;
    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    for (auto [x, v] : freq) {
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    debug(arr);

    n = arr.size();

    bool on = false;
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] >= 4) {
            cout << "Yes" << endl;
            return;
        }
        if (freq[arr[i]] >= 2) {
            if (on && arr[i] == arr[i - 1] + 1) {
                cout << "Yes" << endl;
                return;
            }
            else {
                on = true;
            }
        }
        else {
            if (i != 0 && arr[i] > arr[i - 1] + 1) {
                on = false;
            }
        }
    }

    cout << "No" << endl;
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

