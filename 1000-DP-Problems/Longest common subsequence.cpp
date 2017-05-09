// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1346
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


int solve(const string &a, const string &b) {
	int n = a.size(), m = b.size();
	vvi dp(n+1, vi(m+1, 0));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(a[i-1] == b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n][m];
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	bool f = false;
	while(!cin.eof()) {
		if (f) cout << endl;
		string a, b;
		getline(cin, a);
		getline(cin, b);
		cout << solve(a, b);
		f = true;
	}
	return 0;
}
