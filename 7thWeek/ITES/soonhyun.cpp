#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <math.h>
#include <deque>
#include <stack>

using namespace std;
typedef long long ll; 

ll cura, preva;
ll signal; 
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);  
	int tc; cin >> tc;
	while (tc--) {
		int k, n;  cin >> k >> n;
		preva = 1983; 
		ll MOD = 1LL << 32;
		ll ans = 0;
		ll total = 0;
		for (int i = 1; i <= n; i++) {
			cura = (preva * 214013 + 2531011) % MOD;
			signal = preva % 10000 + 1;
			preva = cura; 
			if (signal > k) {
				while (total >= k) {
					if (total == k) ans++;
					total -= q.front();
					q.pop();
				}
				while (!q.empty()) {
					q.pop();
				}
				total = 0;
			}
			/*if (total == k) {
				ans++;
				q.pop();
			} 
			else */
			if (total< k) {
				total += signal;
				q.push(signal);
				while (total >= k) {
					if (total == k) ans++;
					total -= q.front();
					q.pop();
				}
			}
			else if (total >= k) {
				while (total >= k) {
					if (total == k)ans++;
					total -= q.front();
					q.pop();
				} 
				total += signal;
				q.push(signal);
				while (total >= k) {
					if (total == k)ans++;
					total -= q.front();
					q.pop();
				}
			}
			//cout << "total = " << total << endl;
		}
		cout << ans << "\n";
		while (!q.empty()) q.pop();
		
	}
}
