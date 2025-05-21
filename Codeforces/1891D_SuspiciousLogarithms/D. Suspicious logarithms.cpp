#include <bits/stdc++.h>
#include <cstdlib>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/modint.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace atcoder;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/Compocode/debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"
#define int unsigned long long

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

using mi = modint1000000007;

void solve() {
    int q;
    cin >> q;

    auto f = [](int x) -> int {
        for (int32_t i = 61; i >= 0; i--) {
            if (x & (1ull << i)) {
                return i;
            }
        }
        return 0;
    };

    auto g = [&](int x) -> mi {
        int rq = f(x);
        int curr = 1;
        int mul = f(x);
        while (rq <= x) {
            rq *= mul;
            curr++;
        }

        return curr - 1;
    };

    vector<tuple<int, int, mi>> intervals;

    for (int i = 2; i <= 60; i++) {
        int start = 1ll << i;
        int end = (1ll << (i + 1)) - 1;

        if (g(start) == g(end)) {
            intervals.push_back({start, end, g(start)});
        }
        else {
            int lower = start;
            int higher = end;
            int answer = lower;
            while (lower <= higher) {
                int mid = (lower + higher) >> 1;
                if (g(mid) == g(start)) {
                    lower = mid + 1;
                    answer = max(answer, mid);
                }
                else {
                    higher = mid - 1;
                }
            }
            intervals.push_back({start, answer, g(start)});
            intervals.push_back({answer + 1, end, g(end)});
        }
    }

    for (auto [l, r, c] : intervals) {
        debug(l, r, c.val());
    }

    auto getCum = [&](int x) -> mi {
        mi ans = 0;
        for (auto [l, r, c] : intervals) {
            if (l > x) return ans;
            if (x <= r) {
                ans += c * (x - l + 1);
                return ans;
            }
            else {
                ans += c * (r - l + 1);
            }
        }
        return ans;
    };

    while (q--) {
        int l, r;
        cin >> l >> r;
        mi ans = getCum(r) - getCum(l - 1);
        debug(getCum(r).val(), getCum(l - 1).val());

        cout << ans.val() << endl;
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

