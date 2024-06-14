#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    map<int, int> curr;
    map<int, int> req;
    vector<int> arr(n);
    vector<int> ref(m);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) {
        cin >> ref[i];
        req[ref[i]]++;
    }
    int current = 0;
    for (int i = 0; i < m; i++) {
        if (req[arr[i]]) {
            if (curr[arr[i]] < req[arr[i]]) current++;
            curr[arr[i]]++;
        }
    }
    // for (auto s : req) cerr << s.first << " " << s.second << endl;
    // cerr << endl;
    int ans = 0;
    for (int i = 0; i + m <= n; i++) {
        if (current >= k) ans++;

        // for (auto s : curr) cerr << s.first << " " << s.second << endl;
        // cerr << ans << " " << current << " " << k << endl << endl;

        if (req[arr[i]]) {
            if (curr[arr[i]] <= req[arr[i]]) current--;
            curr[arr[i]]--;
        }
        int j = i + m;
        if (req[arr[j]]) {
            if (curr[arr[j]] < req[arr[j]]) current++;
            curr[arr[j]]++;
        }
    }

    cout << ans << endl;
    // cerr << endl << endl;
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

