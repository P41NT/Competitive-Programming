#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end());

    int tv1 = arr[0].second;
    int i = 1;
    for (; i < n; i++) {
        auto s = arr[i];
        if (s.first > tv1) tv1 = max(tv1, s.second);
        else break;
    }
    // cerr << arr[i].first << " " << arr[i].second << endl;
    int tv2 = arr[i].second;
    for (int j = i + 1; j < n; j++) {
        // cjrr << j << " " << tv1 << " " << tv2 << endl;
        auto s = arr[j];
        if (s.first <= tv1 && s.first <= tv2) {
            cout << "NO" << endl;
            return;
        }
        if (s.first > tv1 && s.first > tv2) {
            if (tv1 < tv2) tv2 = max(tv2, s.second);
            else tv1 = max(tv1, s.second);
        }
        else if (s.first <= tv1) tv2 = max(tv2, s.second);
        else tv1 = max(tv1, s.second);
    }

    cout << "YES" << endl;
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
