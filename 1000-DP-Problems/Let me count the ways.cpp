// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=293
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned long long int uint64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()

vi v = {1, 5, 10, 25, 50};
vector<vector<uint64> > DP(5, vector<uint64>(30010, 0));

void solve() {
	int n = 5;
	int m = 30000;
	rep(i, n)
		DP[i][0] = 1;
	rep(i, m+1) {
		DP[0][i] = 1;
	}
	for(int i=1; i<n; i++) {
		for(int j=1; j<=m; j++) {
			DP[i][j] = DP[i-1][j];
			if (j-v[i] >= 0) {
				DP[i][j] += DP[i][j-v[i]];
			}
		}
	}
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int n;
	solve();
	while(cin >> n) {
		uint64 ans = DP[4][n];
		if (ans == 1) {
			cout << "There is only 1 way to produce " << n << " cents change.\n";
		} else {
			cout << "There are " << ans << " ways to produce " << n << " cents change.\n";
		}
	}
	return 0;
}
