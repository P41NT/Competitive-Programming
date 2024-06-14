#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

bool isPalindrome(int n) { 
    string str = to_string(n); 
    int len = str.length(); 
    for(int i = 0; i < len/2; i++) { 
        if(str[i] != str[len-1-i]) 
            return false; 
    } 
    return true; 
}

vector<int> palindromes;

void generatePalindromes(int n) { 
    for(int i = 1; i < n; i++) { 
        if(isPalindrome(i)) palindromes.push_back(i);
    } 
}

const int mod = 1e9 + 7;
int n = 4 * 1e4 + 5;
int m;
vector<vector<int>> dp;

void generateDP() {
    generatePalindromes(n);
    m = palindromes.size();

    dp = vector<vector<int>> (n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; j++) dp[0][j] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i - palindromes[j] >= 0) dp[i][j] += dp[i - palindromes[j]][j];
            dp[i][j] %= mod;
        }
    }
}

void solve() {
    int a; cin >> a;
    // for (int j = 0; j <= 40; j++) {
    //     cerr << palindromes[j] << "\t";
    //     for (int i = 0; i <= a; i++) {
    //         cerr << dp[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    // for (int j = 0; j <= m; j++) {
    //     if (dp[a][j] != 7) cerr << j << endl;
    // }

    cout << dp[a][m - 1] << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    palindromes.push_back(0);
    generateDP();

	int t = 1;
	cin >> t;
	while ( t-- ) {
		solve();
	}
}

