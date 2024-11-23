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
    int n, m;
    cin >> n >> m;
    m--;

    string s;
    cin >> s;

    if (m >= n / 2) {
        reverse(s.begin(), s.end());
        m = n - m - 1;
    }

    debug(s, m);
    debug(s[m]);

    int mxL = m + 1;
    int mxR = m - 1;
    int sum = 0;

    for (int i = 0; i < n / 2; i++) {
        int diff = abs(s[n - i - 1] - s[i]);
        diff = min(diff, (26 - diff) % 26);
        sum += diff;
    }

    for (int i = 0; i < (n + 1)/2; i++) {
        if (s[i] != s[n - i - 1]) {
            mxL = min(mxL, i);
            mxR = max(mxR, i);
            debug(i, mxR);
        }
    }

    debug(mxL, mxR);
    
    if (mxL == m + 1 && mxR == m - 1) {
        cout << sum << endl;
        return;
    }
    else if (mxL == m + 1) {
        sum += mxR - m;
        cout << sum << endl;
    }
    else if (mxR == m - 1) {
        sum += m - mxL;
        cout << sum << endl;
    }
    else {
        int dist1 = m - mxL;
        int dist2 = mxR - m;

        int dist = min(dist1, dist2) * 2 + max(dist1, dist2);
        sum += dist;
        cout << sum << endl;
    }
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

