#include <bits/stdc++.h>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>

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
    int n;
    cin >> n;

    string s;
    cin >> s;
    s = "." + s;

    vector<vector<int>> prefixOdd(n + 2, vector<int>(26, 0));
    vector<vector<int>> prefixEven(n + 2, vector<int>(26, 0));

    vector<vector<int>> suffixOdd(n + 2, vector<int>(26, 0));
    vector<vector<int>> suffixEven(n + 2, vector<int>(26, 0));

    for (int i = 1; i <= n; i++) {
        debug(i);
        prefixOdd[i] = prefixOdd[i - 1];
        prefixEven[i] = prefixEven[i - 1];
        if (i & 1) {
            prefixOdd[i][s[i] - 'a']++;
        } else {
            prefixEven[i][s[i] - 'a']++;
        }
    }

    for (int i = n; i >= 1; i--) {
        suffixOdd[i] = suffixOdd[i + 1];
        suffixEven[i] = suffixEven[i + 1];
        if (i & 1) {
            suffixOdd[i][s[i] - 'a']++;
        } else {
            suffixEven[i][s[i] - 'a']++;
        }
    }

    if (n & 1) {
        int answer = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int smOdd = 0;
            int smEven = 0;
            int mxOdd = 0;
            int mxEven = 0;
            for (int z = 0; z < 26; z++) {
                int oddCount = prefixOdd[i - 1][z] + suffixEven[i + 1][z];
                int evenCount = prefixEven[i - 1][z] + suffixOdd[i + 1][z];
                smOdd += oddCount;
                smEven += evenCount;
                mxOdd = max(mxOdd, oddCount);
                mxEven = max(mxEven, evenCount);
            }
            smOdd -= mxOdd;
            smEven -= mxEven;
            if (smOdd + smEven + 1 < answer) {
                answer = smOdd + smEven + 1;
            }
        }
        cout << answer << endl;
    }
    else {
        int oddAnswer = accumulate(prefixOdd[n].begin(), prefixOdd[n].end(), 0ll)
            - *max_element(prefixOdd[n].begin(), prefixOdd[n].end());

        int evenAnswer = accumulate(prefixEven[n].begin(), prefixEven[n].end(), 0ll)
            - *max_element(prefixEven[n].begin(), prefixEven[n].end());

        cout << oddAnswer + evenAnswer << endl;
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

