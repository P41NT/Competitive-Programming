#include <algorithm>
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

    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end());

    int p;
    cin >> p;
    vector<int> pegs(p);
    set<int> stpeg;

    for (int i = 0; i < p; i++) {
        cin >> pegs[i];
        stpeg.insert(pegs[i]);
    }

    sort(pegs.begin(), pegs.end());

    vector<int> temp(n);

    for (int i = 0; i < n; i++) {
        int start = lower_bound(pegs.begin(), pegs.end(), arr[i].first) - pegs.begin();
        int end = upper_bound(pegs.begin(), pegs.end(), arr[i].second) - pegs.begin() - 1;

        if (end - start + 1 > 2) {
            cout << "impossible" << endl;
            return;
        }

        temp[i] = end - start + 1;
    }


    debug(arr);
    debug(temp);

    vector<int> answer;

    for (int i = 0; i < n; i++) {
        if (temp[i] == 2) continue;
        if (temp[i] == 0) {
            int in = arr[i].second - 1;
            while (stpeg.count(in)) in--;
            answer.push_back(in);
            stpeg.insert(in);
            temp[i]++;
        }
        if (temp[i] == 1) {
            if (i + 1 == n) {
                int in = arr[i].second ;
                while (stpeg.count(in)) in--;
                answer.push_back(in);
                stpeg.insert(in);
                temp[i]++;
            }
            else if (arr[i + 1].first == arr[i].second) {
                if (temp[i + 1] != 2) {
                    if (!stpeg.count(arr[i].second)) {
                        answer.push_back(arr[i].second);
                        stpeg.insert(arr[i].second);
                        temp[i]++;
                        temp[i + 1]++;
                    }
                    else {
                        int in = arr[i].second - 1;
                        while (stpeg.count(in)) in--;
                        answer.push_back(in);
                        stpeg.insert(in);
                        temp[i]++;
                    }
                }
                else {
                    int in = arr[i].second - 1;
                    while (stpeg.count(in)) in--;
                    answer.push_back(in);
                    stpeg.insert(in);
                    temp[i]++;
                }
            }
            else {
                int in = arr[i].second;
                while (stpeg.count(in)) in--;
                answer.push_back(in);
                stpeg.insert(in);
            }
        }
    }

    cout << answer.size() << endl;
    for (auto s : answer) {
        cout << s << " ";
    }
    cout << endl;
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

