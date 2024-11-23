#include <bits/stdc++.h>
#include <climits>
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

    vector<int> cost(n);
    for (int i = 0; i < n; i++) cin >> cost[i];

    vector<string> s(n);
    vector<string> copy;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        copy.push_back(s[i]);
        string t = s[i];
        reverse(t.begin(), t.end());
        copy.push_back(t);
    }


    vector<pair<int, int>> arr(n);

    sort(copy.begin(), copy.end());
    debug(copy);
    for (int i = 0; i < n; i++) {
        string a = s[i];
        string b = a;
        reverse(b.begin(), b.end());

        int req1 = lower_bound(copy.begin(), copy.end(), a) - copy.begin();
        int req2 = lower_bound(copy.begin(), copy.end(), b) - copy.begin();

        arr[i] = {req1, req2};
    }

    debug(arr);

    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    const int inf = LLONG_MAX;

    function<int(int, int)> rec;
    rec = [&](int i, int k) -> int {
        if (i == n) return 0;
        int r = i;
        if (dp[r][k] != -1) return dp[i][k];
        int prev = k ? arr[i - 1].second: arr[i - 1].first;

        int answer = inf;
        if (arr[i].first >= prev) {
            int res = rec(i + 1, 0);
            if (res != inf)
                answer = min(answer, res);
        }
        if (arr[i].second >= prev) {
            int res = rec(i + 1, 1);
            if (res != inf)
                answer = min(answer, cost[i] + res);
        }
        debug(prev);
        debug(r, k, answer);
        return dp[r][k] = answer;
    };

    debug(rec(1, 0));

    int ans1 = rec(1, 0);
    int ans2 = rec(1, 1);
    if (ans2 != inf) ans2 += cost[0];

    int ans = min(ans1, ans2);

    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t;
    // cin >> t;
    t = 1;
	while (t--) {
        solve();
	}
}

