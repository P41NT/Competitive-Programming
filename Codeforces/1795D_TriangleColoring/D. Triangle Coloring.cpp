#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

const int mod = 998244353;

int powmod(int a, int b, int p) {
    a %= p;
    if (a == 0) return p;
    int product = 1;
    while (b) {
        if (b&1) {
            product *= a;
            product %= p;
            b--;
        }
        a *= a;
        a %= p;
        b /= 2;
    }
    return product;
}

int inv(int a, int p) {
    return powmod(a, p - 2, p);
}

vector<int> fact;

int combinations(int n, int r, int p) {
    return ((fact[n] * inv(fact[r], p) % p) * inv(fact[n - r], p)) % p;
}

void preprocess() {
    fact.push_back(1);
    for (int i = 1; i <= 3*1e5 + 10; i++) 
        fact.push_back((fact.back() * i) % mod);
}

void solve() {
    int n;
    cin >> n;

    int fac = 1;
    for (int i = 1; i <= n/3; i++) {
        vector<int> temp(3);
        cin >> temp[0] >> temp[1] >> temp[2];
        sort(temp.begin(), temp.end());

        if (temp[2] > temp[0] && temp[0] == temp[1])
            fac = (fac * 2) % mod;
        if (temp[2] == temp[0])
            fac = (fac * 3) % mod;
    }

    int ans = combinations(n/3, n/6, mod);
    ans = (ans * fac % mod) % mod;

    cout << ans << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    preprocess();

	int t = 1;
	// cin >> t;
	while ( t-- ) {
		solve();
	}
}

