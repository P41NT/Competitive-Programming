#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < n; j++) cin >> arr[j][i];

    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][1];
        if (i > 1) dp[i][0] = max(dp[i - 1][1], max(dp[i - 2][0], dp[i - 2][1]));
        dp[i][0] += arr[i][0];
        
        dp[i][1] = dp[i - 1][0];
        if (i > 1) dp[i][1] = max(dp[i - 1][0], max(dp[i - 2][0], dp[i - 2][1]));
        dp[i][1] += arr[i][1];
    }

    int ans = 0;
    for (int j = 0; j < 2; j++){
        for (int i = 0; i < n; i++) 
            ans = max(ans, dp[i][j]);
    }

    cout << ans << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while ( t-- ) {
		solve();
	}
}

