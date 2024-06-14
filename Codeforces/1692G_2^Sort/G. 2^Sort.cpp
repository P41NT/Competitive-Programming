#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<int> indices;
    indices.push_back(0);

    cin >> arr[0];
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        if (arr[i] * 2 <=  arr[i - 1]) indices.push_back(i);
    }

    int l = indices.size();
    indices.push_back(n);

    // for (auto s : indices) cerr << s << " ";
    // cerr << endl;

    int ans = 0;
    for (int i = 0; i < l; i++) {
        ans += max(0ll, indices[i + 1] - indices[i] - k);
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

