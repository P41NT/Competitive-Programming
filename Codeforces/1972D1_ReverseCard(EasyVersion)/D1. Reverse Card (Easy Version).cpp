#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int b = 1; b <= m; b++) {
        int k = ceil(2.0/(double)(b*b));
        // cerr << b << " ";
        while (k * (b*b) - b <= n) {
            // cerr << (k * (b * b) - b) << " ";
            ans++, k++;
        }
        // cerr << endl;
    }
    // cerr << endl;
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

