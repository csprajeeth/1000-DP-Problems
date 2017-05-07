// http://www.spoj.com/problems/ACODE/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef long long int int64;
typedef unsigned long long int uint64;

#define rep(i, n) for(int i=0; i<(int)n; i++)
#define all(X) (X).begin(),(X).end()


int solve(string s) {
	int n = s.size();
	vi dp(n+1, 0);
	dp[n-1] = (s[n-1] != '0');
	dp[n] = 1;
	for(int i=n-2; i>=0; i--) {
		if(s[i] != '0') {
			dp[i] = dp[i+1];
			int a = 10*(s[i]-'0') + (s[i+1] - '0');
			if (a >=1 && a <=26) {
				dp[i] += dp[i+2];
			}
		}
	}
	return dp[0];
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	string s;
	while(cin >> s) {
		if (s == "0")
			break;
		cout << solve(s) << endl;
	}
	return 0;
}
