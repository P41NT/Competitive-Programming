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

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> arr(n + 1);
    for (int i = 0; i <= n; i++) arr[i] = (s[i] == 'R');

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));

    int first = 0, second = 0;
    function<int(int, int, int)> recur;
    recur = [&](int i, int prev, int prev2) -> int {
        if (i == n) {
            if (first == prev && second == first) return INT_MAX;
            if (first == prev && prev == prev2) return INT_MAX;
            return 0;
        }

        if (dp[i][prev][prev2] != -1) return dp[i][prev][prev2];

        int op1 = recur(i + 1, 0, prev);
        int op2 = recur(i + 1, 1, prev);

        if (arr[i] == 0) {
            if (prev == prev2 && prev == 0) return dp[i][prev][prev2] = 1 + op2;
            if (prev == prev2 && prev == 1) return dp[i][prev][prev2] = op1;
            return dp[i][prev][prev2] = min(1 + op2, op1);
        }
        else {
            if (prev == prev2 && prev == 0) return dp[i][prev][prev2] = op2;
            if (prev == prev2 && prev == 1) return dp[i][prev][prev2] = 1 + op1;
            return dp[i][prev][prev2] = min(op2, 1 + op1);
        }
    };

    auto cleardp = [&]() {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < 2; j++) 
                for (int k = 0; k < 2; k++) 
                    dp[i][j][k] = -1;

    };

    int answer = INT_MAX;
    int curr;

    first = 0, second = 0;
    curr = (arr[0] == 1) + (arr[1] == 1);
    curr += recur(2, 0, 0);
    answer = min(answer, curr);
    debug(curr);

    cleardp();
    first = 0, second = 1;
    curr = (arr[0] == 1) + (arr[1] == 0);
    curr += recur(2, 1, 0);
    answer = min(answer, curr);
    debug(curr);

    cleardp();
    first = 1, second = 0;
    curr = (arr[0] == 0) + (arr[1] == 1);
    curr += recur(2, 0, 1);
    answer = min(answer, curr);
    debug(curr);

    cleardp();
    first = 1, second = 1;
    curr = (arr[0] == 0) + (arr[1] == 0);
    curr += recur(2, 1, 1);
    answer = min(answer, curr);
    debug(curr);

    cerr << endl;
    cout << answer << endl;
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

