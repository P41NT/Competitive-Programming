#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/CompetitiveProgramming/debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;

    vector<int> given(n / 2);
    for (int i = 0; i < n / 2; i++) cin >> given[i];
    
    set<int> givenset;
    for (auto s : given) givenset.insert(s);

    set<int> notgiven;
    for (int i = 1; i <= n; i++) {
        if (!givenset.count(i)) notgiven.insert(i);
    }

    vector<int> answer(n);

    for (int i = n / 2 - 1; i >= 0; i--) {
        auto req = notgiven.lower_bound(given[i]);
        if (req == notgiven.begin()) {
            cout << -1 << endl;
            return;
        }
        req--;
        answer[2 * i + 1] = given[i];
        answer[2 * i] = *req;

        notgiven.erase(req);
    }

    map<int, int> freqcheck;
    for (int i = 0; i < n; i++) {
        if (freqcheck[answer[i]] != 0) {
            cout << -1 << endl;
            return;
        }
        freqcheck[answer[i]]++;
    }


    for (auto s : answer) cout << s << " ";
    cout << endl;
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

