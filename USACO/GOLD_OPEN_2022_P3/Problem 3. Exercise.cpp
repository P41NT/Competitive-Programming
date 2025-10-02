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

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, m;
    cin >> n >> m;

    using mi = atcoder::modint;
    mi::set_mod(m);

    vector<bool> isPrime(n + 1, true);
    isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int j = 2 * i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }

    vector<int> primes(1);
    for (int i = 1; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    vector<vector<mi>> dp(primes.size(), vector<mi>(n + 1));
    for (int i = 0; i <= n; i++) dp[0][i] = 1;

    for (int i = 1; i < primes.size(); i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int p = primes[i]; p <= j; p *= primes[i]) {
                dp[i][j] += dp[i - 1][j - p] * p;
            }
        }
    }

    // for (int i = 0; i <= 3; i++) {
    //     for (int j = 0; j <= 5; j++) {
    //         std::cerr << dp[i][j].val() << " ";
    //     }
    //     std::cerr << std::endl;
    // }

    cout << dp[primes.size() - 1][n].val() << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

