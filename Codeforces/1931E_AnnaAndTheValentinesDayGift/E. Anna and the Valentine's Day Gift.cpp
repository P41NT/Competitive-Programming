#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> lz(n);
    for (int i = 0 ; i < n; i++) {
        int t = arr[i];
        while (t % 10 == 0) {
            lz[i]++;
            t /= 10;
        }
        t = arr[i];
        while (t) {
            total++;
            t /= 10;
        }
    }


    sort(lz.rbegin(), lz.rend());

    // for (auto s : lz) cerr << s << " ";
    // cerr << endl;

    int sub = 0;
    for (int i = 0; i < n; i += 2) {
        if (lz[i] == 0) break;
        sub += lz[i];
    }
    total -= sub;

    if (total <= m) cout << "Anna" << endl;
    else cout << "Sasha" << endl;
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

