#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        for (int fac = 1; fac * fac <= i; fac++) {
            if (i % fac == 0) {
                if (arr[fac] < arr[i]) dp[i] = max(dp[i], dp[fac] + 1);
                if (arr[i/fac] < arr[i]) dp[i] = max(dp[i], dp[i/fac] + 1);
            }
        }
    }

    int ans = *max_element(dp.begin(), dp.end());
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

