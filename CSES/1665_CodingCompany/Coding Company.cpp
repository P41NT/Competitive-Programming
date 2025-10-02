#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/modint.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

using mi = atcoder::modint1000000007;

const int P = 1e4 + 1;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    debug(arr);

    vector<vector<mi>> dp1(n + 1, vector<mi>(P + x + 1));
    vector<vector<mi>> dp2(n + 1, vector<mi>(P + x + 1));

    dp1[0][P] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= P + x; k++) {
                if (dp1[j][k] == 0) continue;
                dp2[j][k] += dp1[j][k];
                if (j > 0 && arr[i] + k <= P + x) {
                    dp2[j - 1][arr[i] + k] += j * dp1[j][k];
                }
                if (j + 1 <= n) {
                    dp2[j + 1][k - arr[i]] += dp1[j][k];
                }
                if (j <= n - (i + 1)) {
                    dp2[j][k] += j * dp1[j][k];
                }
            }
        }
        for (int j = 0; j <= n;  j++) {
            for (int k = 0; k <= P + x; k++) {
                dp1[j][k] = dp2[j][k];
                dp2[j][k] = 0;
            }
        }
    }

    mi answer = 0;
    for (int k = P; k <= P + x; k++) {
        answer += dp1[0][k];
    }

    cout << answer.val() << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

