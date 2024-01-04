#include <iostream>
using namespace std;

int main() {
	int T, n;
	long long P[101] = { 0, 1, 1, 1, 2, 2, };

	for (int i = 6; i < 101; i++)
		P[i] = P[i - 1] + P[i - 5];

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << P[n] << "\n";
	}

	return 0;
}