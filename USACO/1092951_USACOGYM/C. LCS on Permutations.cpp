#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/CompetitiveProgramming/debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> brr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> brr[i];

    vector<pair<int, int>> newarr;
    for (int i = 0; i < n; i++) newarr.push_back({brr[i], arr[i]});

    sort(newarr.begin(), newarr.end());

    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = newarr[i].second;

    debug(v);

    vector<int> dp;

    for (int i = 0; i < n; i++) {
        debug(dp);
        int index = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if (index == dp.size()) dp.push_back(v[i]);
        else dp[index] = v[i];
    }
    debug(dp);

    cout << dp.size() << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

