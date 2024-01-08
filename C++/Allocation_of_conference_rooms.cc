#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, start, end, t, cnt = 1;
	vector<pair<int, int>> schedule;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		schedule.push_back({ end, start });
	}

	sort(schedule.begin(), schedule.end());

	t = schedule[0].first;

	for (int i = 1; i < N; i++) {
		if (t <= schedule[i].second) {
			t = schedule[i].first;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}