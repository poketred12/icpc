/****
***** 시간초과
*****/


#include <iostream> 
#include <vector>
#include <algorithm>
#include <queue> 
#include <string>

using namespace std;
typedef long long ll; 
int n;

vector<int> getPi(string p) {
	int m = (int)p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) j = pi[j - 1];
		if (p[i] == p[j]) pi[i] = ++j;
	}
	return pi;
} 
vector<int> kmp(string s, string p) {
	vector<int> ans;
	auto pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);  
	int tc; cin >> tc;
	while (tc--) {
		cin >> n; 
		string str; cin >> str;
		int ans = 0;
		if (n == 1) {
			cout << str.size() << "\n";
			continue;
		}
		string pattern;

		for (int i = 0; i < str.size(); i++) {
			pattern = "";
			for (int j = i; j < str.size(); j++) {
				pattern += str.at(j);
			}

			string sub;
			int mc = 0;
			int index = 0;
			vector<int> matched = getPi(pattern);
			for (int idx = 0; idx < matched.size(); idx++) {
				if (mc < matched[idx]) {
					index = idx;
					mc = matched[idx];
				}
			}
			for (int j = 0; j < matched[index]; j++) {
				sub += pattern.at(j);
			} 
			vector<int> km = kmp(str, sub);
			if (km.size() >= n) {
				//cout << "is it true? : " << sub << endl;
				ans = max(ans, (int)sub.size());
			} 
		}
		cout << ans << "\n";
	}
}
