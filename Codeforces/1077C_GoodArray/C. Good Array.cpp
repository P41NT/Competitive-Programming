#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n; 
    cin >> n;
    vector<pair<int, int>> arr(n);
    map<int, int> contains;

    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
        total_sum += arr[i].first;
        contains[arr[i].first]++;
    }

    sort (arr.begin(), arr.end());

    vector<int> ans;
    for (int i = 0; i < n - 1; i++) 
        if (total_sum - arr[i].first == 2 * arr[n - 1].first)
            ans.push_back(arr[i].second);

    contains[arr[n-1].first]--;

    int required = total_sum - arr[n-1].first;
    if (required % 2 == 0 && contains[required/2]) 
        ans.push_back(arr[n-1].second);

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (auto s : ans) cout << s + 1 << " ";
    cout << endl;
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

