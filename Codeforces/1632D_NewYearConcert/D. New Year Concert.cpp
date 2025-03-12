#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/segtree.hpp>

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

int op(int a, int b) { return std::gcd(a, b); }
int e() { return 0; }

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    atcoder::segtree<int, op, e> segs(arr);

    vector<pair<int, int>> segments;

    int first = 0;
    int maxRight = -1;
    int answer = 0;
    for (int last = 0; last < n; last++) {
        while (first < last && segs.prod(first, last + 1) < (last - first + 1)) first++;
        if (segs.prod(first, last + 1) == (last - first + 1)) {
            if (first > maxRight) {
                answer++;
                maxRight = last;
            }
        }
        debug(first, last);
        cout << answer << " ";
    }
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

