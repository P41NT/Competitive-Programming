#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;

    map<int, int> freq;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        freq[temp]++;
    }
    int alice_first = 0;
    int mx = 0;
    for (int i = 0; i <= n; i++) {
        if (!freq[i]) {
            cout << i << endl;
            return;
        }
        else if (freq[i] == 1) {
            if (!alice_first) {
                alice_first = 1;
                continue;
            }
            cout << i << endl;
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

