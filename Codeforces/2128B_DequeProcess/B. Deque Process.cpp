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

// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);

void solve() {
    int n;
    cin >> n;

    deque<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> temp;

    bool lr = false;
    string answer;
    while (arr.size()) {
        if (arr.size() == 1) {
            temp.push_back(arr.front());
            arr.pop_front();
            answer.append("L");
        }
        else {
            int l = arr.front();
            int r = arr.back();
            if (lr) {
                temp.push_back(min(l, r));
                temp.push_back(max(l, r));
                if (min(l, r) == l) answer.append("LR");
                else answer.append("RL");
            }
            else {
                temp.push_back(max(l, r));
                temp.push_back(min(l, r));
                if (max(l, r) == l) answer.append("LR");
                else answer.append("RL");
            }
            lr = !lr;

            arr.pop_front();
            arr.pop_back();
        }
    }

    for (int i = 0; i < n - 4; i++) {
        if (temp[i] < temp[i + 1] && temp[i + 1] < temp[i + 2] && temp[i + 2] < temp[i + 3] && temp[i + 3] < temp[i + 4]) {
            string other = answer;
            answer = "";
            for (int j = 0; j < n; j++) {
                if (other[j] == 'L')
                    answer.push_back('R');
                else 
                    answer.push_back('L');
            }
        }
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

