#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int k_ = k;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());
    vector<int> req;
    vector<int> x;

    for (int i = 0; i < n; i++) {
        if (k) {
            req.push_back(arr[i].first);
            x.push_back(min(k, m));
            k -= min(k, m);
        }
    }

    int ans = 0;
    int sum = 0;
    for (int i = 0; i < req.size(); i++) {
        ans += req[i] * x[i];
        sum += x[i];
    }
    for (int i = 0; i < x.size(); i++) {
        sum -= x[i];
        ans += x[i] * sum;
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

