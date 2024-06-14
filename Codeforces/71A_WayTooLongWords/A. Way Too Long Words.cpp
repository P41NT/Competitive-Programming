#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    string word;
    cin >> word;

    if (word.length() > 10) cout << word[0] << (word.length() - 2) << word[word.length() - 1] << endl;
    else cout << word << endl;
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

