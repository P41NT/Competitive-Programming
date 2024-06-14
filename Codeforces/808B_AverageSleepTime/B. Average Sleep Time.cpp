#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
// #define int long long int

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> mul(n, 1);
    if (n != k) {
        int l = min(k, n - k + 1);
        for (int i = 0; i < l - 1; i++) mul[i] = i + 1;
        // for (int i = 0; i < n; i++) cerr << mul[i] << " ";
        // cerr << endl;
        for (int i = l - 1; i <= n - l; i++) mul[i] = l;
        // for (int i = 0; i < n; i++) cerr << mul[i] << " ";
        // cerr << endl;
        for (int i = n - l + 1; i < n; i++) mul[i] = --l;
        // for (int i = 0; i < n; i++) cerr << mul[i] << " ";
        // cerr << endl;
    }

    // for (int i = 0; i < n; i++) 
    //     cerr << mul[i] << " ";
    // cerr << endl;

    double sum = 0;
    for (int i = 0; i < n; i++) sum += (double) arr[i] * mul[i];

    double ans = sum / (double)(n - k + 1);
    cout << fixed << setprecision(10) << ans << endl;
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

