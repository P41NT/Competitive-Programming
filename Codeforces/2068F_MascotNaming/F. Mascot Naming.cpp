#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <set>

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
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    string t;
    cin >> t;
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == t[count])
                count++;
            if (count == t.size()) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;

    // vector<vector<string>> stitch(n, vector<string>(1, ""));
    vector<string> stitch(t.size() + 1);
    int mxCounter = 0;
    for (int i = 0; i < n; i++) {
        string &str = arr[i];
        int counter = 0;
        for (int j = 0; j < str.size(); j++) {
            if (t[counter] == str[j]) {
                counter++;
            }
            else {
                stitch[counter].push_back(str[j]);
            }
        }
        mxCounter = max(mxCounter, counter);
    }

    debug(stitch);

    string answer = "";
    for (int i = 0; i <= mxCounter; i++) {
        answer += stitch[i];
        if (i < mxCounter) answer += t[i];
    }

    cout << answer << endl;
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

