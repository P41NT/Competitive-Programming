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
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i].first;
    for (int i = 0; i < n; i++) cin >> arr[i].second;

    for (int i = 0; i < n; i++) {
        if (arr[i].first > arr[i].second) 
            swap(arr[i].first, arr[i].second);
    }

    sort(arr.begin(), arr.end());

    bool can = false;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1].first <= arr[i].second) can = true;
    }

    debug(arr);

    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer += arr[i].second - arr[i].first;
    }
    if (can) {
        cout << answer << endl;
        return;
    }

    int mn = 1e12;
    for (int i = 0; i < n - 1; i++) {
        int curr = arr[i].second - arr[i].first + arr[i + 1].second - arr[i + 1].first;
        int nw = arr[i + 1].second - arr[i].first + arr[i + 1].first - arr[i].second;
        debug(nw, curr);
        mn = min(mn, nw - curr);
    }

    cout << answer + mn << endl;
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

