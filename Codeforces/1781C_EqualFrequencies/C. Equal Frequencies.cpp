#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool cmp(pair<int, char> a, pair<int, char> b) {
    return a.first > b.first;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<pair<int, char>> freq(26);
    for (int i = 0; i < 26; i++) freq[i].second = 'a' + i;
    for (char c : s) freq[c - 'a'].first++;

    sort(freq.begin(), freq.end(), cmp);

    int minchanges = LONG_MAX, mink = LONG_MAX;
    for (int k = 1; k * k <= n; k++) {
        if (n % k == 0) {
            int chk[] = {k, n/k};
            for (auto s : chk) {
                if (n/s > 26) continue;
                int changes = 0;
                for (int i = 0; i < n/s; i++) 
                    changes += abs(s - freq[i].first);
                for (int i = n/s; i < 26; i++) 
                    changes += freq[i].first;
                changes /= 2;
                if (changes < minchanges)
                    minchanges = changes, mink = s;
            }
        }
    }

    int maxind = n/mink;
    int extra = 0;
    vector<char> nextel;


    int lst = maxind;
    for (int i = maxind; i < 26; i++) {
        if (freq[i].first) lst = i;
        extra += freq[i].first;
        freq[i].first = 0;
    }

    for (int i = 0; i < maxind; i++) {
        // if (freq[i].first) {
        //     cerr << freq[i].first << " " << freq[i].second << " " << extra << endl;
        // }
        if (freq[i].first >= mink) {
            extra += (freq[i].first - mink);
            freq[i].first = mink;
        }
        else if (extra > 0) {
            for (int j = 0; j < mink - freq[i].first; j++) 
                nextel.push_back(freq[i].second);
            extra -= (mink - freq[i].first);
        }
    }

    int currl = lst;
    while (extra && currl < 26) {
        for (int i = 0; i < mink; i++)
            nextel.push_back(freq[currl].second);
        currl++;
        extra -= mink;
    }

    map<char, int> mp;
    for (int i = 0; i < 26; i++) 
        mp[freq[i].second] = freq[i].first;

    string ans = "";
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (mp[s[i]]) {
            ans += s[i];
            mp[s[i]]--;
        }
        else if (curr < nextel.size()) 
            ans += nextel[curr++];
    }

    cout << curr << endl << ans << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while ( t-- ) {
		solve();
	}
}

