#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n; cin >> n;

    vector<int> unis(n), skil(n);
    for (int i = 0; i < n; i++) cin >> unis[i];
    for (int i = 0; i < n; i++) cin >> skil[i];

    vector<vector<int>> skill(n + 1);
    vector<vector<int>> pref(n + 1, vector<int>(1, 0));

    for (int i = 0; i < n; i++) skill[unis[i]].push_back(skil[i]);
    for (int i = 1; i <= n; i++) sort(skill[i].begin(), skill[i].end(), greater<int>());

    for (int i = 1; i <= n; i++) 
        for (auto s : skill[i]) 
            pref[i].push_back(pref[i].back() + s);

    vector<int> ans(n + 1);

    // for (auto s : pref) {
    //     for (auto i : s) 
    //         cerr << i << " ";
    //     cerr << endl;
    // }

    for (int i = 1; i <= n; i++) {
        if (pref[i].size() == 1) continue;
        for (int k = 1; k <= (pref[i].size() - 1); k++) {
            ans[k] += pref[i][(pref[i].size() - 1) /k * k];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
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

