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
    int n, k;
    cin >> n >> k;

    if (n < 60 && k > (1ll << (n - 1))) {
        cout << -1 << endl;
        return;
    }

    function<void(int, int, int)> answer;
    answer = [&](int i, int curr, int k) {
        if (curr == 1) {
            cout << i << " ";
            return;
        }

        if (curr >= 60) {
            cout << i << " ";
            answer(i + 1, curr - 1, k);
        }
        else {
            int fn = (1ll << (curr - 2));

            if (k > fn) {
                answer(i + 1, curr - 1, k - fn);
                cout << i << " "; 
            }
            else {
                cout << i << " ";
                answer(i + 1, curr - 1, k);
            }
        }
    };
    answer(1, n, k);
    cout << endl;
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

