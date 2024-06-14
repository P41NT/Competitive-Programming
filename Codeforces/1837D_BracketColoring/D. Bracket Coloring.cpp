#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans(n);
    int ans_ = 1;

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == s[0]) k++;
        else k--;

        if (k == 0 && i > 0) ans[i] = ans[i - 1];
        else ans[i] = (k >= 0)? 1 : 2;
        ans_ = max(ans_, ans[i]);
    }
    if (k != 0) cout << "-1" << endl;
    else {
        cout << ans_ << endl;
        for (auto s : ans) cout << s << " ";
        cout << endl;
    }
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

