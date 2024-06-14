#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

const int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> arr(1, 0);

    int i = 0;
    while (i < n && s[i] != 'a') i++;

    for (; i < n; i++) {
        if (s[i] == 'a') arr.back()++;
        else if (s[i] == 'b' && arr.back() != 0) arr.push_back(0);
    }

    // for (auto s : arr) cerr << s << " ";
    // cerr << endl;

    int ans = 1;
    for (auto s : arr) {
        if (s == 0) continue;
        ans *= (1 + s%mod)%mod;
        ans %= mod;
    }
    ans = (mod + ans - 1) % mod;

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

