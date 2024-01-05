#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, x;
	priority_queue<int, vector<int>, greater<int>> heap;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x > 0)
			heap.push(x);
		else {
			if (heap.size()) {
				cout << heap.top() << '\n';
				heap.pop();
			}
			else {
				cout << 0 << '\n';
			}
		}
	}

	return 0;
}