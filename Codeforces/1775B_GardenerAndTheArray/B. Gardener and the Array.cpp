#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
	// code goes here 
    //
    int n;
    cin >> n;
    map<int, int> freq;
    vector<vector<int>> arr(n) ;
    vector<int> kk(n);
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        kk[i] = k;
        for (int j = 0; j < k; j++) {
            int l; cin >> l;
            arr[i].push_back(l);
            freq[l]++;
        }
    }
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0;j < kk[i]; j++) {
            if (freq[arr[i][j]] >= 2) continue;
            flag = false; break;
        }
        if (flag) {
            cout << "Yes" << endl;
            return;
        }
     }
    cout << "No" << endl;
    return;
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

