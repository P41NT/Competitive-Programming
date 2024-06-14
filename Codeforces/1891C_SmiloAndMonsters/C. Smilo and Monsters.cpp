#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &s : arr) cin >> s;

    sort(arr.begin(), arr.end());

    int i = 0, j = n - 1;
    int charge = 0;
    int ans = 0;
    while (i < j) {
        if (charge + arr[i] >= arr[j]) {
            int req = arr[j] - charge;
            // cerr << req << " " << arr[j] << endl;
            ans += req;
            arr[i] -= req;
            charge += req;
        }
        else {
            charge += arr[i];
            ans += arr[i];
            arr[i] = 0;
            i++;
        }
        if (charge == arr[j]) {
            charge = 0;
            arr[j] = 0;
            j--;
            ans++;
        }
        // cerr << i << " " << j << " " << ans << " " << charge << " " << endl;
    }
    if (arr[i]) {
        // cerr << arr[i] << " " << charge << endl;
        if (arr[i] == charge) ans++;
        else if (arr[i] == 1) ans++;
        else {
            int req = (arr[i] - charge)/2;
            charge += req;
            arr[i] -= req;
            ans += req;
            arr[i] -= charge;
            ans++;
            charge = 0;
            ans += arr[i];
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

