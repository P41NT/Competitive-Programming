#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    int ones = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ones += (arr[i] == 1);
    }
    

    if (ones) {
        cout << arr.size() - ones << endl;
        return;
    }
    
    // if one exists -> todo;

    int mn = LONG_MAX;
    for (int i = 0; i < n - 1; i++) {
        int g = arr[i];
        for (int j = i + 1; j < n; j++) {
            g = gcd(g, arr[j]);
            if (g == 1) {
                mn = min(mn, j - i);
                break;
            }
        }
    }
    if (mn == LONG_MAX) cout << -1 << endl;
    else cout << mn + arr.size() - 1<< endl;
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

