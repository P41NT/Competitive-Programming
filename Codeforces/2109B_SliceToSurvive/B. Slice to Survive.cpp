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
    int n, m;
    int a, b;
    cin >> n >> m;
    cin >> a >> b;

    auto answer = [&](int x, int y) {
        debug(x, y);
        int ans = 0;
        while (x > 1) {
            ans++;
            x = x / 2 + (x % 2);
        }
        while (y > 1) {
            ans++;
            y = y / 2 + (y % 2);
        }
        return ans;
    };

    int answer1 = answer(a, m);
    answer1 = min(answer1, answer(n, b));
    answer1 = min(answer1, answer(n - a + 1, m));
    answer1 = min(answer1, answer(n, m - b + 1));
    answer1++;

    cout << answer1 << endl;
    cerr << endl;
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

