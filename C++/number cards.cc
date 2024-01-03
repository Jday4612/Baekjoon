#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M, a[500000], b[500000], left, right, mid, check;
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	sort(a, a + N);

	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> b[i];

	for (int i = 0; i < M; i++) {
		left = 0;
		right = N - 1;
		check = 0;

		while (left <= right) {
			mid = (left + right) / 2;

			if (a[mid] == b[i]) {
				check = 1;
				break;
			}
			else if (a[mid] < b[i])
				left = mid + 1;
			else
				right = mid - 1;
		}

		if (check)
			cout << "1 ";
		else
			cout << "0 ";
	}

	return 0;
}