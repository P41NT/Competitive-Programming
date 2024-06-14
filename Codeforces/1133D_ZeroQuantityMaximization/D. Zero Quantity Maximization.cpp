#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    map<pair<int, int>, int> mp;

    int zeroes = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && b[i] == 0) zeroes++;
        if (a[i] == 0) continue;
        int factor = gcd(abs(a[i]), abs(b[i]));
        mp[{((a[i] * b[i] > 0) ? 1 : -1) * abs(a[i]/factor), abs(b[i]/factor)}]++;
    }


    if (mp.empty()) {
        cout << zeroes << endl;
        return;
    }
    int ans = 0;
    for (auto s : mp) 
        ans = max(ans, s.second);


    ans += zeroes;

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

