#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    string s;
    cin >> s;

    vector<int> arr;
    int i = 0;
    while (s[i] == 'o') i++;
    int curr = 0;
    bool is_v = true;
    while (i <= s.length()){
        if (i == s.length()) arr.push_back(curr);
        if (is_v && s[i] == 'v') curr++;
        else if (is_v && s[i] == 'o') {
            arr.push_back(curr);
            curr = 1;
            is_v = false;
        }
        else if (!is_v && s[i] == 'o') curr++;
        else if(!is_v && s[i] == 'v') {
            arr.push_back(curr);
            curr = 1;
            is_v = true;
        }
        i++;
    }
    if (arr.size() % 2 == 0) arr.pop_back();


    int n = arr.size();

    // for (int i = 0; i < n; i++) cerr << arr[i] << " ";
    // cerr << endl;

    for (int i = 0; i < n; i += 2) arr[i]--;

    int sum1 = arr[0];
    int sum2 = 0;
    for (int i = 2; i < n; i += 2) sum2 += arr[i];

    int ans = 0;
    for (int i = 1; i < n - 1; i+=2) {
        ans += sum1 * arr[i] * sum2;
        sum1 += arr[i + 1]; sum2 -= arr[i + 1];
    }

    cout << ans << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while ( t-- ) {
		solve();
	}
}

