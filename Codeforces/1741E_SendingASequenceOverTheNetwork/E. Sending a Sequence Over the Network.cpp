#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

vector<int> dp(2 * 1e5 + 1);

bool solve(int n, vector<int> &arr) {
    if (n == arr.size()) return true;
    // if (n > arr.size()) return false;

    if (dp[n] == 1) return true;
    if (dp[n] == 0) return false;

    bool ans = false;
    if (arr[n] + n + 1 <= arr.size())
        ans |= solve(arr[n] + n + 1, arr);

    if (ans) return dp[n] = ans;

    for (int i = n + 1; i < arr.size(); i++) {
        if (arr[i] == i - n)
            ans |= solve(i + 1, arr);
        if (ans) return dp[n] = ans;
    }

    return dp[n] = ans;
}

void solve() {

    int n;
    cin >> n;

    // for (int i = 0; i <= n; i++) dp[i] = -1;
    // dp[n] = 1;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    for (int i = 0; i <= n; i++) dp[i] = 0;

    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] + i + 1 <= n)
            dp[i] |= dp[arr[i] + i + 1];
        if (i - arr[i] >= 0)
            dp[i - arr[i]] |= dp[i + 1];
    }

    cout << (dp[0] ? "YES" : "NO") << endl;
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

