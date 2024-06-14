#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> a;
    vector<int> b;

    int k = 1;
    a.push_back(arr[0]);
    while (k < n && a[a.size() - 1] >= arr[k]) {
        a.push_back(arr[k]);
        k++;
    }
    if (k < n) b.push_back(arr[k++]);
    
    int ans = 0;
    for (; k < n; k++) {
        bool f = arr[k] <= a[a.size() - 1];
        bool s = arr[k] <= b[b.size() - 1]; 

        if (f && !s) a.push_back(arr[k]);
        else if (s && !f) b.push_back(arr[k]);
        else if (!s && !f) {
            ans++;
            if (a[a.size() - 1] > b[b.size() - 1]) b.push_back(arr[k]);
            else a.push_back(arr[k]);
        }
        else if (s && f) {
            if (a[a.size() - 1] > b[b.size() - 1]) b.push_back(arr[k]);
            else a.push_back(arr[k]);
        }
    }

    cout << ans << endl;
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

