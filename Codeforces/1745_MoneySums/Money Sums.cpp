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
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<bool> dp(1e6 + 5, false);
    vector<bool> newdp(1e6 + 5, false);

    dp[0] = true;
    newdp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= 1e6; j++) 
            newdp[j] = newdp[j] | dp[j - arr[i]];

        for (int j = 1; j <= 1e6; j++) {
            dp[j] = dp[j] | newdp[j];
            newdp[j] = false;
        }
    }

    vector<int> answer;
    for (int i = 1; i <= 1e6; i++) 
        if (dp[i]) answer.push_back(i);

    cout << answer.size() << endl;
    for (auto s : answer) cout << s << " ";
    cout << endl;
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

