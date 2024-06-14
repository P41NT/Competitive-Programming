#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, m, a;
    cin >> n >> m >> a;

    int x = (int)(ceil((double)n/(double(a))));
    int y = (int)(ceil((double)m/(double(a))));

    cout << x * y << endl;
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

