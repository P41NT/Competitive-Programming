#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool cmp(string a, string b) {
    string c = a, d = b;
    reverse(c.begin(), c.end());
    reverse(d.begin(), d.end());

    return c < d;
}

void solve(string first) {
    vector<string> v;
    v.push_back(first);

    string s;
    getline(cin, s);
    while (getline(cin, s) && s.length() != 0)
        v.push_back(s);

    stable_sort(v.begin(), v.end(), cmp);

    int largest = 0;
    for (auto s : v) 
        largest = max(largest, (int)s.length());

    for(auto s : v) {
        for (int i = 0; i < largest - s.length(); i++) cout << " ";
        cout << s << endl;
    }
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    string s;
    int grp = 0;
	while (cin >> s) {
        if (grp++ >= 1) cout << endl;
		solve(s);
	}
}

