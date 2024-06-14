#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

int count(int a, int b, vector<int> &row, vector<int> &col) {

    int f = 0, s = 0;
    for (auto j : row) 
        f += max(0ll, j - a + 1);
    for (auto j : col) 
        s += max(0ll, j - b + 1);

    return f * s;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> row(1, 0), col(1, 0);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 1) row.back()++;
        else if (row.back() != 0) row.push_back(0);
    }
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        if (a == 1) col.back()++;
        else if (col.back() != 0) col.push_back(0);
    }

    int ans = 0;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            ans += count(i, k/i, row, col);
            if (i != k/i) ans += count(k/i, i, row, col);
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

