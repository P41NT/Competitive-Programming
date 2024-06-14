#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> seg(n);
    for (int i = 0; i < n; i++) cin >> seg[i];

    vector<int> cuts;
    for (int i = 1; i < n; i++) cuts.push_back(seg[i] - seg[i - 1] - 1);
    sort(cuts.begin(), cuts.end(), greater<int>());

    int ans = seg.back() - seg.front() + 1;
    for (int i = 0; i < k - 1 && i < cuts.size(); i++) {
        ans -= cuts[i];
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

