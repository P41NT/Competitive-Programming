#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << (n/2 + 1) * (n /2 + 1) << endl;
    }
    else {
        cout << 2 * (n/2 + 1) * (n/2 + 2) << endl;
    }
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

