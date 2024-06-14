#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
	// code goes here 
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) 
        c[i] = { a[i] - b[i], i + 1 };

    sort(c.begin(), c.end());

    vector<int> ans;
    int biggest = c[n - 1].first;
    for (int i = 0; i < n; i++) if (c[i].first== biggest) ans.push_back(c[i].second);

    // cerr << "A : ";
    // for (auto k : a) {
    //     cerr << k << " ";
    // }
    // cerr << endl;
    // cerr << "B : ";
    // for (auto k : b) {
    //     cerr << k << " ";
    // }
    // cerr << endl;
    // cerr << "C : ";
    // for (auto k : c) {
    //     cerr << k.first << " ";
    // }
    // cerr << endl;

    // cerr << biggest << endl;
    cout << ans.size() << endl;
    for (auto k : ans) {
        cout << k << " ";
    }
    cout << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

