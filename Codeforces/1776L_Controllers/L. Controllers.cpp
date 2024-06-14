#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;
    int plus = 0, minus = 0;
    string s; cin >> s;
    for (char c : s) 
        plus += (c == '+'), minus += (c == '-');

    int mp = minus - plus;

    int q; cin >> q;
    while (q--) {
        if (mp == 0) {
            cout << "YES" << endl;
            continue;
        }
        int x, y;
        cin >> x >> y;
        int xy = x - y;
        int mpy = mp * y;

        if (xy == 0 || mpy % xy != 0) {
            cout << "NO" << endl;
            continue;
        }
        int req = mpy/xy;
        if (req <= plus && req >= -minus) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
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

