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

    map<int, array<int, 5>> val;
    val[1] = {1, 0, 0, 1, 1};

    int curr = 1;
    while (n--) {
        char x;
        cin >> x;

        if (x == '+') {
            int v; int w;
            cin >> v >> w;

            curr++;
            val[curr] = {
                val[v][0] + w,
                min(val[v][1] + w, w),
                min(val[v][2], min(val[v][1] + w, w)),
                max(val[v][3] + w, w),
                max(val[v][4], max(val[v][3] + w, w)),
            };
        }
        else {
            int u, v, k;
            cin >> u >> v >> k;
            if (k >= val[v][2] && k <= val[v][4]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }

        debug(val);
    }
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

