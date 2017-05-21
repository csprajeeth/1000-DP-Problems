// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1406
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int int64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()

struct Choice {
	int beers, burgers;

	Choice(int a, int b) {
		beers = a; burgers = b ;
	}

	bool operator<(const Choice rhs) const {
		if (this->beers == rhs.beers)
			return this->burgers > rhs.burgers;
		return this->beers < rhs.beers;
	}
};
vvi beers, burgers;
void solve(int n, int m, int t) {
	vi v = {n, m};
	beers[0][0] = beers[1][0] = burgers[0][0] = burgers[1][0] = 0;
	for(int i=0; i<2; i++) {
		for(int j=1; j<=t; j++) {
			// Drink beer
			Choice c = Choice(1+beers[i][j-1], burgers[i][j-1]);

			// Exclude this type of burger
			if (i-1>=0) {
				c = min(c, Choice(beers[i-1][j], burgers[i-1][j]));
			}

			// Include atleast 1 of this type of burger
			if (j-v[i]>=0) {
				c = min(c, Choice(beers[i][j-v[i]], 1+burgers[i][j-v[i]]));
			}
			beers[i][j] = c.beers;
			burgers[i][j] = c.burgers;
		}
	}
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int n, m, t;
	beers = vvi(2, vi(10001, 0)); // beers drunk
	burgers = vvi(2, vi(10001, 0)); // burgers eaten

	while(cin >> n >> m >> t) {
		if (n > m)
			swap(n, m);
		solve(n, m, t);
		cout << burgers[1][t];
		if (beers[1][t] > 0)
			cout << " " << beers[1][t];
		cout << "\n";
	}
	return 0;
}
