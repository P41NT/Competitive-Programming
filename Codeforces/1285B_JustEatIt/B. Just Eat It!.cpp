#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n; 
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int curr = 0, max = 0;
    for (int i = 0; i < n - 1; i++) {
        curr += arr[i];
        if (curr > max) max = curr;
        if (curr < 0) curr = 0;
    }
    curr = 0;
    for (int i = 1; i < n; i++) {
        curr += arr[i];
        if (curr > max) max = curr;
        if (curr < 0) curr = 0;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)  ans += arr[i];

    if (ans > max) cout << "YES" << endl;
    else  cout << "NO"  << endl;
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

