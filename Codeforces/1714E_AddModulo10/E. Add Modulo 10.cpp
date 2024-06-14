#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

int next(int n) { return n + n%10; }

int grp(int k) {
    vector<int> grp1 = { 2, 4, 8, 16 };
    for (int s : grp1) 
        if (s == k) return 1;
    return 2;
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int chk5 = false;
    for (int i = 0; i < n; i++) {
        if (arr[i]%5 == 0) {
            chk5 = true;
            arr[i] = next(arr[i]);
        }
        else {
            if (arr[i] % 2 == 1) 
                arr[i] = next(arr[i]);
            arr[i] %= 20;
        }
    }
    if (chk5) {
        for (int i = 0; i < n; i++) {
            if (arr[i] != arr[0]) {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
        return;
    }

    int group = grp(arr[0]); 
    for (int i = 0; i < n; i++) {
        if (grp(arr[i]) != group) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
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

