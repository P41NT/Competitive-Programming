#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

void solve() {
    string lower, upper;
    cin >> lower >> upper;

    while (lower.size() < upper.size()) lower = '0' + lower;

    int mx = upper.size();

    int dp[mx][2][2][2];

    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }

    function<int(int, bool, bool, bool)> recur;
    recur = [&](int pos, bool low, bool high, bool started) -> int {
        if (pos == mx) {
            if (started) return 1;
            return 0;
        }

        auto temp = dp[pos][low][high][started];
        if (temp != -1) return temp;

        int answer = 0;
        int first = low ? 0 : lower[pos] - '0';
        int second = high ? 9 : upper[pos] - '0';

        for (int i = first; i <= second; i++) {
            int curr = recur(pos + 1, (low || i > first), (high || i < second), started || (i > 0));
            if (started || (i > 0)) curr *= i;
            answer = max(answer, curr);
        }

        return dp[pos][low][high][started] = answer;
    };

    string answerString = "";
    function<void(int, int, int, int)> findString;
    findString = [&](int pos, bool low, bool high, bool started) {

        if (pos == mx) return;

        int first = low ? 0 : lower[pos] - '0';
        int second = high ? 9 : upper[pos] - '0';

        int answer = dp[pos][low][high][started];

        for (int i = first; i <= second; i++) {
            int curr = recur(pos + 1, (low || i > first), (high || i < second), started || (i > 0));
            if (started || (i > 0)) curr *= i;
            if (curr == answer) {
                if (started || (i > 0)) answerString.push_back('0' + i);
                findString(pos + 1, (low || i > first), (high || i < second), started || (i > 0));
                break;
            }
        }
    };

    int ans = recur(0, false, false, false);
    findString(0, false, false, false);

    cout << answerString << endl;
    // cout << stoi(answerString) << endl;
    // cout << ans << endl;
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

