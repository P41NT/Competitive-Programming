#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
	// code goes here 
    int n;
    cin >> n;
    vector<vector<int>> ct(n + 1, vector<int>(2));

    vector<int> arr(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i + 2];
    }

    string c; cin >> c;
    c = "N" + c;

    for (int k = n; k >= 1; k--) {
        if (c[k] == 'W') ct[k][0]++;
        else ct[k][1]++;
        ct[arr[k]][0] += ct[k][0];
        ct[arr[k]][1] += ct[k][1];
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)  if (ct[i][0] == ct[i][1]) cnt++;

    cout << cnt << endl;
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

