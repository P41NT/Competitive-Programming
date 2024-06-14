#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        x ^= k;
    }

    if ((x & 1) == (y & 1)) cout << "Alice" << endl;
    else cout << "Bob" << endl;
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

