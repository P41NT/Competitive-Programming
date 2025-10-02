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
    int n, p, k;
    cin >> n >> p >> k;

    vector<int> dp(1 << p, -1);
    vector<int> newdp(1 << p, -1);
    // vector<vector<int>> dp(k + 1, vector<int>(1 << p));
    // vector<vector<int>> newdp(k + 1, vector<int>(1 << p));

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<pair<int, vector<int>>> s(n);
    for (int i = 0; i < n; i++) {
        s[i].first = arr[i];
        s[i].second = vector<int>(p);
        for (int j = 0; j < p; j++) {
            cin >> (s[i].second)[j];
        }
    }

    sort(s.begin(), s.end(), greater<pair<int, vector<int>>>());

    debug(s);

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1ll << p); j++) {
            if (i - __builtin_popcount(j) < k) {
                if (dp[j] != -1) 
                    newdp[j] = max(newdp[j], dp[j] + s[i].first);
            }
            else {
                if (dp[j] != -1)
                    newdp[j] = max(newdp[j], dp[j]);
            }
            for (int k = 0; k < p; k++) {
                if (j & (1ll << k)) {
                    int prevDp = dp[j ^ (1ll << k)];
                    if (prevDp != -1) 
                        newdp[j] = max(newdp[j], prevDp + (s[i].second)[k]);
                }
            }
        }
        debug(newdp);
        dp = newdp;
        newdp = vector<int>(1ll << p, -1);
    }

    cout << dp[(1ll << p) - 1] << endl;
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

