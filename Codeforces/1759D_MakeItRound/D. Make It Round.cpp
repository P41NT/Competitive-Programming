#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;

    int fac_2 = 0; int fac_5 = 0;
    int t = n;
    while (t % 10 == 0) t /= 10;
    while (t % 2 == 0) fac_2++, t /= 2;
    while (t % 5 == 0) fac_5++, t /= 5;

    int ans = 1;
    while (ans * 2 <= k && fac_5) ans *= 2, fac_5--;
    while (ans * 5 <= k && fac_2) ans *= 5, fac_2--;
    while (ans * 10 <= k) ans *= 10;

    int lst = 1;
    while ((lst + 1) * ans <= k) lst++;
    ans *= (lst) ? lst : 1;

    cout << n * ans << endl;
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

