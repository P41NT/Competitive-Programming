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
    int n;
    cin >> n;
    int m; 
    cin >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) { cin >> arr[i]; }

    vector<int> brr(m);
    for (int i = 0; i < m; i++) { cin >> brr[i]; }

    vector<vector<int>> insert(n + 1, vector<int>(0));

    vector<int> dp;
    dp.push_back(arr[0]);

    vector<int> dp2(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int lb = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if (lb == dp.size()) {
            dp2[i] = dp.size();
            dp.push_back(arr[i]);
        } 
        else {
            dp2[i] = lb;
            dp[lb] = arr[i];
        }
    }

    debug(dp);
    debug(dp2);


    int lis = dp.size() - 1;
    vector<pair<int, int>> c;

    sort(brr.begin(), brr.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        if (dp2[i] == lis) {
            c.push_back({arr[i], i});
        }
    }

    reverse(c.begin(), c.end());

    debug(c);

    int mx = *max_element(arr.begin(), arr.end());

    vector<int> beginning;

    for (int i = 0; i < m; i++) {
        if (brr[i] > mx) {
            beginning.push_back(brr[i]);
            continue;
        }
        int lower = 0, higher = n - 1;
        int answer = 0;
        while (lower <= higher) {
            int mid = (lower + higher) / 2;
            if (c[mid].second < brr[i]) {
                lower = mid + 1;
                answer = max(answer, mid);
            } else {
                higher = mid - 1;
            }
        }
        insert[answer].push_back(brr[i]);
        // insert[ind].push_back(brr[i]);
    }

    for (auto s : beginning) {
        cout << s << " ";
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)insert[i].size(); j++) {
            cout << insert[i][j] << " ";
        }
        cout << arr[i] << " ";
    }

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

