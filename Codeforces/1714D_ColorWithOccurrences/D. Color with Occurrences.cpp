#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/Compocode/debug.cpp"
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
    string s; cin >> s;

    int n;
    cin >> n;

    vector<string> arr;

    for (int i = 0; i < n; i++) {
        string k; cin >> k;
        arr.push_back(k);
    }

    vector<pair<int, int>> answer;

    bool ok = true;

    int currInd = 0;
    while (currInd < s.length()) {
        int mxInd = currInd;
        pair<int, int> sm;
        for (int i = 0; i <= currInd; i++) {
            for (int j = 0; j < n; j++) {
                if (s.substr(i, arr[j].length()) == arr[j]) {
                    if (i + arr[j].length() > currInd) {
                        if (i + arr[j].length() > mxInd) {
                            mxInd = max(mxInd, i + (int)arr[j].length());
                            sm = {i + 1, j + 1};
                        }
                    }
                }
            }
        }

        debug(currInd, mxInd);

        if (mxInd == currInd) {
            cout << -1 << endl;
            return;
        }
        currInd = mxInd;
        answer.push_back(sm);
    }

    if (!ok) {
        cout << -1 << endl;
        return;
    }

    cout << answer.size() << endl;
    for (auto [a, b] : answer) {
        cout << b << " " << a << endl;
    }
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

