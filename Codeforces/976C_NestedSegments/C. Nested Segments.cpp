#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.first.first == b.first.first) 
        return a.first.second > b.first.second;
    return a.first.first < b.first.first;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end(), cmp);

    int mx = arr[0].first.second;
    int curr = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].first.second <= mx) {
            cout << arr[i].second << " " << arr[curr].second << endl;
            return;
        }
        else {
            mx = arr[i].first.second;
            curr = i;
        }
    }
    cout << "-1 -1" << endl;
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

