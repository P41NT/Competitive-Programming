#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr;
    
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        int min_health = 0;
        for (int j = 0; j < k; j++) {
            int l; cin >> l;
            min_health = max(min_health, l - j);
        }
        arr.push_back({min_health, k});
    }
    sort(arr.begin(), arr.end());

    vector<int> pref(n);
    pref[0] = arr[0].second;
    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + arr[i].second;
    
    int ans = arr[0].first;
    for (int i = 1; i < n; i++) {
        ans = max(ans, arr[i].first - pref[i - 1]);
    }
    cout << ans + 1 << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}

