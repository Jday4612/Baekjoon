#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	string site, pwd;
	map<string, string> site_list;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> site >> pwd;
		site_list[site] = pwd;
	}

	for (int i = 0; i < M; i++) {
		cin >> site;
		cout << site_list[site] << "\n";
	}

	return 0;
}