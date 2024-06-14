#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int


void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pairs(m);
    for (auto &s : pairs)  cin >> s.first >> s.second;

    int q; cin >> q;
    vector<int> sec(q);
    for (auto &s : sec) cin >> s;

    // for (auto s : sec)  cerr << s << " ";
    // cerr << endl;

    vector<int> arr(n + 1);
    vector<int> pref(n + 1);

    int l = 0, r = q;
    int ans = n + 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        for (auto &s : arr) s = 0;

        for (int i = 0; i < mid; i++) 
            arr[sec[i]] = 1;
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + arr[i];

        // cerr << mid << endl;
        // for (auto s : arr) cerr << s << " ";
        // cerr << endl;

        bool done = false;
        for (auto s : pairs) {
            if (pref[s.second] - pref[s.first - 1] > (s.second - s.first + 1)/2) {
                // cerr << s.second << " " << s.first << endl;
                done = true;
                break;
            }
        }
        if (done) {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }

    // cerr << endl;
    cout << (ans <= n ? ans : -1) << endl;
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

