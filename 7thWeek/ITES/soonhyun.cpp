#include <iostream> 
#include <vector>
#include <algorithm>
#include <queue> 

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
		preva = 1983; // A[i-1]
		ll MOD = 1LL << 32;
		ll ans = 0;
		ll total = 0;

		for (int i = 1; i <= n; i++) {
			cura = (preva * 214013 + 2531011) % MOD; // A[i]
			signal = preva % 10000 + 1; //현재 신호를 담고있는 변수 
			preva = cura; 

			if (signal > k) { 
				/*
				*
				*   만약 signal이 k보다 크다면 큐안에 있는 값들 사용하지 못함
				*   신호가 1 4 8 3 2 8 1 1 1 3 8 4 3 8이고, K가 7일 때
				*   1 4 8(끊기고) 3 2 8(끊기고) 1 1 1 3 8(끊기고) 4 3(ans++) 8(끊기고)
				*
				*/
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

			/*
			*  signal값을 queue에 넣어주면서 k값이 될 수 있는지 확인
			*  총합이 k보다 크냐, 작냐를 확인해주면 됨
			*/
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
		}
		cout << ans << "\n";
		while (!q.empty()) q.pop();
		
	}
}
