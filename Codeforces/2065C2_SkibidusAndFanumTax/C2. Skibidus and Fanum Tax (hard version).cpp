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
#define debugArr(...)
#endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    vector<int> brr(m);

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) cin >> brr[i];


    sort(brr.begin(), brr.end());

    arr[0] = min(brr[0] - arr[0], arr[0]);


    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1] && brr[m - 1] - arr[i] < arr[i - 1]) {
            cout << "NO" << endl;
            return;
        }
        debug(i);
        // we want brr[j] - arr[i] >= arr[i - 1]
        // => brr[j] >= arr[i - 1] + arr[i]
        int req = lower_bound(brr.begin(), brr.end(), arr[i - 1] + arr[i]) - brr.begin();
        if (req == m) {
            continue;
        }
        if (arr[i] >= arr[i - 1]) {
            arr[i] = min(arr[i], brr[req] - arr[i]);
        }
        else arr[i] = brr[req] - arr[i];
    }

    debug(arr);

    cout << "YES" << endl;
    return;
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

