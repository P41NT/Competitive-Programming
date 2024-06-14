#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool ok(int n, int k, vector<int> &tasks) {
    vector<int> work(n + 1);
    int unallocated = 0;
    for (int s : tasks) {
        if (work[s] + 1 <= k) work[s]++;
        else unallocated++;
    }
    // cerr << n << " " << k << " " <<  unallocated << endl;
    for (int i = 1; i <= n; i++) unallocated -= (k - work[i])/2;
    // cerr << unallocated << endl;

    if (unallocated > 0) return false;
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> tasks(m);
    for (int i = 0; i < m; i++) cin >> tasks[i];

    int left = 0, right = m * 2;
    int ans = right;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (ok(n, mid, tasks)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    // cerr << endl;
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

