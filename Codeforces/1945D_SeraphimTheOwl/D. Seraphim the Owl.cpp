#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    vector<int> brr(n);
    vector<int> suff(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> brr[i];

    for (int i = m - 1; i > 0; i--) {
        suff[i] = brr[i];
        if (i < m - 1) suff[i] += suff[i + 1];
    }

    int ans = LONG_MAX;
    for (int i = 0; i < n; i++) {
        if (i < m) ans = min(ans, arr[i] + ((i < m - 1)? suff[i + 1] : 0));
        else ans += min(arr[i], brr[i]);
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

