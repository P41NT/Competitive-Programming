#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int r = k;
    int i = 0, j = n - 1;
    int ans = 0;
    while (i < j && r) {
        // cerr << i << " " << j << " " << r << endl;
        // for (auto s : arr) cerr << s << " ";
        // cerr << endl;
        if (arr[i] > arr[j]) {
            // cerr << "first" << endl;
            if (arr[j] * 2 <= r) {
                r -= arr[j] * 2;
                arr[i] -= arr[j], arr[j] = 0;
                ans++;
                j--;
            }
            else {
                arr[i] -= r/2;
                arr[j] -= r/2;
                if (r % 2 == 1) arr[i] = max(0ll, arr[i] - 1);
                if (arr[i] == 0) ans++;
                if (arr[j] == 0) ans++;
                r = 0;
            }
        }
        else if (arr[i] < arr[j]) {
            // cerr << "second" << endl;
            if (arr[i] * 2 <= r) {
                r -= arr[i] * 2;
                arr[j] -= arr[i], arr[i] = 0;
                ans++;
                i++;
            }
            else {
                arr[i] -= r/2;
                arr[j] -= r/2;
                if (r % 2 == 1) arr[i] = max(0ll, arr[i] - 1);
                if (arr[i] == 0) ans++;
                if (arr[j] == 0) ans++;
                r = 0;
            }
        }
        else {
            // cerr << "third" << endl;
            if (arr[i] * 2 <= r) {
                r -= arr[i] * 2;
                arr[i] = 0, arr[j] = 0;
                ans += 2;
                i++, j--;
            }
            else {
                arr[i] -= r/2;
                arr[j] -= r/2;
                if (r % 2 == 1) arr[i] = max(0ll, arr[i] - 1);
                if (arr[i] == 0) ans++;
                if (arr[j] == 0) ans++;
                r = 0;
            }
        }
    }

    if (i == j && r >= arr[i]) ans++, arr[i] = 0;

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

