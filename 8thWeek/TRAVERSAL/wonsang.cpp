#include<iostream>
#include<vector>

using namespace std;

int C, N;

void InsertPostOrder(vector<int> &preOrder, vector<int> &midOrder, vector<int> &postOrder, int minIndex, int maxIndex, int &preIndex) {
	if (minIndex > N - 1 || maxIndex < 0 || minIndex > maxIndex)
		return;

	int rootIndex;
		
	for (int i = minIndex; i <= maxIndex; i++) {
		if (preOrder[preIndex] == midOrder[i]) {
			preIndex++;
			rootIndex = i;
			break;
		}
	}

	InsertPostOrder(preOrder, midOrder, postOrder, minIndex, rootIndex - 1, preIndex);
	InsertPostOrder(preOrder, midOrder, postOrder, rootIndex + 1, maxIndex, preIndex);

	postOrder.push_back(midOrder[rootIndex]);
}

int main() {
	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> N;
		vector<int> preOrder(N, 0);
		vector<int> midOrder(N, 0);
		vector<int> postOrder;
		int midRoot, preIndex = 0;

		for (int j = 0; j < N; j++) {
			cin >> preOrder[j];
		}

		for (int j = 0; j < N; j++) {
			cin >> midOrder[j];

			if (midOrder[j] == preOrder[0])
				midRoot = j;
		}

		InsertPostOrder(preOrder, midOrder, postOrder, 0, N - 1, preIndex);

		for (int j = 0; j < postOrder.size(); j++) {
			cout << postOrder[j] << " ";
		}
		cout << endl;
	}

	return 0;
}