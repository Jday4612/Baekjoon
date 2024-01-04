#include <iostream>
using namespace std;

int tile[1001] = { 0, 1, 2, };
void solve(int x);

int main() {
	int n;
	cin >> n;

	solve(n);
	cout << tile[n];

	return 0;
}

void solve(int x) {
	for (int i = 3; i <= x; i++)
		tile[i] = (tile[i - 1] + tile[i - 2]) % 10007;
}