#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

vector<int> dp(1e3 + 10, INT_MAX);

void preprocess() {
    dp[1] = 0;

    for (int i = 1; i <= 1e3; i++) {
        for (int k = 1; k <= i; k++) {
            int j = i + i / k;
            if (j <= 1e3) dp[j] = min(dp[j], dp[i] + 1);
        }
    }
}

vector<int> dpknapsack(1e6 + 10, 0);

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> b(n);
    vector<int> c(n);

    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];


    vector<pair<int, int>> arr(n);
    int maxk = 0;
    for (int i = 0; i < n; i++) {
        arr[i].first = dp[b[i]];
        arr[i].second = c[i];
        maxk += arr[i].first;
    }

    k = min(maxk, k);

    for (int i = 0; i <= k; i++) dpknapsack[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int x = k; x >= 0; x--) {
            if (x + arr[i].first <= k) {
            dpknapsack[x + arr[i].first] = 
                max(dpknapsack[x + arr[i].first], dpknapsack[x] + arr[i].second);
            }
        }
    }

    int mx = 0;
    for (int i = 0; i <= k; i++) mx = max(mx, dpknapsack[i]);
    cout << mx << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    preprocess();

	int t = 1;
	cin >> t;
	while ( t-- ) {
		solve();
	}
}

