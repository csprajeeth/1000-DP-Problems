// http://www.spoj.com/problems/COINS/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int int64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()

unordered_map<int, int64> mp;

int64 solve(int n) {
	if (mp.find(n) != mp.end())
		return mp[n];

	int64 a = solve(n/2), b = solve(n/3), c = solve(n/4);
	int64 ans = n;
	ans = max(ans, a+b+c);
	mp[n] = ans;
	return ans;
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int n;
	mp[0] = 0;
	while(cin >> n) {
		cout << solve(n) << "\n";
	}
	return 0;
}
