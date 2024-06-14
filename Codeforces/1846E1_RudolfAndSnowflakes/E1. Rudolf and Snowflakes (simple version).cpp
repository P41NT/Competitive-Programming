#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

set<int> s;

const int MAX_ = 1000000;

int power(int a, int n)
{
    int ans = 1;
    while (n > 0) {
        int last_bit = (n & 1);
        if (last_bit) {
            ans = ans * a;
        }
        a = a * a;
        n = n >> 1;
    }

    return ans;
}

set<int> vals;

void preprocess() {
    for (int k = 2; ; k++) {
        for (int p = 3; ; p++) {
            int pow = power(k, p) - 1;
            if (pow/(k - 1) > MAX_) break;
            vals.insert(pow/(k-1));
            if (pow/(k-1) == 1000000) cout << k << " " << p << endl;
        }
        if ((k*k*k)/(k-1) > MAX_) break;
    }
}

void solve() {
	// code goes here 
    int n;
    cin >> n;

    if (vals.count(n)) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    preprocess();

	int t = 1;
	cin >> t;
	while ( t-- ) {
		solve();
	}
}

