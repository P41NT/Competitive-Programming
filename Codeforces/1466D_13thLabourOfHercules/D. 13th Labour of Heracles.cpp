#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end(), greater<pair<int, int>>());

    map<int, int> degree;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
    }

    int sum = 0;
    for (auto s : arr) sum += s.first;

    cout << sum << " ";
    int j = 0;
    for (int i = 1; i < n - 1; i++) {
        while (degree[arr[j].second] <= 1) j++;
        sum += arr[j].first;
        // cerr << j << " " << arr[j].second << " " << arr[j].first << " " << 
        //     degree[arr[j].second] << endl;
        degree[arr[j].second]--;
        cout << sum << " ";
    }
    cout << endl;
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

