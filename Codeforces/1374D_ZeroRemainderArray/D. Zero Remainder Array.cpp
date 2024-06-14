#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;

    map<int, int> arr;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        if (m % k == 0) continue;
        arr[k - m%k]++;
    }

    int mx = 0;
    int mx_index = 0;
    for (auto s : arr) {
        if (s.second >= mx){
            mx = s.second;
            mx_index = s.first;
        }
    }
    int ans = (mx - 1) * k + mx_index + 1;
    if (mx == 0) cout << 0 << endl;
    else cout << ans << endl;
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

