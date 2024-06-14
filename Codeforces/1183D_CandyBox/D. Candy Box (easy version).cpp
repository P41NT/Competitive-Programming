#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        freq[k]++;
    }

    sort(freq.begin(), freq.end());

    int ans = 0;
    vector<bool> visited(n + 1, false);
    for (int i = n; i >= 1; i--) {
        auto it = lower_bound(freq.begin(), freq.end(), i) - freq.begin();
        if (it == n + 1) continue;
        while (it <= n && visited[it]) it++;
        if (it == n + 1) continue;

        ans += i;
        visited[it] = true;
    }

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

