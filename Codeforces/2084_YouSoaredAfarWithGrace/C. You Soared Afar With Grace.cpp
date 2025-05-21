#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

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
    int n;
    cin >> n;

    map<int, int> matches;

    vector<int> arr(n);
    vector<int> brr(n);

    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (matches.count(arr[i])) {
            if (matches[arr[i]] != brr[i]) {
                ok = false;
                break;
            }
        }
        else if (matches.count(brr[i])) {
            if (matches[brr[i]] != arr[i]) {
                ok = false;
                break;
            }
        }
        else {
            matches[arr[i]] = brr[i];
        }
    }

    if (!ok) {
        cout << "-1" << endl;
        return;
    }

    map<int, int> location;
    if (n & 1) {
        int repeating = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == brr[i]) repeating = i;
            break;
        }
        cout << repeating << " " << (n / 2 + 1);
    }
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

