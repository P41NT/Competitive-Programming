#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    vector<int> multiple(5);
    for (int i = 1; i <= 4; i++) {
        cout << "? " << i << " " << i + 1 << endl;
        cout.flush();
        cin >> multiple[i];
    }

    vector<int> ans = { 4, 8, 15, 16, 23, 42 };
    do {
        bool ok = true;
        for (int i = 1; i <= 4; i++) 
            if (ans[i - 1] * ans[i] != multiple[i]) ok = false;
        if (ok) {
            cout << "! ";
            for (int i = 0; i < 6; i++)
                cout << ans[i] << " ";
            cout << endl;
            cout.flush();
        }
    }
    while (next_permutation(ans.begin(), ans.end()));
}

int32_t main () {
	int t = 1;
	// cin >> t;
	while ( t-- ) {
		solve();
	}
}

