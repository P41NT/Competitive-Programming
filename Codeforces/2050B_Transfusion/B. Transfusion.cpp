#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>


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
    for (int i = 0; i < n; i++) cin >> arr[i];

    int sm = accumulate(arr.begin(), arr.end(), 0ll);
    if (sm % n != 0) {
        cout << "NO" << endl;
        return;
    }

    int oddsum = 0;
    int evensum = 0;

    int oddnum = 0;
    int evenum = 0;

    for (int i = 0; i < n; i++) {
        if (i & 1) oddsum += arr[i], oddnum++;
        else evensum += arr[i], evenum++;
    }

    if (oddsum % oddnum != 0)  {
        cout << "NO" << endl;
        return;
    }
    if (oddsum / oddnum != sm / n) {
        cout << "NO" << endl;
        return;
    }

    if (evensum % evenum != 0) {
        cout << "NO" << endl;
        return;
    }
    if (evensum / evenum != sm / n) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
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

