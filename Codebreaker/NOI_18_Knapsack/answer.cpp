#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "../../debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int s, n;
    cin >> s >> n;

    vector<int> v(n);
    vector<int> w(n);
    vector<int> k(n);

    for (int i = 0; i < n; i++) cin >> v[i] >> w[i] >> k[i];

    vector<vector<pair<int, int>>> temp(2001);

    for (int i = 0; i < n; i++) {
        temp[w[i]].push_back({v[i], k[i]});
    }

    for (int i = 1; i <= 2000; i++) 
        sort(temp[i].begin(), temp[i].end(), greater<pair<int, int>>());

    vector<pair<int, int>> arr(1);

    for (int i = 1; i <= 2000; i++) {
        int curr = 0;
        int mx = s / i;
        for (auto pr : temp[i]) {
            if (curr + pr.second > mx) {
                for (int k = 0; k < mx - curr; k++) {
                    arr.push_back({i, pr.first});
                }
            }
            else {
                for (int k = 0; k < pr.second; k++) {
                    arr.push_back({i, pr.first});
                }
            }
        }
    }

    debug(arr);

    int nn = arr.size();
    // vector<vector<int>> dp(nn, vector<int>(s + 1));
    
    vector<int> dp(s + 1);
    vector<int> newdp(s + 1);

    for (int i = 1; i < nn; i++) {
        newdp = dp;
        for (int j = 0; j <= s; j++) {
            if (j - arr[i].first >= 0) {
                newdp[j] = max(newdp[j], dp[j - arr[i].first] + arr[i].second);
            }
        }
        dp = newdp;
    }
    cout << dp[s] << endl;
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

