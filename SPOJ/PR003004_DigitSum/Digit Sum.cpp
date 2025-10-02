#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #ifndef ONLINE_JUDGE
// #include "../debug.cpp"
// #define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
// #else
#define debug(...)
#define debugArr(...)
// #endif

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int a, b;
    cin >> a >> b;

    if (a == 0) a++;

    string stringb = to_string(b);
    string stringa = to_string(a - 1);

    vector<vector<pair<int, int>>> dp;

    function<pair<int, int>(int, bool, string&)> recur;
    recur = [&](int dig, bool free, string &s) -> pair<int, int> {
        if (dig == s.size()) {
            return make_pair(0, 1);
        }
        int lim = free ? 9 : s[dig] - '0';

        if (dp[dig][free].first != -1) return dp[dig][free];

        int answer = 0;
        int numWays = 0;
        for (int i = 0; i <= lim; i++) {
            auto [sm, nextWays] = recur(dig + 1, free || (i != lim), s);
            answer += sm + nextWays * i;
            numWays += nextWays;
        }
        debug(dig, answer, s);

        return dp[dig][free] = make_pair(answer, numWays);
    };

    dp = vector<vector<pair<int, int>>>(stringb.length(), vector<pair<int, int>>(2, {-1, -1}));
    auto [ans1, num1] = recur(0, false, stringb);

    dp = vector<vector<pair<int, int>>>(stringa.length(), vector<pair<int, int>>(2, {-1, -1}));
    auto [ans2, num2] = recur(0, false, stringa);

    cout << ans1 - ans2 << endl;
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

