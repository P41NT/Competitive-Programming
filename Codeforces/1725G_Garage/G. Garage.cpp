#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/CompetitiveProgramming/debug.cpp"
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

    auto chk = [&](int mid) -> int {
        int numodd = (mid - 1) / 2;
        int numeven = max(mid / 4 - 1, 0ll);

        debug(mid, numodd, numeven);
        return numodd + numeven >= n;
    };

    int lower = 3, higher = 1e18;
    int answer = 1e18;
    while (lower <= higher) {
        int mid = (lower + higher) >> 1;
        if (chk(mid)) {
            higher = mid - 1;
            answer = min(answer, mid);
        }
        else { lower = mid + 1; }
    }

    cout << answer << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

