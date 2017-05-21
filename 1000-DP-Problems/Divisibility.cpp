// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=977
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int int64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()

bool solve(vi &v, int K) {
	int n = v.size();

	vi prev(K, false), curr;
	prev[v[0]%K] = true;
	curr = prev;
	for(int i=1; i<n; i++) {
		fill(all(curr), false);
		v[i] %= K;
		for(int j=0; j<K; j++) {
			if(prev[j]) {
				int mod1 = (j+v[i]) % K;
				int mod2 = (j-v[i]+K) % K;
				curr[mod1] = curr[mod2] = true;
			}
		}
		prev = curr;
	}

	return curr[0];
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int N, K;
		cin >> N >> K;
		vi v;
		rep(i, N) {
			int a; cin >> a;
			a = abs(a);
			v.push_back(a);
		}
		if (solve(v, K)) {
			cout << "Divisible" << endl;
		} else {
			cout << "Not divisible" << endl;
		}
	}
	return 0;
}
