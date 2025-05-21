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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int req = a * b;

    auto check_range = [&](int p, int s, int t) -> bool {
        int checker = ((s / p) + 1) * p;
        return checker <= t;
    };
    auto getchecker = [&](int p, int s, int t) -> int {
        int checker = ((s / p) + 1) * p;
        return checker;
    };

    vector<int> divisors1;
    vector<int> divisors2;

    for (int g = 1; g * g <= a; g++) {
        if (a % g == 0) {
            divisors1.push_back(g);
            if (a / g != g) divisors1.push_back(a / g);
        }
    }

    for (int g = 1; g * g <= b; g++) {
        if (b % g == 0) {
            divisors2.push_back(g);
            if (b / g != g) divisors2.push_back(b / g);
        }
    }

    debug(divisors1);
    debug(divisors2);

    for (auto r1 : divisors1) {
        for (auto r2 : divisors2) {
            int gg = r1 * r2;
            if (!check_range(gg, a, c)) continue;
            if (!check_range(req / gg, b, d)) continue;
            cout << getchecker(gg, a, c) << " " << getchecker(req / gg, b, d) << endl;
            return;
        }
    }

    cout << -1 << " " << -1 << endl;
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

