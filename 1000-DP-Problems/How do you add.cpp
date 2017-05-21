// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1884
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned long long int uint64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()
#define MOD 1000000

vvi DP(110, vi(110, 0));

void solve() {
	for(int i=0; i<=100; i++) {
		DP[1][i] = 1;
	}
	for(int i=2; i<=100; i++) {
		for(int j=0; j<=100; j++) {
			for(int k=0; k<=j; k++) {
				DP[i][j] += DP[i-1][j-k];
				DP[i][j] %= MOD;
			}
		}
	}
}
int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int n, k;
	solve();
	while(cin >> n >> k) {
		if(n==0 && k==0)
			break;
		cout << DP[k][n] << "\n";
	}
	return 0;
}
