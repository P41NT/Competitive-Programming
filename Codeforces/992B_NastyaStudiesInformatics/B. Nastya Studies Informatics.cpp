#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int l, r, x, y;
    cin >> l >> r >> x >> y;

    int ans = 0;
    int product = y/x;

    if (y % x != 0) {
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i * i <= product; i++) {
        if (product % i == 0) {
            int j = product/i;
            if (gcd(i, j) != 1) continue;
            int a = i * x, b = j * x;

            if (a >= l && b <= r) {
                if (i == j) ans += 1;
                else ans += 2;
            }

            // cerr << a << " " << b << endl;
        }
    }
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

