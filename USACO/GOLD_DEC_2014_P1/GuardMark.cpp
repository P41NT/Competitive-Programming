#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #ifndef ONLINE_JUDGE
// #include "../debug.cpp"
// #define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
// #else
#define debug(...)
#define debugArr(...)
// #endif

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, h;
    cin >> n >> h;

    struct cow {
        int weight;
        int height;
        int strength;
    };

    vector<cow> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].height >> arr[i].weight >> arr[i].strength;
    }

    vector<int> dp(1ll << n, -1);

    const int inf = 1e12;
    dp[0] = 1e12;

    vector<int> sm(1ll << n);

    int answer = -1;

    for (int i = 1; i < (1ll << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1ll << j)) {
                sm[i] += arr[j].height;

                int prevDp = dp[i ^ (1ll << j)];
                dp[i] = max(dp[i], min(prevDp - arr[j].weight, arr[j].strength));
            }
        }
        if (sm[i] >= h) {
            answer = max(answer, dp[i]);
        }
    }

    if (answer == -1) {
        cout << "Mark is too tall" << endl;
    }
    else {
        cout << answer << endl;
    }
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

