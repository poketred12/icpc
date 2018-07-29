#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll dp[40001];
class sushi {
public:
	ll cost;
	ll prefer;
	sushi() {}
	bool operator<(const sushi &other) {
		return cost < other.cost;
	}
}S[22];
int main() {
	int t; cin >> t;
	while (t--) {
		ll n, m; cin >> n >> m;
		ll di;
		ll ans = 0;

		for (int i = 0; i <= 10000; i++) {
			dp[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			ll c; cin >> c >> S[i].prefer;
			//di = min(c, di);
			S[i].cost = c / 100;
		}
		sort(S, S + n);
		if (n >= 2) {
			di = S[n - 1].cost * S[n - 2].cost;
		}
		else
			di = S[n - 1].cost;
		for (int i = 0; i < n; i++) {
			dp[S[i].cost] = max(dp[S[i].cost], S[i].prefer);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= 10000; j++) {
				if (j - S[i].cost >= 0) {
					dp[j] = max(dp[j], dp[j - S[i].cost] + dp[S[i].cost]);
				}
			}
		} 
		m /= 100;
		ll maxs[10001];
		ll maxss = 0;
		for (int i = 0; i <= 10000; i++) {
			maxss = max(maxss, dp[i]);
			maxs[i] = maxss;
		}
		for (int i = 1; i <= 10000; i++) {
			ll div = m / i;
			int mod = m%i;
			ll value = div*dp[i] + maxs[mod];
			ans = max(ans, value);
		}
		cout << ans << "\n";
	}
}