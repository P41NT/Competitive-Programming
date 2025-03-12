#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/segtree>

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

int op(int a, int b) { return gcd(a, b); }
int e() { return 0; }

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) { cin >> arr[i]; }
    for (int i = 0; i < n - 1; i++) arr.push_back(arr[i]);

    atcoder::segtree<int, op, e> segs(arr);

    auto chk = [&](int curr) -> bool {
        int answer = segs.prod(0, curr + 1);
        for (int i = 0; i < n; i++) {
            int currcheck = segs.prod(i, i + curr + 1);
            if (currcheck != answer) return false;
        }

        return true;
    };

    if (*max_element(arr.begin(), arr.end()) == *min_element(arr.begin(), arr.end())) {
        cout << 0 << endl;
        return;
    }

    int lower = 1, higher = n;
    int answer = n;
    while (lower <= higher) {
        int mid = (lower + higher) >> 1;
        if (chk(mid)) {
            answer = min(answer, mid);
            higher = mid - 1;
        }
        else { lower = mid + 1; }
    }

    cout << answer << endl;
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

