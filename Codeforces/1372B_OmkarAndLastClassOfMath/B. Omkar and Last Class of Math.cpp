#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n/2 << " " << n/2 << endl;
    }
    else {
        int ans = 0;
        for (int i = 2; i <= (int)ceil(sqrt(n)); i++) 
            if (n%i == 0){
                ans = n/i;
                break;
            }
        if (ans == 0) ans = 1;

        cout << ans << " " << n - ans << endl;
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

