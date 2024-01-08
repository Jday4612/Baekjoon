#include <iostream>
#include <queue>
using namespace std;

void bfs(int x, int y);
int n, m, map[1001][1001] = {0}, visited[1001][1001] = {0};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				x = i;
				y = j;
			}
		}
	
	bfs(x, y);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
				cout << "0 ";
			else
				cout << visited[i][j] - 1 << " ";
		}

		cout << "\n";
	}

	return 0;
}

void bfs(int x, int y) {
	int direct_x[4] = { 0, 0, 1, -1 };
	int direct_y[4] = { -1, 1, 0, 0 };
	queue<pair<int, int>> q;

	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int front_x = q.front().first, front_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int current_x = front_x + direct_x[i], current_y = front_y + direct_y[i];

			if (0 <= current_x && current_x < n && 0 <= current_y && current_y < m && visited[current_x][current_y] == 0 && map[current_x][current_y] != 0) {
				visited[current_x][current_y] = visited[front_x][front_y] + 1;
				q.push({ current_x, current_y });
			}
		}
	}
}