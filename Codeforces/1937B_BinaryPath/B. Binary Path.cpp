#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int end = n - 1;
    int counter = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == b[i - 1]) counter++;
        else if (a[i] > b[i - 1]) {
            end = i - 1;
            break;
        }
        else if (a[i] < b[i - 1]) counter = 1;
    }

    for (int i = 0; i <= end; i++) cout << a[i];
    for (int i = end; i < n; i++) cout << b[i];

    cout << endl << counter << endl;
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

