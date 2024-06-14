#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

const int MOD = 1e9+7;

int fact (int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans * (i%MOD))%MOD;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    int dup = -1;
    for (int i = 1; i < n; i++) 
        if (arr[i] == arr[i - 1]) {
            dup = arr[i];
            break;
        }

    if (dup == -1) {
        cout << 0 << endl;
        return;
    }

    int curr = dup;
    for (int i = 0; i < n;i++) curr &= arr[i];

    if (curr != dup) {
        cout << 0 << endl;
        return;
    }

    int num_dup = 0;
    for (int i = 0 ; i < n; i++) 
        if (arr[i] == dup) num_dup++;

    int ans = fact(n - 2);
    int perm = (((num_dup%MOD) * ((num_dup-1)%MOD)))%MOD;
    ans = (ans * perm) % MOD;

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

