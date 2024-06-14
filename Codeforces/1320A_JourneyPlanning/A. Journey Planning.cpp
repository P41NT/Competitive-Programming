#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    map<int, int> paths;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        paths[k - i] += k;
    }

    int ans = 0;
    for (auto s : paths) ans = max(ans, s.second);

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

