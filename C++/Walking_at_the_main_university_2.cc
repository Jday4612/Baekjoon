#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b);
long long D;
const vector<vector<long long>> path = {
    { 0, 1, 1, 0, 0, 0, 0, 0 },
    { 1, 0, 1, 1, 0, 0, 0, 0 },
    { 1, 1, 0, 1, 1, 0, 0, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 0 },
    { 0, 0, 1, 1, 0, 1, 0, 1 },
    { 0, 0, 0, 1, 1, 0, 1, 0 },
    { 0, 0, 0, 0, 0, 1, 0, 1 },
    { 0, 0, 0, 0, 1, 0, 1, 0 }
}; // 정보과학관, 전산관, 미래관, 신양관, 한경직기념관, 진리관, 학생회관, 형남공학관

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<vector<long long>> ans(8, vector<long long>(8));
    vector<vector<long long>> factor = path;

    cin >> D;

    for (int i = 0; i < 8; i++)
        ans[i][i] = 1; // 단위 행렬

    while (D) {
        if (D & 1) { // 홀수, 1분 남았을 때는 무조건 실행
            ans = multiply(ans, factor);
            D--;
        }

        factor = multiply(factor, factor);
        D /= 2;
    }

    cout << ans[0][0];

    return 0;
}

vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> v(8, vector<long long>(8));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            long long tmp = 0;

            for (int k = 0; k < 8; k++) {
                tmp += a[i][k] * b[k][j];
                tmp %= 1000000007;
            }

            v[i][j] = tmp % 1000000007;
        }
    }

    return v;
}