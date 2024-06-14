#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
	// code goes here 
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int bit = 30; bit >= 0; bit--) {
        int cnt = 0;
        for (int i = 0; i < n; i++) 
            cnt += (arr[i] & (1 << bit)) ? 1 : 0; 

        if ((n - cnt) <= k) {
            k -= (n - cnt);
            ans += (1 << bit);
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

