#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> limits(n + 1, n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        limits[a] = min(limits[a], b - 1);
    }

    for (int i = n - 1; i >= 1; i--) {
        limits[i] = min(limits[i], limits[i + 1]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (limits[i]) - i + 1;
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

