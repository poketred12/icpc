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
using namespace std;
typedef long long ll; 

const int INF = 987654321;
int prerequsitie[12];
int classes[10]; // i번쨰 학기에 개설되는 과목의 집합
int cache[10][1 << 12];
int bitCount(int x) {
	if (x == 0) return 0;
	return x % 2 + bitCount(x / 2);
}
int n, k;
int m, l;
int graduate(int semester, int taken) { 
	//cout << "taken =" << taken << endl;
	if (bitCount(taken) >= k) return 0;
	//cout << "count = " << __popcnt(taken) << endl;
	if (semester == m) return INF;
	int& ret = cache[semester][taken];
	if (ret != -1) return ret;
	ret = INF;
	int canTake = (classes[semester] & ~taken);
	for (int i = 0; i < n; i++) {
		if ((canTake & (1 << i)) && (taken & prerequsitie[i]) != prerequsitie[i])
		{
			canTake &= ~(1 << i);
		}
	}
	//cout << "canTake = " << canTake << endl;
	for (int take = canTake; take > 0; take = ((take - 1) & canTake)) {
		//cout << "take count = " << __popcnt(take) << endl;
		if (bitCount(take) > l) continue;
		//cout << "take = " << take << endl;
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	ret = min(ret, graduate(semester + 1, taken));
	//cout << "ret = " << ret << endl;
	return ret;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);  
	int tc; cin >> tc;
	while (tc--) {
		cin >> n >> k;
		cin >> m >> l; 
		for(int j=0; j<10; j++)
			for (int i = 0; i < (1 << 12); i++) {
				cache[j][i] = -1;
			}

		for (int i = 0; i < 12; i++) {
			prerequsitie[i] = 0;
		}
		for (int i = 0; i < 10; i++) {
			classes[i] = 0;
		}
		/*initailize!!!*/

		for (int i = 0; i < n; i++) {
			int cnt; cin >> cnt; 
			for (int count = 0; count < cnt; count++) {
				int num; cin >> num; 
				prerequsitie[i] |= (1 << num);
			}
		}
		for (int i = 0; i < m; i++) {
			int cnt; cin >> cnt; 
			for (int count = 0; count < cnt; count++) {
				int num; cin >> num; 
				classes[i] |= (1 << num);
			}
		}
		int ans = graduate(0, 0);
		if (ans == INF) cout << "IMPOSSIBLE" << "\n";
		else cout << ans << "\n";
	}
}