#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.first.first != b.first.first)
        return a.first.first > b.first.first;
    if (a.first.second != b.first.second)
        return b.first.second > a.first.second;
    return a.second < b.second;
}

void solve() {
    vector<pair<pair<int, int>, int>> score(101);
    for (int i = 1; i <= 100; i++) score[i].second = i;

    vector<vector<int>> solved(101, vector<int>(10));
    vector<bool> submitted(101, false);
    vector<vector<bool>> AC(101, vector<bool>(10));
    string submission;
    // getline(cin, submission);
    while (getline(cin, submission) && submission.length() != 0){
        istringstream in(submission);
        int contestant, problem, time; char verdict;
        in >> contestant >> problem >> time >> verdict;

        submitted[contestant] = true;
        if (!AC[contestant][problem]) {
            if (verdict == 'C') {
                score[contestant].first.first++;
                score[contestant].first.second += time;
                score[contestant].first.second += solved[contestant][problem] * 20;
                AC[contestant][problem] = true;
            }
            else if (verdict == 'I') {
                solved[contestant][problem]++;
            }
        }
    }

    sort(score.begin(), score.end(), cmp);

    for (int i = 0; i <= 100; i++) {
        if (!submitted[score[i].second]) continue;
        auto s = score[i];
        cout << s.second << " " << s.first.first << " " << s.first.second << endl;
    }
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
    string temp;
    getline(cin, temp);
    getline(cin, temp);
	while ( t-- ) {
		solve();
        if (t) cout << endl;
	}
}

