#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> brr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> brr[i];

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    function<int(int, int)> recur;
    recur = [&](int i, int j) -> int {
        if (i == n || j == n) return dp[i][j] = 0;
        if (dp[i][j] != -1) return dp[i][j];
        int answer = 0;
        if (abs(arr[i] - brr[j]) <= 4) answer = max(answer, 1 + recur(i + 1, j + 1));

        answer = max(answer, recur(i + 1, j + 1));
        answer = max(answer, recur(i, j + 1));
        answer = max(answer, recur(i + 1, j));

        return dp[i][j] = answer;
    };

    int answer = recur(0, 0);
    // debug(dp);
    cout << answer << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

