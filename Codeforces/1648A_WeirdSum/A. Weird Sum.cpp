#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

const int COLORS = 100000;

void solve() {
    int n, m; 
    cin >> n >> m;

    vector<vector<int>> inp(n, vector<int>(m));

    for (int i = 0; i < n; i++) 
        for (int j = 0 ; j < m; j++) 
            cin >> inp[i][j];

    vector<vector<int>> row(COLORS + 1);
    vector<vector<int>> col(COLORS + 1);

    int mx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            row[inp[i][j]].push_back(i);
            col[inp[i][j]].push_back(j);
            mx = max(mx, inp[i][j]);
        }
    }

    int ans = 0;
    for (int color = 1; color <= mx; color++) {
        int sum_1 = 0;
        int sum_2 = 0;
        int n_ = row[color].size();
        sort(col[color].begin(), col[color].end());
        for (int i = 0; i < n_; i++) sum_1 += i * row[color][i];
        for (int i = 0; i < n_; i++) sum_2 += (n_ - 1 - i) * row[color][i];
        ans += sum_1 - sum_2;
    }

    for (int color = 1; color <= mx; color++) {
        int sum_1 = 0;
        int sum_2 = 0;
        int n_ = col[color].size();
        sort(col[color].begin(), col[color].end());
        for (int i = 0; i < n_; i++) sum_1 += i * col[color][i];
        for (int i = 0; i < n_; i++) sum_2 += (n_ - 1 - i) * col[color][i];
        ans += sum_1 - sum_2;
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

