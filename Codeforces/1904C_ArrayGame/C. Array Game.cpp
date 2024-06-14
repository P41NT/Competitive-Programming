#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int lowest = arr[0];
    for (int i = 0; i < n; i++) lowest = min(lowest, arr[i]);

    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n - 1; i++)
        lowest = min(lowest, arr[i + 1] - arr[i]);

    if (k >= 3) 
        cout << "0" << endl;
    else if (k == 1) {
        cout << lowest << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int c = arr[j] - arr[i];
                int lb = lower_bound(arr.begin(), arr.end(), c) - arr.begin();
                if (lb > 0) lowest = min(lowest, c - arr[lb - 1]);
                if (lb < n) lowest = min(lowest, arr[lb] - c);
            }
        }
        cout << lowest << endl;
    }
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}

