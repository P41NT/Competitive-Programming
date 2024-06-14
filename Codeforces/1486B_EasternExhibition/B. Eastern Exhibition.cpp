#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++) 
        cin >> x[i] >> y[i];

    sort(x.begin(), x.end()); sort(y.begin(), y.end());

    if (n % 2 == 1) {
        cout << 1 << endl;
        return;
    }

    int medianx1 = x[x.size()/2 - 1], medianx2 = x[x.size()/2];
    int mediany1 = y[y.size()/2 - 1], mediany2 = y[y.size()/2];
    int ans = (medianx2 - medianx1 + 1) * (mediany2 - mediany1 + 1);

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

