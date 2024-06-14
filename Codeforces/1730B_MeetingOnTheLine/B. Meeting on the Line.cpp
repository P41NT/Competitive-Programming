#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), t(n);

    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> t[i];

    int ans_time = LONG_MAX;
    int l = 0, r = LONG_MAX;
    int position;
    bool ishalf = false;
    while (l <= r) {
        int mid = (l + r) >> 1;
        
        int rmax = LONG_MAX;
        int lmax = LONG_MIN;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (mid < t[i]) {
                flag = false;
                break;
            }
            int remtime = mid - t[i];
            lmax = max(lmax, x[i] - remtime);
            rmax = min(rmax, x[i] + remtime);
        }
        if (rmax < lmax) flag = false;

        if (flag) {
            if (mid < ans_time) {
                position = (rmax + lmax) >> 1;
                ishalf = (rmax + lmax) & 1;
            }
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << position << (ishalf? ".5" : "") << endl;
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

