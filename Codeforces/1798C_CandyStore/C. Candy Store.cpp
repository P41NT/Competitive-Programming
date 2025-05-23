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
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> brr(n);

    for (int i = 0; i < n; i++) cin >> arr[i] >> brr[i];

    int currlcm = brr[0];
    int currgcd = arr[0] * brr[0];

    int counter = 1;

    for (int i = 1; i < n; i++) {
        currlcm = lcm(currlcm, brr[i]);
        currgcd = gcd(currgcd, arr[i] * brr[i]);

        if (currgcd % currlcm != 0) {
            counter++;
            currlcm = brr[i];
            currgcd = arr[i] * brr[i];
        }
    }

    cout << counter << endl;
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

