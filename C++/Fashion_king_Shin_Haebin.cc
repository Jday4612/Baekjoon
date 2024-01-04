#include <iostream>
#include <map>
using namespace std;

int main() {
	int T, n;
	long long cnt;
	string a, b;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;

		map<string, int> m;
		for (int j = 0; j < n; j++) {
			cin >> a >> b;
			m[b]++;
		}

		cnt = 1;

		for (auto k : m)
			cnt *= k.second + 1;

		cout << cnt - 1 << "\n";
	}

	return 0;
}