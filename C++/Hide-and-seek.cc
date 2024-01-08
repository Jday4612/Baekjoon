#include <iostream>
#include <queue>
using namespace std;

void solve(int x);
int visited[100001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	queue<pair<int, int>> q;

	cin >> N >> K;

	visited[N] = 1;
	q.push({ N, 0 });

	while (!q.empty()) {
		int current = q.front().first;
		int time = q.front().second;

		q.pop();

		if (current == K) {
			cout << time;
			break;
		}
		
		int a = current - 1, b = current + 1, c = current * 2;

		if (0 <= a && a < 100001 && visited[a] == 0) {
			visited[a] = 1;
			q.push({ a, time + 1 });
		}

		if (0 <= b && b < 100001 && visited[b] == 0) {
			visited[b] = 1;
			q.push({ b, time + 1 });
		}

		if (0 <= c && c < 100001 && visited[c] == 0) {
			visited[c] = 1;
			q.push({ c, time + 1 });
		}
	}

	return 0;
}