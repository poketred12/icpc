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

using namespace std;
typedef long long ll; 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);  
	int tc; cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k; 
		deque<int> dq;
		for (int i = 1; i <= n; i++) {
			dq.push_back(i);
		}

		while (dq.size() != 2) {
			dq.pop_front(); 

			for (int i = 0; i < k - 1; i++) {
				int tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
			}
		}

		sort(dq.begin(), dq.end());
		for (auto print : dq) {
			cout << print << " ";
		}
		cout << "\n";
	}
}