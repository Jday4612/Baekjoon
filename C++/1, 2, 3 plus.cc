#include <iostream>
using namespace std;

int cnt = 0;

void add(int x);

int main() {
	int T, n;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cnt = 0;

		add(n);
		cout << cnt << "\n";
	}

	return 0;
}

void add(int x) {
	if (0 == x)
		cnt++;
	else {
		if (0 <= x - 3)
			add(x - 3);

		if (0 <= x - 2)
			add(x - 2);

		if (0 <= x - 1)
			add(x - 1);
	}
}