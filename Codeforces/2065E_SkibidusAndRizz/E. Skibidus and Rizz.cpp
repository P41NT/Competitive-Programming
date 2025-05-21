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
    int n, m, k;
    cin >> n >> m >> k;

    bool flip = false;
    if (n < m) { flip = true; swap(n, m); }

    if (n - m > k) {
        cout << -1 << endl;
        return;
    }

    string answer = "";
    bool last = 0;
    while (n >= k) {
        if (n >= k) {
            for (int i = 0; i < k; i++) answer += '0';
            n -= k;
            last = 0;
        }
        if (m >= k) {
            for (int i = 0; i < k; i++) answer += '1';
            m -= k;
            last = 1;
        }
    }
    if (last) {
        while (n--) answer += '0';
        while (m--) answer += '1';
    }
    else {
        while (m--) answer += '1';
        while (n--) answer += '0';
    }

    if (flip) {
        for (int i = 0; i < answer.size(); i++) {
            if (answer[i] == '0') cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    else cout << answer << endl;
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

