#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> factors;
    for (int i = 1; i <= (int)ceil(sqrt(n)); i++) 
        if (n % i == 0) {
            factors.push_back(i);
            factors.push_back(n/i);
        }
    sort(factors.begin(), factors.end());

    for (int i = 0; i < factors.size(); i++) {
        if (n/factors[i] <= k) {
            cout << factors[i] << endl;
            return;
        }
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

