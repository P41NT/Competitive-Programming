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
    int p, y;
    cin >> p >> y;

    int t = y + 1;
    while(t--) {
        if (t <= p) {
            cout << -1 << endl;
            return;
        }

        bool found = true;
        for (int f = 1; f * f <= t; f++) {
            if (t % f == 0) {
                if (f >= 2 && f <= p) {
                    found = false;
                    break;
                }
                if (t/f >= 2 && t/f <= p) {
                    found = false;
                    break;
                }
            }
        }

        if (found) {cout << t << endl; return;}
    }
    cout << -1 << endl;
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

