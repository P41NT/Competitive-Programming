#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define debug(...)
#define debugArr(...)

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        int mx = arr[i];
        int answer = 0;
        for (int j = i - 1; j >= 0 && (i - j) <= k; j--) {
            int curr = dp[j] + mx * (i - j);
            answer = max(answer, curr);
            debug(curr, i, j);
            mx = max(mx, arr[j]);
        }
        dp[i] = answer;
    }
    debug(dp);
    cout << dp[n] << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    int t = 1;
	while (t--) {
        solve();
	}
}

