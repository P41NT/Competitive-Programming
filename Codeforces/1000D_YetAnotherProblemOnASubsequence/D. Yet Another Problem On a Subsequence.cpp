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

const int maxf = 1e5;

vector<mi> fact(maxf + 5);
void preprocess() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= maxf; i++) fact[i] = i * fact[i - 1];
}

mi combination(int n, int r) {
    return fact[n] / (fact[n - r] * fact[r]);
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<mi> dp(n + 1);
    vector<bool> visited(n + 1);

    // function<mi(int)> recur;
    // recur = [&](int i) -> mi{
    //     if (i == n) return 1;
    //
    //     if (visited[i]) return dp[i];
    //
    //     mi answer = 0;
    //     for (int j = i + arr[i]; j < n; j++) {
    //         mi factor = combination(j - i, arr[i]);
    //         mi nextans = recur(j + 1);
    //
    //         answer += factor * nextans;
    //     }
    //     debug(i, (int)answer);
    //     return dp[i] = answer;
    // };

    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        mi answer = 0;
        if (arr[i] <= 0) {
            dp[i] = 0;
            continue;
        }

        for (int j = i  + arr[i]; j < n; j++) {
            mi factor = combination(j - i, arr[i]);
            mi nextans = dp[j + 1];

            answer += factor * nextans;
        }
        dp[i] = answer;
    }

    for (int i = 0; i <= n; i++) 
        cerr << (int) dp[i] << " ";
    cerr << endl;

    mi answer = accumulate(dp.begin(), dp.end() - 1, (mi)0);
    cout << (int)answer << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    preprocess();
    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

