#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool check(int l, int r, vector<vector<int>> &prefixbit, int k) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int bit = ((prefixbit[r][i] - prefixbit[l - 1][i]) == (r - l + 1));
        ans += bit * (1 << i);
    }
    return ans >= k;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);

    vector<vector<int>> prefixbit(n + 1, vector<int>(32, 0));

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        for (int j = 0; j < 32; j++) {
            prefixbit[i][j] = prefixbit[i - 1][j];
            prefixbit[i][j] += ((arr[i] & (1 << j)) >> j);
        }
    }


    int q;
    cin >> q;
    while (q--) {
        int l, k;
        cin >> l >> k;

        int left = l, right = n;
        int r = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (check(l, mid, prefixbit, k)) {
                r = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        cout << r << " ";
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

