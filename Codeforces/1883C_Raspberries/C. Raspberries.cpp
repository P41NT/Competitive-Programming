#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

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

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i =  0; i < n; i++) cin >> arr[i];

    if (k == 4) {
        int curr = 0;
        int count = k - 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) curr++;
            count = min(count, (k - (arr[i] % k)) % k);
        }

        debug(n, k, curr, count);
        count = min(count, 2 - min(2ll, curr));
        debug(count);
        cout << count << endl;
    }
    else {
        int curr = 0;
        int count = k - 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) curr++;
            count = min(count, (k - (arr[i] % k)) % k);
        }

        debug(n, k, curr, count);
        debug(count);
        cout << count << endl;
    }
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

