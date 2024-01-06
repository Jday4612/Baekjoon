#include <iostream>
#include <vector>
using namespace std;

void solve(int x);
int visited[1001] = { 0 };
vector<int> adj[1001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, u, v, cnt = 0;
	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int j = 1; j <= N; j++) {
		if (visited[j] == 0) {
			cnt++;
			solve(j);
		}
	}

	cout << cnt;

	return 0;
}

void solve(int x) {
	visited[x] = 1;
	int idx;

	for (int i = 0; i < adj[x].size(); i++) {
		idx = adj[x][i];

		if (visited[idx] == 0)
			solve(idx);
	}
}