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

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int count = 0;
    bool zero = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) count++;
        else zero = true;
    }

    vector<int> mx(n + 1);
    vector<int> mx2(n + 1);

    vector<bool> b(n + 1);
    int mex = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] <= n) b[arr[i]] = true;
        while (b[mex]) mex++;
        mx[i] = mex;
    }

    vector<bool> b1(n + 1);
    mex = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] <= n) b1[arr[i]] = true;
        while (b1[mex]) mex++;
        mx2[i] = mex;
    }

    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        debug(i, mn, mx[i + 1]);
        if (arr[i] == 0) {
            count++;
            break;
        }
        mn = min(mn, arr[i]);
        if (mn < mx[i + 1]) break;
    }
    cerr << endl;
    cout << count << endl;
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

