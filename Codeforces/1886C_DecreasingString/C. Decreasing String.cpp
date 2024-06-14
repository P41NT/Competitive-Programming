#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    string s; cin >> s;
    
    int n = s.size();

    vector<int> pref;
    pref.push_back(n);
    for (int i = n - 1; i >= 1; i--) 
        pref.push_back(pref.back() + i);

    for (auto &s : pref) s--;

    // for (auto s : pref) cerr << s << " ";
    // cerr << endl;

    int k; cin >> k;
    k--;
    int op = lower_bound(pref.begin(), pref.end(), k) - pref.begin();
    int l = (op > 0 ? pref[op - 1] : -1);
    // cerr << k << " " << l << " " << k - l - 1 << " " << op << endl;

    string tmp = "";
    for (int i = 0; i < n - 1; i++) {
        // cerr << tmp << endl;
        if (s[i] > s[i + 1] && op) {
            op--; 
            while (op && tmp.back() > s[i + 1]) tmp.pop_back(), op--;
            continue;
        }
        tmp += s[i];
    }
    tmp += s[n - 1];
    if (op) 
        tmp = tmp.substr(0, tmp.size() - op);

    // cerr << tmp << " " << k - l - 1 << endl;
    cout << tmp[k - l  - 1];
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

