#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

vector<int> digs(10);

void preprocess() {
    digs[0] = 1;
    for (int k = 1; k <= 9; k++) {
        for (int a = 0; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 9; c++) {
                    if (a + b + c == k) digs[k]++;
                }
                // if (a == b && b == c) digs[k] += 1;
                // else if (a == b || b == c|| a == b) digs[k] += 3;
                // else digs[k] += 6;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    int ans = 1;
    while (n) {
        int dig = n % 10;
        ans *= digs[dig];
        n /= 10;
    }
    cout << ans << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;

	cin >> t;
    preprocess();

    // for (int i = 1; i <= 9; i++) {
    //     cerr << digs[i] << " ";
    // }
    // cerr << endl;

	while ( t-- ) {
		solve();
	}
}

