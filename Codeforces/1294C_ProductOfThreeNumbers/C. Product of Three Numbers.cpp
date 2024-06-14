#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;
    int a, b, c;
    map<int, int> factors;

    a = -1;
    int t = n;
    for (int i = 2; i * i <= t; i++) {
        while (t % i == 0) {
            if (a == -1) a = i;
            factors[i]++;
            t /= i;
        }
    }

    if (factors.size() == 0) {
        cout << "NO" << endl;
        return;
    }

    factors[a]--;

    // for (auto s : factors) {
    //     cerr << s.first << " " << s.second << endl;
    // }

    b = 1;
    for (auto s : factors) {
        if (b != 1 && b != a) break;
        while (s.second > 0 && (b == 1 ||b == a)) {
            b *= s.first;
            s.second--;
        }
    }
    if (b == a || b == 1) {
        cout << "NO" << endl;
        return;
    }

    c = n/(a * b);

    if (c == a || c == b || c == 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << a << " " << b << " " << c << endl;
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

