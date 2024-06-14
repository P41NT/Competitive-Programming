#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;

    vector<string> arr(n/k);
    string temp; cin >> temp;

    for (int i = 0; i < n; i += k) 
        arr[i/k] = temp.substr(i, k);

    int ans = 0;
    vector<int> freq(26);
    for (int i = 0; i < (k + 1)/2; i++) {
        fill(freq.begin(), freq.end(), 0);
        for (string s : arr) freq[s[i] - 'a']++, freq[s[k - i - 1] - 'a']++;

        char hf = 'a'; int fre = freq[0];
        for (int j = 0; j < 26; j++) 
            if (freq[j] > fre) hf = j + 'a', fre = freq[j];

        for (string s: arr) {
            ans += s[i] != hf;
            if (i != k - i - 1) ans += s[k - i - 1] != hf;
        }
    }
    cout << ans << endl;
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

