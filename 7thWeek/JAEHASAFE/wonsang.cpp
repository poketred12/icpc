#include<iostream>
#include<string>
#include<vector>

using namespace std;

int C, N;

string GetMinToken(string &current) {
	string result;

	for (int i = 2; i <= current.length() / 2 + 1; i++) {
		result = current.substr(0, i);

		int find = current.find(result, 1);

		if (find < 0)
			break;
	}

	return result;
}

//RTE (SIGKILL: program was forcefully killed, probably memory limit exceeded)
//참조자를 이용해서 문제해결

bool Check(string &code, string &token, int pos, int index) {
	
	if (index == token.length())
		return true;

	if (pos == code.length())
		pos = 0;

	if (code.at(pos) == token.at(index))
		return Check(code, token, pos + 1, index + 1);

	return false;
}

int main() {
	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> N;

		string current;
		int pos = 0, answer = 0;
		bool flag = true;
		vector<string> code;
		
		cin >> current;

		string token = GetMinToken(current);

		for (int i = 0; i < N; i++) {
			string buffer;
			cin >> buffer;
			code.push_back(buffer);
		}

		for (int i = 0; i < code.size(); i++) {
			int find = code[i].find(token);

			if (find < 0) {
				for (int j = code[i].length() - 1; token.length() > code[i].length() - j; j--) {
					if (Check(code[i], token, j, 0)) {
						find = j;
						break;
					}
				}
			}

			if (flag) {
				if (find > pos)
					answer += find - pos;
				else
					answer += code[i].length() - pos + find;
			}
			else {
				if (find < pos)
					answer += pos - find;
				else
					answer += code[i].length() - find + pos;
			}

			pos = find;
			flag = !flag;
		}

		cout << answer << endl;
	}
	
	return 0;
}