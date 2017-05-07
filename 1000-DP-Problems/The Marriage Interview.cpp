// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1387
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

vector<vector<uint64> > dp(70, vector<uint64>(70, 1));

void solve() {
	for(int i=0; i<=60; i++) {
		dp[0][i] = dp[1][i] = 1;
	}
	for(int n=2; n<=60; n++) {
		for(int b=0; b<=60; b++) {
			for(int k=1; k<=b; k++) {
				if (n-k < 0)
					dp[n][b]++;
				else
					dp[n][b] += dp[n-k][b];
			}
		}
	}
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	solve();
	int a, b;
	int Case = 1;
	while(cin >> a >> b) {
		if (a > 60)
			break;
		cout << "Case " << Case++ <<": ";
		if (a < 0 || b < 0)
			cout << 1 << endl;
		else
			cout << dp[a][b] << endl;
	}
	return 0;
}
