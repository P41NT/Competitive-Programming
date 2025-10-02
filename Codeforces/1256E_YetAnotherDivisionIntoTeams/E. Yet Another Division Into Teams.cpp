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

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first;
    for (int i = 0; i < n; i++) arr[i].second = i;

    sort(arr.begin(), arr.end());

    const int inf = 1e14;
    vector<int> dp(n + 1, inf);
    dp[n - 3] = arr[n - 1].first - arr[n - 3].first;
    dp[n] = 0;

    int mn = arr[n - 1].first;
    int mncurr = n;

    vector<int> nxt(n);
    nxt[n - 3] = n;

    for (int i = n - 4; i >= 0; i--) {
        dp[i] = mn - arr[i].first;
        nxt[i] = mncurr;
        if (dp[i + 2] + arr[i + 1].first < mn) {
            mn = dp[i + 2] + arr[i + 1].first;
            mncurr = i + 2;
        }
    }

    vector<int> diff(n + 1);
    int curr = 0;
    while (curr < n) {
        debug(curr);
        diff[curr] = 1;
        curr = nxt[curr];
    }

    cout << dp[0] << " ";

    vector<int> answer(n);

    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (diff[i]) counter++;
        answer[arr[i].second] = counter;
    }

    cout << counter << endl;
    for (auto s : answer) {
        cout << s << " ";
    }
    cout << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}


