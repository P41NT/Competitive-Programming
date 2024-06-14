#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int a, b, k;
    cin >> a >> b >> k;

    vector<vector<int>> inp(k, vector<int>(2));

    for (int i = 0; i < 2; i++) for (int j = 0; j < k; j++) cin >> inp[j][i];

    vector<int> boys(a + 1);
    vector<int> girls(b + 1);

    vector<vector<int>> boy_con(a + 1);

    for (int i = 0; i < k; i++) {
        boys[inp[i][0]]++;
        girls[inp[i][1]]++;
        boy_con[inp[i][0]].push_back(inp[i][1]);
    }

    int ans = 0;
    for (int i = 1; i <= a; i++) 
        for (auto s : boy_con[i]) 
            ans += k - boys[i] - girls[s] + 1;

    cout << ans/2 << endl;
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

