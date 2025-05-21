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
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    if (n % 2 == 0) {
        int answer = 0;
        int nxt = n + 1;
        for (int i = 1; i <= nxt / 2; i++) answer = answer ^ arr[i];
        arr.push_back(answer);
        n++;
    }

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) { pref[i] = pref[i - 1] ^ arr[i]; }

    debug(pref);

    function<int(int)> pre;
    pre = [&](int curr) -> int {
        if (curr <= n) return pref[curr];
        if (curr % 2 == 1) return pref[n];
        return pref[n] ^ pre(curr / 2);
    };
    // 69 -> 38 -> 19

    if (l <= n) {
        cout << arr[l] << endl;
        return;
    }
    cout << pre(l / 2) << endl;

    // function<int(int)> recur;
    // recur = [&](int curr) -> int {
    //     // debug(curr, pref[curr]);
    //     if (curr <= n) return arr[curr];
    //     if (curr % 2 == 1) return pref[n];
    //
    // };
    // cerr << endl;

    // int answer = recur(l);
    // cout << answer << endl;
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

