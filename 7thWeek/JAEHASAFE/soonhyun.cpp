#include <iostream> 
#include <vector>
#include <algorithm>
#include <queue> 
#include <string>

using namespace std;
typedef long long ll; 

#define INF 98765432;
vector<int> getPi(string p) {
	int m = (int)p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) j = pi[j - 1];
		if (p[i] == p[j]) pi[i] = ++j;
	}
	return pi;
}
int kmp(string s, string p) {
	vector<int> ans;
	auto pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				return i - m + 1;
			}
			else {
				j++;
			}
		}
	}
	return INF;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);  
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		int ans = 0;
		int dir = 1; // clockwise, rotate counterclockwise 

		string prev , cur; 
		string str, pattern;  // kmp 
		cin >> prev;
		for (int i = 0; i < n; i++) {
			str = "";
			pattern = "";
			if (dir == 1) {
				cur = "";
				cin >> cur;
				// cur -> str;
				str = cur + cur;
				pattern = prev;
				ans += kmp(str, pattern);
				dir *= -1;
				prev = cur;
			}
			else {
				cur = "";
				cin >> cur;
				// prev -> str;
				str = prev + prev;
				pattern = cur;
				ans += kmp(str, pattern);
				dir *= -1;
				prev = cur;
			}
		}
		cout << ans << "\n";
		
	}
}
