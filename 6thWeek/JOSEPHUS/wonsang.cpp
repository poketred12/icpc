#include<iostream>
#include<vector>

using namespace std;

int C;

int main() {
	cin >> C;

	int N, K;

	for (int i = 0; i < C; i++) {
		cin >> N >> K;

		vector<int> survive;

		for (int j = 0; j < N; j++) {
			survive.push_back(j + 1);
		}

		int size = N, index = 0;

		for (int j = 0; j < N - 2; j++) {
			survive.erase(survive.begin() + index);

			size--;

			index += K - 1;

			if (index >= size) {
				index %= size;
			}
		}

		cout << survive.at(0) << " " << survive.at(1) << endl;
	}

	return 0;
}