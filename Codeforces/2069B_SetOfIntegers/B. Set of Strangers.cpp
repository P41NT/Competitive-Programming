#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    set<int> st;

    for (int i = 0; i < n;i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            st.insert(arr[i][j]);
        }
    }

    int dir_x[4] = {-1, 0, 1, 0};
    int dir_y[4] = {0, -1, 0, 1};

    set<int> st2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int nexti = i + dir_x[k];
                int nextj = j + dir_y[k];

                if (nexti < 0 || nextj < 0 || nexti >= n || nextj >= m) {
                    continue;
                }
                else {
                    if (arr[nexti][nextj] == arr[i][j]){
                        st2.insert(arr[i][j]);
                    }
                }
            }
        }
    }

    map<int, int> freq;

    for (auto s : st) freq[s]++;
    for (auto s : st2) freq[s]++;

    const int inf = 1e12;
    int answer = st.size() + st2.size();
    int sum = answer;

    for (auto s : freq) {
        answer = min(answer, sum - s.second);
    }

    cout << answer << endl;
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

