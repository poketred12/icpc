#include<iostream>
#include<deque>
#include<string>

using namespace std;

int C;

int main() {
	cin >> C;

	for (int i = 0; i < C; i++) {
		deque<char> bracket;
		string input;
		bool flag = true;

		cin >> input;
		
		if (input.length() % 2 != 0)
			flag = false;

		for (int i = 0; i < input.length() && flag; i++) {
			if (input.at(i) == '(')
				bracket.push_back(')');
			else if (input.at(i) == '{')
				bracket.push_back('}');
			else if (input.at(i) == '[')
				bracket.push_back(']');
			else {
				if (bracket.empty()) {
					flag = false;
					break;
				}
					
				if (bracket.back() != input.at(i)) 
					flag = false;
				else
					bracket.pop_back();
			}
		}
		
		if (flag && bracket.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}