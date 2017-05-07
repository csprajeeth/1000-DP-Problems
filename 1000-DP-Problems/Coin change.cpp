// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=615
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
vector<vector<uint64> > dp(5, vector<uint64>(8000, 0));
vi denom = {1, 5, 10, 25, 50};
unsigned long long int solve(int n) {
	rep(i, n+1)
		dp[0][i] = 1; // 1 cent denomination
	rep(i, 5)
		dp[i][0] = 1;

	for (int i=1; i<5; i++) {
		for (int j=1; j<=n; j++) {
			if (denom[i] > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j] + dp[i][j-denom[i]];
		}
	}
	return dp[4][n];
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	int n;
	solve(7489);
	while(cin >> n) {
		cout << dp[4][n] << endl;
	}
	return 0;
}
