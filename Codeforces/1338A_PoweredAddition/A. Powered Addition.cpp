#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int max_diff = 0;
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        max_diff = max(max_diff, mx - arr[i]);
        mx = max(mx, arr[i]);
    }
    cout << ceil(log2(max_diff + 1)) << endl;
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

