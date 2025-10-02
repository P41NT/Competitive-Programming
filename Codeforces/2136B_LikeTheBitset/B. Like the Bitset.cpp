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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++) {
        arr[i + 1] = s[i] - '0';
    }

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + arr[i];
    }

    for (int i = 0; i + k <= n; i++) {
        if (pref[i + k] - pref[i] == k) {
            cout << "NO" << endl;
            return;
        }
    }

    vector<int> answer(n + 1);
    cout << "YES" << endl;

    debug(arr);

    int temp = 1;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 1) {
            answer[i] = temp++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0) {
            answer[i] = temp++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
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

