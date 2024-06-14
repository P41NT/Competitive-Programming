#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool ok(vector<int>& arr, int mid, int k) {
    int req = 0;
    for (auto s : arr) 
        req += max(0ll, mid - s);
    return (req <= k);
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    int l = arr.front(), r = 1e13;
    int ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(arr, mid, k)) {
            ans = mid;
            l = mid + 1;
        }
        else { r = mid - 1; }
    }
    int extra = 0, added = 0;
    for (auto &s : arr) {
        int req = max(0ll, ans - s);
        s += req, k -= req;
        if (s > ans) extra++;
        if (s == ans) added++;
    }
    if (k) extra += min(k, added);
    int length = ans * n + extra;
    // cerr << ans << " " << extra << " " << length << endl << endl;
    cout << length - n + 1 << endl;
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

