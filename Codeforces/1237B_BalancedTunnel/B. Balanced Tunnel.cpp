#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    vector<int> init(n);
    vector<int> fin(n);

    for (int i = 0 ; i < n; i++) cin >> init[i];
    for (int i = 0 ; i < n; i++) cin >> fin[i];

    int j = 0;
    vector<bool> visited(n + 1);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (visited[init[i]]) continue;
        while (init[i] != fin[j]) {
            // cerr << i << " " << j << "[ " ;
            // for (auto s : visited) cerr << s << " ";
            // cerr << "]" << endl;
            visited[fin[j]] = true; j++; ans++;
        }
        j++;
        visited[init[i]] = true;
    }

    cout << ans << endl;
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

