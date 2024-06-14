#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> delta(n + 2);

    while (q--) {
        int a, b;
        cin >> a >> b;
        delta[a]++;
        delta[b + 1]--;
    }

    vector<int> prod;
    int curr = 0;
    for (int i = 1; i <= n; i++) {
        curr = curr + delta[i];
        prod.push_back(curr);
    }

    sort(prod.begin(), prod.end(), greater<int>());
    sort(arr.begin(), arr.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < n; i++) 
        ans += prod[i] * arr[i];

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

