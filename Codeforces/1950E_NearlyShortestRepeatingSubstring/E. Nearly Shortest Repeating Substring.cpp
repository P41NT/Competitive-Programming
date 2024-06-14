#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool ok(string curr, string &s, int n) {
    int errors = 0;
    int k = curr.size();
    for (int i = 0; i < n; i++) {
        int j = i % k;
        if (s[i] != curr[j] && ++errors > 1) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = n;
    for (int k = 1; k * k <= n; k++) {
        if (n % k == 0) {
            if (ok(s.substr(0, k), s, n) || ok(s.substr(n - k), s, n)) 
                ans = min(ans, k);
            else if (ok(s.substr(0, n/k), s, n) || ok(s.substr(n - n/k), s, n)) 
                ans = min(ans, n/k);
        }
    }
    cout << ans << endl;
    cerr << endl;
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

