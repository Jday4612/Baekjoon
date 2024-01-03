#include <iostream>
using namespace std;

int main() {
	int N, stairs[300], dp[300];

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> stairs[i];

	dp[0] = stairs[0];
	dp[1] = max(stairs[1], stairs[0] + stairs[1]);
	dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (int i = 3; i < N; i++) {
		dp[i] = max(stairs[i] + dp[i - 2], stairs[i] + stairs[i - 1] + dp[i - 3]);
	}
    
    cout << dp[N - 1];

	return 0;
}