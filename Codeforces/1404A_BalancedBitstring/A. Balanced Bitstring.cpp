#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;

    vector<char> s;
    string temp; cin >> temp;
    for (char c : temp) s.push_back(c);

    vector<char> required(k);
    for (int i = 0; i < k; i++) required[i] = s[i];

    // for (char m : required) cerr << m;
    // cerr << endl;
    // for (char m : s) cerr << m;
    // cerr << endl;
    
    for (int i = k; i < n; i++) {
        int j = i % k;
        if (s[i] == '?') continue;
        if (required[j] == '?') {
            if (s[i] != '?') required[j] = s[i];
        }
        else if (required[j] != s[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    int ones = 0, zeroes = 0, qns = 0;
    for (int i = 0; i < k; i++) {
        ones += required[i] == '1';
        zeroes += required[i] == '0';
        qns += required[i] == '?';
    }
    if (abs(ones - zeroes) > qns) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
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

