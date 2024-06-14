#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

const int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
    }

    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 1; l * j <= n; l++) {
                int h = l * j;
                dp[i + 1][h] += dp[i][j];
                dp[i + 1][h] %= mod;
            }
        }
    }

    // for (auto s : dp) {
    //     for (int i : s ) cerr << i << " ";
    //     cerr << endl;
    // }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[k][i];
        ans %= mod;
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

