#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

vector<vector<int>> dp(105, vector<int>(105));

bool check(int n, int m, vector<vector<int>> &arr, int factor) {

    for (int i = 0; i < n; i++) 
        dp[i].assign(m, 0);

    dp[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (arr[i][j] % factor != 0) continue;
            if (i + 1 < n) dp[i][j] |= dp[i + 1][j];
            if (j + 1 < m) dp[i][j] |= dp[i][j + 1];
        }
    }

    // cerr << factor << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cerr << dp[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    return dp[0][0];
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> arr[i][j];

    int g = gcd(arr[0][0], arr[n - 1][m - 1]);

    int ans = 1;
    for (int k = 1; k * k <= g; k++) {
        if (g % k == 0) {
            if (check(n, m, arr, k)) ans = max(ans, k);
            if (k == g/k) continue;
            if (check(n, m, arr, g/k)) ans = max(ans, g/k);
        }
    }
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

