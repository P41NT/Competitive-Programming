
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

vector<int> factorials;
vector<pair<int, int>> sums;

void preprocess() {
    factorials.push_back(6);
    for (int i = 4; i <= 16; i++) factorials.push_back(factorials.back() * i);
    int num = 1 << (factorials.size() - 1);

    for (int bitmask = 0; bitmask <= num; bitmask++) {
        int sum = 0;
        for (int bit = 0; (1 << bit) <= num; bit++) {
            int ch = 1 << bit;
            if (ch & bitmask) sum += factorials[bit];
        }
        if (sum >= 0 && sum <= 1e12) sums.push_back({sum, __builtin_popcount(bitmask)});
    }
    sort(sums.begin(), sums.end());
}

void solve() {
    int n; cin >> n;

    int ans = __builtin_popcountll(n);
    for (auto c : sums) {
        if (c.first > n) break;
        ans = min(ans, c.second + __builtin_popcountll(n - c.first));
    }
    cout << ans << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    preprocess();

	int t = 1;
	cin >> t;
	while ( t-- ) {
		solve();
	}
}

