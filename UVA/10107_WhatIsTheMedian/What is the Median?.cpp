#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

vector<int> arr;

void solve(int n) {
    arr.push_back(n);
    sort(arr.begin(), arr.end());

    int l = arr.size();
    if (l % 2 == 0) {
        cout << ((arr[l/2] + arr[l/2 - 1])/2) << endl;
    }
    else {
        cout << (arr[l/2]) << endl;
    }
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
    int k;
	while (cin >> k) {
		solve(k);
	}
}

