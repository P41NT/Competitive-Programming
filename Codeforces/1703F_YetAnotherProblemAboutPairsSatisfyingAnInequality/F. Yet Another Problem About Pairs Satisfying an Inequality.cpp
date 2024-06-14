#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
	// code goes here 
    int n;
    cin >> n;
    
    vector<int> arr;
    vector<int> indices;
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        if (k < i) {
            arr.push_back(k);
            indices.push_back(i);
        }
    }

    n = arr.size();
    int sum = 0;
    for (int k = n - 1; k >= 0; k--) {
        auto it = lower_bound(indices.begin(), indices.end(), arr[k]);
        int pos = it - indices.begin();
        if (pos < 0) pos = 0;
        sum += pos;
    }
    cout << sum << endl;
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

