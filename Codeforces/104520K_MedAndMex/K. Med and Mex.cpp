#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/modint.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

using mi = atcoder::modint998244353;

const int maxn = 2e5;

vector<mi> fact(maxn + 5);

void preprocess() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= maxn; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

void solve() {
    int n;
    cin >> n;

    auto ncr = [&](int n, int r) -> mi {
        return fact[n] / (fact[r] * fact[n - r]);
    };

    for (int i = 1; i <= n; i++) {
        if (i == 1 || i > (n + 1) / 2) {
            cout << 0 << " ";
            continue;
        }
        int sz = 2 * i - 2;
        mi ans = ncr(n - i - 1, i - 2) * fact[sz] * fact[n - sz + 1];

        cout << ans.val() << " ";
    }
    cout << "\n";
}

int32_t main () {
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    preprocess();

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

