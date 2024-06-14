#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

int get(int a) {
    return a * (a + 1) / 2;
}

int get_val(int n, int level){
    if (level <= n) return get(level);
    return (get(n) + get(n-1) - get(2*n-1 - level));
}

void solve() {
    int n, k;
    cin >> n >> k;

    if (k >= get(n) + get(n - 1)) {
        cout << 2*n - 1 << endl;
        return;
    }

    int ans = 0;
    int l = 1, r = 2*n-1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (get_val(n, mid) >= k) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
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
