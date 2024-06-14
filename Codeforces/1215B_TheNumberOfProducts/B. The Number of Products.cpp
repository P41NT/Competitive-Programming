#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

int c2(int n) {
    return n * (n - 1) / 2;
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    arr[0] = 1;

    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        arr[i] = arr[i - 1] * (temp > 0 ? 1 : -1);
    }

    int pos = 0, neg = 0;
    for (int i = 0; i <= n; i++) 
        pos += arr[i] > 0, neg += arr[i] < 0;

    int total = c2(n + 1);
    int ans1 = c2(pos) + c2(neg);
    int ans2 = total - ans1;

    cout << ans2 << " " << ans1 << endl;
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

