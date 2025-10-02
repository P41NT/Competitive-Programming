#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    const int inf = 1e12;

    vector<int> dp(513, inf);
    dp[0] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 512; j++) {
            if (dp[j] == inf) continue;
            if (dp[j] > arr[i]) continue;

            int curr = j ^ arr[i];
            if (dp[curr] > arr[i]) {
                dp[curr] = arr[i];
            }
        }
    }

    vector<int> answer;
    for (int i = 0; i <= 512; i++) {
        if (dp[i] == inf) continue;
        answer.push_back(i);
    }

    cout << answer.size() << endl;
    for (auto s : answer) {
        cout << s << " ";
    }
    cout << endl;
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

