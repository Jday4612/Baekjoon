#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M, i, j, num[100001] = {0}, tmp;

	cin >> N >> M;
	for (int a = 1; a <= N; a++) {
		cin >> tmp;
		num[a] = num[a - 1] + tmp;
	}

	for (int a = 0; a < M; a++) {
		cin >> i >> j;
		cout << num[j] - num[i - 1] << "\n";
	}

	return 0;
}