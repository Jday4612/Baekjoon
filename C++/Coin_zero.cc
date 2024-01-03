#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K, tmp, cnt = 0;
	vector<int> A;

	cin >> N;
	A.resize(N);

	cin >> K;
	for (int& i : A)
		cin >> i;

	for (int i = N - 1; 0 <= i; i--) {
		tmp = K / A[i];
		cnt += tmp;

		K -= tmp * A[i];
		if (K == 0)
			break;
	}

	cout << cnt;

	return 0;
}