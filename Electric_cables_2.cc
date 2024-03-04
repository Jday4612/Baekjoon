#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;
vector<int> idx, ans, num;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, z;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
    }

    sort(v.begin(), v.end());

    ans.push_back(v.front().second);
    idx.push_back(0);

    for (int i = 1; i < v.size(); i++) {
        int next = v[i].second;

        if (ans.back() < next) { // 교차 X
            ans.push_back(next);
            idx.push_back(ans.size() - 1);
        }
        else {
            int left = 0, right = ans.size() - 1;

            while (left < right) {
                int mid = (left + right) / 2;

                if (ans[mid] < next) // 교차 X
                    left = mid + 1;
                else
                    right = mid;
            }

            ans[left] = next;
            idx.push_back(left);
        }
    }

    cout << v.size() - ans.size() << "\n";

    z = ans.size() - 1;

    for (int i = idx.size() - 1; 0 <= i; i--) {
        if (z == idx[i])
            z--;
        else
            num.push_back(v[i].first);
    }

    sort(num.begin(), num.end());

    for (int j = 0; j < num.size(); j++)
        cout << num[j] << "\n";

    return 0;
}