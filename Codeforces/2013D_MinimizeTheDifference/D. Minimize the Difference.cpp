#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <unistd.h>

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

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    auto chk = [&](int x) -> bool {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > x) count += arr[i] - x;
            else {
                count -= x - arr[i];
                if (count < 0) {
                    return false;
                }
            }
        }
        return true;
    };

    auto chk2 = [&](int x) -> bool {
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] < x) count += x - arr[i];
            else {
                count -= arr[i] - x;
                if (count < 0) {
                    return false;
                }
            }
        }
        return true;
    };

    int lower = *min_element(arr.begin(), arr.end());
    int higher = arr[0];
    int ans1 = lower;
    while (lower <= higher) {
        int mid = (lower + higher) >> 1;
        if (chk(mid)) {
            lower = mid + 1;
            ans1 = max(ans1, mid);
        }
        else {
            higher = mid - 1;
        }
    }

    lower = arr[n - 1];
    higher = *max_element(arr.begin(), arr.end());
    int ans2 = higher;

    while (lower <= higher) {
        int mid = (lower + higher) >> 1;
        if (chk2(mid)) {
            higher = mid - 1;
            ans2 = min(ans2, mid);
        }
        else{
            lower = mid + 1;
        }
    }

    cout << ans2 - ans1 << endl;
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

