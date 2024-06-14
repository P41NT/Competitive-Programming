#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> suffix(n + 2);
    suffix[n + 1] = 0;

    for (int i = n; i >= 1; i--) suffix[i] = suffix[i + 1] + arr[i];

    // for (auto s : arr) cerr << s << " ";
    // cerr << endl;
    // for (auto s : suffix) cerr << s << " ";
    // cerr << endl;

    int ans = 0;
    int curr = 0;
    for (int i = 1; i <= n; i++) {
        ans += b * (arr[i] - arr[curr]);
        int shifting = (arr[i] - arr[curr]) * a;
        int cost_shifted = (suffix[i + 1] - arr[i] * (n - i))*b;
        int cost_now = (suffix[i + 1] - arr[curr] * (n - i)) * b;
        if (shifting + cost_shifted <= cost_now) ans += shifting, curr = i;
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

