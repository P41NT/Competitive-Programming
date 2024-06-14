#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

char increment(char c, int i) {
    return 'a' + ((c - 'a') + i) % 26;
}

void solve() {
    string s;
    cin >> s;
    
    vector<pair<char, int>> arr;
    arr.push_back({s[0], 1});
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) arr[arr.size() - 1].second++;
        else arr.push_back({s[i], 1});
    }

    int n = arr.size();

    // for (auto s : arr) cerr << s.first << " " << s.second << endl;

    string ans = "";
    for (int i = 0; i < n; i++) {
        if (arr[i].second == 1) ans += arr[i].first;
        else if (arr[i].second == 2) {
            char c = arr[i].first;
            c = increment(c, 1);
            if (i > 0 && c == arr[i - 1].first)
                c = increment(c, 1);
            ans += c;
            ans += arr[i].first;
        }
        else if (arr[i].second == 3) {
            char c = arr[i].first;
            ans += c;
            ans += increment(c, 1);
            ans += c;
        }
        else {
            if (arr[i].second % 2 == 1) {
                char c = increment(arr[i].first, 1);
                for (int j = 0; j < arr[i].second - 1; j += 2) {
                    ans += arr[i].first;
                    ans += c;
                }
                ans += arr[i].first;
            }
            else {
                char c = 'a';
                while(arr[i].first == c || 
                        (ans.length() && ans[ans.length() - 1] == c)) 
                    c = increment(c, 1);

                cerr << c << endl;
                for (int j = 0; j < arr[i].second; j += 2) {
                    ans += c;
                    ans += arr[i].first;
                }
            }
        }
    }
    cout << ans << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while ( t-- ) {
		solve();
	}
}

