#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/modint.hpp>

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

using mi = atcoder::modint1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> pos(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) { pos[arr[i]] = i; }

    int left = pos[0], right = pos[0];

    mi answer = 1;

    for (int i = 1; i < n; i++) {
        int nxt = pos[i];
        if (nxt >= left && nxt <= right) {
            answer *= (right - left + 1) - i;
            continue;
        }
        if (nxt < left) { left = nxt; }
        else right = nxt;
    }

    cout << answer.val() << endl;
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

