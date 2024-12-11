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

inline int log10(int x) {
    int ans = 0;
    while (x) {
        x /= 10;
        ans++;
    }

    return ans;
}

void solve() {
    int x, p;
    cin >> x >> p;

    int y, r;
    cin >> y >> r;

    while (log10(x) > log10(y)) { y *= 10; r--; }
    while (log10(x) < log10(y)) { x *= 10; p--; }

    debug(x, p, y, r);

    if (p > r) {cout << ">" << endl;}
    else if (p < r) {cout << "<" << endl;}
    else {
        if (x > y) { cout << ">" << endl; }
        else if (x < y) { cout << "<" << endl; }
        else cout << "=" << endl;
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

