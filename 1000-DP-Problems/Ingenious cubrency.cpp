// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2078
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

vi denom;
vector<vector<uint64> > dp(21, vector<uint64>(11000, 0));

void solve(int n) {
	for(int i=0; i<=n; i++)
		dp[0][i] = 1; // 1 cent;
	for(int i=0; i<21; i++)
		dp[i][0] = 1; // # of ways to make 0
	for(int i=1; i<=20; i++) {
		for(int j=1; j<=n; j++) {
			dp[i][j] = dp[i-1][j];
			if (denom[i] <= j) {
				dp[i][j] += dp[i][j-denom[i]];
			}
		}
	}
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	for (int i=1; i<=21; i++) {
		denom.push_back(i*i*i);
	}
	solve(10000);
	int n;
	while(cin >> n) {
		cout << dp[20][n] << endl;
	}
	return 0;
}
