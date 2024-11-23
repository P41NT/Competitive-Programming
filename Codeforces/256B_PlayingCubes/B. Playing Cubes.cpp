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

    int n_ = n, m_ = m;

    int alice = 0, bob = 0;
    vector<int> try1;
    try1.push_back(1);
    n--;

    for (int i = 1; i < n_ + m_; i++) {
        debug(i, try1);
        if (i % 2 == 1) {
            if (try1.back() == 1) {
                if (m) try1.push_back(2), m--;
                else try1.push_back(1), n--;
            }
            else {
                if (n) try1.push_back(1), n--;
                else try1.push_back(2), m--;
            }
        }
        else {
            if (try1.back() == 1) {
                if (n) try1.push_back(1), n--;
                else try1.push_back(2), m--;
            }
            else {
                if (m) try1.push_back(2), m--;
                else try1.push_back(1), n--;
            }
        }
    }

    debug(try1);

    int score1 = 0, score2 = 0;
    for (int i = 0; i < n_ + m_ - 1; i++) {
        if (try1[i + 1] == try1[i]) score1++;
        else score2++;
    }

    alice = score1, bob = score2;

    try1.clear();
    n = n_, m = m_;
    try1.push_back(2);
    m--;

    for (int i = 1; i < n_ + m_; i++) {
        debug(i, try1);
        if (i % 2 == 1) {
            if (try1.back() == 1) {
                debug(i, n, m);
                if (m) try1.push_back(2), m--;
                else try1.push_back(1), n--;
            }
            else {
                if (n) try1.push_back(1), n--;
                else try1.push_back(2), m--;
            }
        }
        else {
            if (try1.back() == 1) {
                if (n) try1.push_back(1), n--;
                else try1.push_back(2), m--;
            }
            else {
                if (m) try1.push_back(2), m--;
                else try1.push_back(1), n--;
            }
        }
    }

    debug(try1);

    score1 = 0, score2 = 0;
    for (int i = 0; i < n_ + m_ - 1; i++) {
        if (try1[i + 1] == try1[i]) score1++;
        else score2++;
    }

    if (score1 > alice || score2 < bob)  {
        alice = score1, bob = score2;
    }

    cout << alice << " " << bob << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t;
    t = 1;
    // cin >> t;
	while (t--) { solve(); }
}

