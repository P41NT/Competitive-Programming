#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve(int n) {
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i]; 

    sort(arr.begin(), arr.end());

    string a = arr[n/2 - 1];
    string b = arr[n/2];

    cerr << a << " " << b << endl;

    string ans = "";

    if (b.substr(0, a.length()) == a) {
        cout << a << endl;
        return;
    }

    int i = 0;
    while (i < a.length() && i < b.length()) {
        if (a[i] != b[i]) 
            break;
        ans += a[i];
        i++;
    }

    if (i == a.length() - 1) {
        cout << a << endl;
        return;
    }

    char next = char(a[i] + 1);
    if (next != b[i]) {
        ans += next;
        cout << ans << endl; return;
    }
    ans += a[i];
    if (i == a.length() - 2) {
        ans += a[i+1];
        cout << ans << endl; return;
    }
    int j = i + 1;
    while (a[j] != 'Z') {
        if (j == a.length() - 1) {
        }
        ans += a[j];
        j++;
    }
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	while (true) {
	    cin >> t;
        if (t == 0) break;
		solve(t);
	}
}

