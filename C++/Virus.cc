#include <iostream>
#include <vector>
using namespace std;

int computer[101] = { 0 }, cnt = -1;
vector<int> adj[101];

void dfs(int x);

int main() {
	int N, M, a, b;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);
	cout << cnt;

	return 0;
}

void dfs(int x) {
	cnt++;
	computer[x] = 1;

	for (int i : adj[x]) {
		if (computer[i] == 0)
			dfs(i);
	}
}