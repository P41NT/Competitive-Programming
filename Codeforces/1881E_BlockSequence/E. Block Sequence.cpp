#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    vector<int> dp(n + 2, n + 1);
    dp[n + 1] = 0;

    for (int i = n; i >= 1; i--) {
        int next = i + arr[i] + 1;
        dp[i] = dp[i + 1] + 1;
        if (next <= n + 1) dp[i] = min(dp[i], dp[next]);
    }

    int ans = n;
    for (int i = 1; i <= n; i++) 
        ans = min(ans, i - 1 + dp[i]);

    cout << ans << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while ( t-- ) {
		solve();
	}
}

