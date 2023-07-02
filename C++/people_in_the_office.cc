#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	set<string> nameList;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string name, state;
		cin >> name >> state;

		if (state == "enter") {
			nameList.insert(name);
		}
		else {
			nameList.erase(name);
		}
	}

	for (auto iter = nameList.rbegin(); iter != nameList.rend(); iter++) {
		cout << *iter << "\n";
	}

	return 0;
}