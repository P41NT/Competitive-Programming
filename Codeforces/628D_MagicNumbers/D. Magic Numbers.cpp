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
    int m, d;
    cin >> m >> d;

    string a, b;
    cin >> a >> b;

    using mi2 = atcoder::modint;
    mi2::set_mod(m);

    int mx = b.size();

    // mi dp[mx][2][m][2];
    vector<vector<vector<mi>>> dp(mx, vector<vector<mi>>(2, vector<mi>(m)));
    vector<vector<vector<bool>>> visited(mx, vector<vector<bool>>(2, vector<bool>(m)));

    function<mi(int, bool, mi2, bool)> recur;
    recur = [&](int dig, bool tight, mi2 curr, bool ok) -> mi {
        if (dig == b.size()) {
            if (tight && !ok) return 0;
            if (curr == 0) return 1;
            return 0;
        }

        if (visited[dig][tight][curr.val()]) return dp[dig][tight][curr.val()];

        string &num = ok ? b : a;

        int high = tight ? num[dig] - '0' : 9;
        int low = (dig == 0) ? 1 : 0;

        if (dig % 2 == 1) {
            if (d > high) return 0;
            auto val = recur(dig + 1, tight & (d == high), curr * 10 + d, ok);
            debug(dig, val.val());
            visited[dig][tight][curr.val()] = true;
            return dp[dig][tight][curr.val()] = val;
        }
        else {
            mi answer = 0;
            for (int i = low; i <= high; i++) {
                if (i == d) continue;
                answer += recur(dig + 1, tight & (i == high), curr * 10 + i, ok);
            }
            debug(dig, answer.val());
            visited[dig][tight][curr.val()] = true;
            return dp[dig][tight][curr.val()] = answer;
        }
    };

    mi ans1 = recur(0, 1, 0, 1);
    dp = vector<vector<vector<mi>>>(mx, vector<vector<mi>>(2, vector<mi>(m, 0)));
    visited = vector<vector<vector<bool>>>(mx, vector<vector<bool>>(2, vector<bool>(m, false)));
    mi ans2 = recur(0, 1, 0, 0);

    debug(ans1.val(), ans2.val());

    cout << (ans1 - ans2).val() << endl;
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

