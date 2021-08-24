#include <iostream>
using namespace std;

int get_cnt(int k, int n) {
    if(k == 0)
        return n;
    else if(n == 1)
        return 1;
    return get_cnt(k-1, n) + get_cnt(k, n-1);
}

int main() {
    int T, K, N;
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        cin >> K >> N;
        cout << get_cnt(K, N) << '\n';
    }

    return 0;
}