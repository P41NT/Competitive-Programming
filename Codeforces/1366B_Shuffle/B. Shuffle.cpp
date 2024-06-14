#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, x, m;
    cin >> n >> x >> m;

    pair<int, int> extremes = {x, x};
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        if (l <= extremes.second) extremes.second = max(extremes.second, r);
        if (r >= extremes.first) extremes.first = min(extremes.first, l);
    }

    cout << extremes.second - extremes.first + 1 << endl;
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

