#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool ok(int k, vector<pair<int, int>> &seg) {
    int left_range = 0, right_range = 0;
    for (auto s : seg) {
        left_range = max(left_range - k, s.first);
        right_range = min(right_range + k, s.second);
        if (left_range > right_range) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    int left = 0, right = 0;
    vector<pair<int, int>> seg(n);
    for (int i = 0; i < n; i++) cin >> seg[i].first >> seg[i].second;

    for (auto s : seg) right = max(right, s.second);

    int ans = right;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (ok(mid, seg)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
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

