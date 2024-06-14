#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define int long long int

typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

void solve() {
    int n;
    cin >> n;

    ordered_set os;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end(), cmp);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += os.order_of_key(arr[i].first);
        os.insert(arr[i].first);
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

