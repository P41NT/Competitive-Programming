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
    string s;
    cin >> s;

    int n = s.size();

    deque<char> arr;
    for (int i = 0; i < n; i++) arr.push_back(s[i]);

    while (!arr.empty() && arr.front() == arr.back()) {
        arr.pop_front();
        arr.pop_back();
    }

    if (arr.empty()) {
        cout << 0 << endl;
        return;
    }

    n = arr.size();

    map<char, int> original_freq;
    for (auto s : arr) original_freq[s]++;

    debug(original_freq);

    auto chk = [&](int curr) -> bool {
        debug(curr);
        for (int i = curr; i < n / 2; i++) {
            if (arr[i] != arr[n - 1 - i]) {
                return false;
            }
        }
        debug(curr);
        debug(arr);
        map<char, int> freq;
        for (int i = max(n / 2, curr); i < n; i++) {
            freq[arr[i]]++;
        }

        for (auto s : freq) {
            if (s.second > original_freq[s.first] / 2) {
                return false;
            }
        }
        return true;
    };

    debug(arr);

    int lower = 0, higher = n;
    int answer = n;
    while (lower <= higher) {
        int mid = (lower + higher) >> 1;
        if (chk(mid)) {
            answer = min(answer, mid);
            higher = mid - 1;
        }
        else lower = mid + 1;
    }

    reverse(arr.begin(), arr.end());
    lower = 0, higher = n;
    while (lower <= higher) {
        int mid = (lower + higher) >> 1;
        if (chk(mid)) {
            answer = min(answer, mid);
            higher = mid - 1;
        }
        else lower = mid + 1;
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

