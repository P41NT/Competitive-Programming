#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
	// code goes here 
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int i = n - 1;
    int j = n - 1;
    int k = 1;
    vector<int> ans;
    while (j >= i){
        while (arr[i] >= k && i >= 0) {i--;k++;}
        ans.push_back(j - i);
        j--;
        k--;
    }

    ans.pop_back();
    reverse(ans.begin(), ans.end());

    for (auto s : ans) {
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

