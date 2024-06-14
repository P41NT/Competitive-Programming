#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<vector<int>> dp(n + 2, vector<int>(2));
    for (int i = n; i >= 1; i--) {
        dp[i][0] = arr[i] + dp[i + 1][1];
        dp[i][1] = dp[i + 1][0];
        if (i + 1 <= n) {
            dp[i][0] = min(dp[i][0], arr[i] + arr[i + 1] + dp[i + 2][1]);
            dp[i][1] = min(dp[i][1], dp[i + 2][0]);
        }
    }

    // for (int j = 0; j < 2; j++) {
    //     for (int i = 1; i <= n; i++) 
    //         cerr << dp[i][j] << " ";
    //     cerr << endl;
    // }
    cout << dp[1][0] << endl;
    // cerr << endl;
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

