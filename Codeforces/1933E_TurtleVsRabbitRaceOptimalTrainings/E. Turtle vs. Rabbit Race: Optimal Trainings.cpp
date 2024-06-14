#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + arr[i];

    // for (auto s : pref) cerr << s << " ";
    // cerr << endl;

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;

        int s1 = lower_bound(pref.begin(), pref.end(), pref[u - 1] + v) - pref.begin();
        int s2 = s1 - 1;
        s1 = min(n, s1);
        s2 = max(s2, u);

        int t1 = pref[s1] - pref[u - 1];
        int t2 = pref[s2] - pref[u - 1];

        // cerr << pref[u-1] + v << endl;
        int x1 = t1 * (2 * v - (t1 - 1))/2;
        int x2 = t2 * (2 * v - (t2 - 1))/2;

        // cerr << pref[s1] << " " << pref[s2] << " " << t1 << " " << t2 << " " << x1 << " "<< x2 << endl;

        if (x1 > x2) cout << s1 << " ";
        else cout << s2 << " ";
    }
    cout << endl;
    // cerr << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
    
    // vector<int> arr = {2, 5, 6, 9, 10};
    // int s = lower_bound(arr.begin(), arr.end(), 6) - arr.begin();
    // cerr << s << endl;


	while ( t-- ) {
		solve();
	}
}


