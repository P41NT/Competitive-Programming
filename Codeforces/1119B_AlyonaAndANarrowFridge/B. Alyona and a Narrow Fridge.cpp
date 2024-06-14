#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool calculate(vector<int> &sub, int n, int height) {
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) arr[i] = sub[i];


    sort(arr.rbegin(), arr.rend());

    // cerr << n << " ";
    // for (auto s : arr) cerr << s << " ";
    // cerr << endl;

    int sum = 0;
    for (int i = 0; i < n; i += 2) sum += arr[i];

    if (sum <= height) return true;
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    int ans = 2;

    int left = 1, right = n;
    while (left <= right) {
        int mid = (left + right) >> 1;
        // bool calc = calculate(arr, mid, k);
        // cerr << left << " " << right << " " << mid << " " << calc << endl; 
        if (calculate(arr, mid, k)) {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout << ans << endl;
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

