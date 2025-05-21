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
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    string s; cin >> s;

    for (int i = 0; i < n; i++) cin >> arr[i];

    auto chk = [&](int curr) {
        int k = 0; char col = 'R';
        for (int i = 0; i < n; i++) {
            if (arr[i] > curr) {
                if (col != s[i]) {
                    if (col == 'R') {
                        col = 'B';
                        k++;
                    }
                    else if (col == 'B') {
                        col = 'R';
                    }
                }
            }
        }

        debug(curr, k);

        return k <= x;
    };

    int lower = 0, higher = 1e9 + 5;
    int answer = 1e9 + 5;
    while (lower <= higher) {
        int mid = (lower + higher) >> 1;

        if (chk(mid)) {
            higher = mid - 1;
            answer = min(answer, mid);
        }
        else lower = mid + 1;
    }

    cout << answer << endl;
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

