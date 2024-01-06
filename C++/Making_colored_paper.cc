#include <iostream>
using namespace std;

void solve(int y, int x, int z);
int paper[128][128], blue = 0, white = 0;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];

	solve(0, 0, n);
	cout << white << '\n' << blue;

	return 0;
}

void solve(int y, int x, int z) {
	int current = paper[y][x];
	bool cut = false;

	for (int i = y; i < y + z; i++) {
		for (int j = x; j < x + z; j++) {
			if (current != paper[i][j]) {
				cut = true;
				break;
			}
		}
	}

	if (cut) {
		solve(y, x, z / 2); // 왼쪽 상단
		solve(y, x + z / 2, z / 2); // 오른쪽 상단
		solve(y + z / 2, x, z / 2); // 왼쪽 하단
		solve(y + z / 2, x + z / 2, z / 2); // 오른쪽 하단
	}
	else {
		if (current == 1)
			blue++;
		else
			white++;
	}
}