#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;
    vector<int> arr;

    int curr;
    cin >> curr; arr.push_back(curr);
    cin >> curr; arr.push_back(curr);

    bool increasing = arr[1] > arr[0];

    for (int i = 2; i < n; i++) {
        cin >> curr;
        if ((curr > arr[arr.size() - 1] && increasing)  || 
            (curr < arr[arr.size() - 1] && !increasing) || 
            curr == arr[arr.size() - 1]) {
            arr.pop_back();
            arr.push_back(curr);
        }
        else {
            increasing = !increasing;
            arr.push_back(curr);
        }
    }

    cout << arr.size() << endl;
    for (auto s: arr) {
        cout << s << " ";
    }
    cout << endl;
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

