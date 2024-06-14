#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> sheep;
    int k = 0;
    for (int i = 0; i < s.length(); i++) 
        if (s[i] == '*') sheep.push_back(i - k++);

    n = sheep.size();

    if (n == 1 || n == 0) {
        cout << 0 << endl;
        return;
    }

    int m1 = sheep[n/2 - 1];
    int m2 = sheep[n/2];

    int ans = 0;
    int curr = 0;

    for (int i = 0; i < n; i++) 
        curr += abs(sheep[i] - m1);
    ans = curr;

    curr = 0;
    for (int i = 0; i < n; i++) 
        curr += abs(sheep[i] - m2);
    ans = min(ans, curr);

    cout << ans << endl;
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

