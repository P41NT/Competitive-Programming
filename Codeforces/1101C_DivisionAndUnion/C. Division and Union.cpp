#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.first.first == b.first.first) 
        return a.first.second > b.first.second;
    return a.first.first < b.first.first;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end(), cmp);

    vector<int> colors(n);
    int color = 1;
    int mx = arr[0].first.second;
    for (int i = 0; i < n; i++) {
        if (arr[i].first.first <= mx) {
            colors[arr[i].second] = color;
            mx = max(mx, arr[i].first.second);
        }
        else {
            color = (color == 1) ? 2 : 1;
            colors[arr[i].second] = color;
            mx = arr[i].first.second;
        }
    }

    if (*max_element(colors.begin(), colors.end()) == 1)
        cout << "-1" << endl;
    else {
        for (auto s : colors) cout << s << " ";
        cout << endl;
    }
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

