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
    int n, d;
    cin >> n >> d;

    int currnines = 999999999999999999;
    int currdiv = pow(10, 18);
    for (int k = 18; k >= 1; k--) {
        if (n / currdiv != 0){
            int check = (n / currdiv - 1) * currdiv + currnines;
            int mn = n - check;

            if (mn >= 0 && mn <= d) {
                cout << check << endl;
                return;
            }
        }
        currdiv /= 10;
        currnines /= 10;
    }

    cout << n << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while ( t-- ) {
		solve();
	}
}
