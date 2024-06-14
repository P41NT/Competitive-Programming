#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool cmp(string a, string b) {
    if (a[0] != b[0]) 
        return b[0] > a[0];
    else if (a[1] != b[1]) 
        return (b[1] > a[1]);
    return false;
}

void solve(int n) {
    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stable_sort(arr.begin(), arr.end(), cmp);

    for (auto s : arr) 
        cout << s << endl;
    cout << endl;
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

