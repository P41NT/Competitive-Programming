#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n; cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int fin = 0;
    for (int i = 1; i <= n; i++) fin ^= arr[i];
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] ^ arr[i];

    // for (auto s : pref) cerr << s << " ";
    // cerr << endl;

    if (fin == 0) {
        int i = 1;
        while (i < n && pref[i] != (pref[n] ^ pref[i])) i++;
        if (i == n) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    else {
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((pref[n] ^ pref[j]) == (pref[j] ^ pref[i]) 
                        && (pref[j] ^ pref[i]) == pref[i]) {
                   // cerr << i << " " << j << " " << endl;
                   cout << "YES" << endl; 
                   return;
                }
            }
        }
        cout << "NO" << endl;
    }
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

