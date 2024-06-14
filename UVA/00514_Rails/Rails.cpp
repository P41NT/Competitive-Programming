#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define endl "\n"

void solve(int n) {

    vector<int> curr(n);

    while (true) {
OUTOFTHIS:
        int start; cin >> start;
        if (start == 0) return;
        curr[0] = start;
        for (int i = 1; i < n; i++) cin >> curr[i];

        vector<bool> visited(n + 1, false);

        vector<int> st;
        int j = 1;
        for (int i = 0; i < n; i++) {
            if (curr[i] >= j) {
                for (; j <= curr[i]; j++) {
                    if (!visited[j]) st.push_back(j);
                    else {
                        cout << "No" << endl;
                        goto OUTOFTHIS;
                    }
                }
            }
            if (curr.size() == 0) {
                cout << "No" << endl;
                goto OUTOFTHIS;
            }
            if (curr[i] == st[st.size() - 1]) {
                st.pop_back();
                visited[curr[i]] = true;
            }
            else {
                cout << "No" << endl;
                goto OUTOFTHIS;
            }
        }
        cout << "Yes" << endl;
    }
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	while (true) {
        cin >> t; 
        if (t == 0) break;
		solve(t);
        cout << endl;
	}
}

