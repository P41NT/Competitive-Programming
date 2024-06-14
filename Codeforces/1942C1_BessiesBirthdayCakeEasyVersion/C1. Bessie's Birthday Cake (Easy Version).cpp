#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    set<int> arr;

    int temp;
    for (int i = 0; i < x; i++) {
        cin >> temp;
        temp--;
        arr.insert(temp);
    }
    for (auto s : arr) if (arr.count((s + 2) % n)) arr.insert((s + 1) % n);
    cout << arr.size() - 2 << endl;
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

