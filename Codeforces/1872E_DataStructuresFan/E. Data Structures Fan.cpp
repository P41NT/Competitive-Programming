#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    string s; cin >> s;

    int ans0 = 0, ans1 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') ans0 ^= arr[i];
        else ans1 ^= arr[i];
    }

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] ^ arr[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int l, r; cin >> l >> r;
            int req = pref[r] ^ pref[l - 1];
            ans0 ^= req; ans1 ^= req;
        }
        else {
            int w; cin >> w;
            if (w == 0) cout << ans0 << " ";
            if (w == 1) cout << ans1 << " ";
        }
    }
    cout << endl;
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

