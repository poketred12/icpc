#include <string>
#include <iostream>
#include <vector> 
#include <stack>

using namespace std;
typedef long long ll; 

stack<char> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);  
	int tc; cin >> tc;
	while (tc--) {
		string str;
		cin >> str;

		while (!st.empty()) { 
			st.pop();
		}
		int flag = 1;
		int super = 1;
		for (int i = 0; i < str.size(); i++) {
			if (str.at(i) == ')' || str.at(i) == '}' || str.at(i) == ']') {
				if (st.empty()) {
					flag = -1;
					super = -1;
					cout << "NO";
					break;
				}
				else {
					if (abs(str.at(i) - st.top()) <= 2) {
						st.pop();
					}
					else {
						flag = -1;
						super = -1;
						cout << "NO";
						break;
					}
				}
			}
			else {
				st.push(str.at(i));
			} 
		}  

		if (super == 1) {
			if (st.size() == 0 && flag == 1) {
				cout << "YES";
			}
			else {
				cout << "NO";
			}
		}
		cout << "\n";
	}
}
