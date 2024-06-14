#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;
    int m = n;
    vector<int> arr;
    bool zeroes = true;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        if (k != 0){
            arr.push_back(k);
            zeroes = false;
        }
    }
    n = arr.size();
    if (zeroes) {
        for (int i = 1; i <= m; i++) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    int gcd = -1;
    for (int bit = 0; bit <= 30; bit++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] & (1 << bit)) count++;
        }
        if (count == 0) continue;
        if (gcd == -1) gcd = count;
        else gcd = __gcd(count, gcd);
        // cerr << gcd << endl;
    }

    vector<int> div;

    for (int i = 1; i*i <= gcd; i++) {
        if (gcd%i == 0) {
            div.push_back(i);
            if (gcd/i != i) div.push_back(gcd/i);
        }
    }
    sort(div.begin(), div.end());
    for (auto s : div) cout << s << " ";
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

