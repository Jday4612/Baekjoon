#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, P[1000], time = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> P[i];

	sort(P, P + N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++)
			time += P[j];
	}

	cout << time;

	return 0;
}