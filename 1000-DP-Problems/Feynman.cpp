// http://www.spoj.com/problems/SAMER08F/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned long long int uint64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()
#define MOD 1000000

vi DP(100, 0);
void solve() {
	DP[1] = 1;
	for(int i=2; i<=100; i++) {
		DP[i] += DP[i-1] + i*i;
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
		if(n == 0) {
			break;
		}
		cout << DP[n] << "\n";
	}
	return 0;
}
