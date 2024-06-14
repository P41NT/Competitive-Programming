#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<pair<int, string>> arr;
    for (int i = 0; i < n; i++) {
        string name;
        int a, b, c;
        cin >> name >> a >> b >> c;
        int num = c * 10000 + b * 100 + a;
        arr.push_back({num, name});
    }

    sort(arr.begin(), arr.end());

    cout << arr[n-1].second << endl;
    cout << arr[0].second << endl;
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

