#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/Compocode/debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    vector<vector<int>> cum(n, vector<int>(n));
    vector<vector<int>> flipped(n, vector<int>(n));

    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) {
                if (j - 1 >= 0) cum[i][j] += cum[i - 1][j - 1];
                if (j + 1 < n) cum[i][j] += cum[i - 1][j + 1];
                if (j - 1 >= 0 && j + 1 < n && i > 1) cum[i][j] -= cum[i - 2][j];
                cum[i][j] += flipped[i - 1][j];
            }

            debug(i, j, cum[i][j]);

            if (arr[i][j] == 1 && cum[i][j] % 2 == 0) {
                flipped[i][j] = 1;
                answer++;
            }
            else if (arr[i][j] == 0 && cum[i][j] % 2 == 1) {
                flipped[i][j] = 1;
                answer++;
            }
            cum[i][j] += flipped[i][j];
        }
    }

    debug(cum);
    debug(flipped);

    cout << answer << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

