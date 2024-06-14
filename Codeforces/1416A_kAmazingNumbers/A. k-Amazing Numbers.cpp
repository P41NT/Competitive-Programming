#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<vector<int>> freq(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        freq[arr[i]].push_back(i);
    }
    for (auto &s : freq) {
        if (s.size() != 0) s.push_back(n + 1);
    }
    // cerr << "reached" << endl;
    //     
    // for (auto s : freq) {
    //     for (auto i : s) {
    //         cerr << i << " ";
    //     }
    //     cerr << endl;
    // }
    // cerr << endl;

    vector<int> ans(n + 1, LONG_MAX);
    for (int i = 1; i <= n; i++) {
        int k = freq[i].size();
        if (k == 0) continue;
        int curr = freq[i][0];
        for (int j = 1; j < k; j++) {
            curr = max(curr, freq[i][j] - freq[i][j - 1]);
            // cerr << curr << " " << j << "; ";
        }
        // cerr << endl;
        //
        // cerr << i << " " << curr << endl;
        ans[curr] = min(ans[curr], i);
        //
        // for (auto s : ans) 
        //     if (s == LONG_MAX) cerr << -1 << " ";
        //     else cerr << s << " ";
        // cerr << endl;

    }


    for (int i = 1; i <= n; i++) ans[i] = min(ans[i], ans[i - 1]);
    for (int i = 1; i <= n; i++) if (ans[i] == LONG_MAX) ans[i] = -1;


    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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

