#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// recursive derrangement formula d(n) = (n - 1) * (d(n - 1) + d(n - 2));

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

// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    pair<int, int> pointa = arr[0];
    pair<int, int> pointb = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i].first + arr[i].second > pointa.first + pointa.second) {
            pointa = arr[i];
        }
        if (arr[i].first - arr[i].second > pointb.first - pointb.second) {
            pointb = arr[i];
        }
    }

    auto query = [&](char c, int x) -> int {
        cout << "? " << c << " " << x << endl;
        cout.flush();
        int z;
        cin >> z;
        return z;
    };

    auto dist = [&](pair<int, int> a, pair<int, int> b) -> int {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };

    const int mx = 1e9;

    query('U', mx);
    query('U', mx);
    query('R', mx);
    query('R', mx);
    int q1 = query('R', mx);

    query('D', mx);
    query('D', mx);
    query('D', mx);
    query('D', mx);
    int q2 = query('D', mx);

    int aplusb = q1 + (pointa.first + pointa.second) - 5 * mx;
    int aminusb = q2 + (pointb.first - pointb.second) - 6 * mx;

    int a = (aplusb + aminusb) / 2;
    int b = (aplusb - a);

    cout << "! " << a << " " << b << endl;
    cout.flush();
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

