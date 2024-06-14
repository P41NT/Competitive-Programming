#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

map<string, int> categories;
vector<vector<string>> arr;

int curr_attr;

bool cmp(vector<string> a, vector<string> b) {
    return a[curr_attr] < b[curr_attr];
}

void solve() {
    string cat;
    getline(cin, cat);
    istringstream in(cat);
    
    string attr;
    int i = 0;
    while (in >> attr)
        categories.insert({attr, i++});

    int n;
    cin >> n;

    arr = vector<vector<string>>(n, vector<string>(categories.size()));

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < categories.size(); j++) 
            cin >> arr[i][j];

    int q;
    cin >> q;
    while (q--) {
        cin >> attr;
        curr_attr = categories[attr];
        stable_sort(arr.begin(), arr.end(), cmp);
        cout << cat << endl;
        for (auto &i : arr) {
            for (auto &j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
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

