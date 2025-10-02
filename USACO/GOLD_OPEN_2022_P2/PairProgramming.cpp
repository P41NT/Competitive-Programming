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

using mi = atcoder::modint1000000007;

void solve() {
    int n;
    cin >> n;

    debug(n);
    
    string tempa;
    string tempb;
    cin >> tempa >> tempb;

    // a = "." + a;
    // b = "." + b;

    string a = ".";
    string b = ".";

    bool done1 = false;
    bool done2 = false;

    for (int i = 0; i < n; i++) {
        if (tempa[i] == '1') continue;
        else if (tempa[i] == '+') a.push_back('+');
        else if (tempa[i] == '0') a = ".0";
        else  a.push_back('2');

    }
    for (int i = 0; i < n; i++) {
        if (tempb[i] == '1') continue;
        else if (tempb[i] == '+') b.push_back('+');
        else if (tempb[i] == '0') b = ".0";
        else b.push_back('2');
    }


    n = a.size() - 1;
    int m = b.size() - 1;

    debug(a, b, n, m);

    vector<vector<mi>> dp(n + 1, vector<mi>(m + 1));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 0; i <= m; i++) dp[0][i] = 1;

    vector<int> pref1(n + 1);
    vector<int> pref2(m + 1);

    for (int i = 1; i <= n; i++) 
        pref1[i] = pref1[i - 1] + (a[i] == '+');

    for (int i = 1; i <= m; i++) 
        pref2[i] = pref2[i - 1] + (b[i] == '+');

    debug(pref1);
    debug(pref2);
    
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == '0' && b[j] == '0') dp[i][j] = 1;
            else if (a[i] == '0') dp[i][j] = pref2[j] + 1;
            else if (b[j] == '0') dp[i][j] = pref1[i] + 1;
            else if (a[i] == b[j]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][m].val() << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

