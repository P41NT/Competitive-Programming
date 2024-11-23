#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/CompetitiveProgramming/debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"
#define int long long int

const int MOD = 998244353;

struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(int tc) {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int dp[n + 1][25][25];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= m; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    function<int(int, int, int)> solve;
    solve = [&](int i, int a, int b) -> int{
        int j = n - i - 1 - b + a;
        debug(i, a, b, j);

        if (a + b > m) return 30;
        if (i >= j) return a + b;
    
        if (dp[i][a][b] != -1) return dp[i][a][b];

        if (arr[i] == arr[j]) return dp[i][a][b] = solve(i + 1, a, b);
        return dp[i][a][b] = min(solve(i + 1, a + 1, b), solve(i, a, b + 1));
    };
    int answer = solve(0, 0, 0);

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         for (int k = 0; k <= m; k++) {
    //             cerr << dp[i][j][k] << " ";
    //         }
    //         cerr << endl;
    //     }
    //     cerr << endl;
    // }

    if (answer == 0) cout << "Case " << tc << ": Too easy" << endl;
    else if (answer > m) cout << "Case " << tc << ": Too difficult" << endl;
    else cout << "Case " << tc << ": " << answer << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
    int tc = 1;
	while (t--) { solve(tc++); }
}

