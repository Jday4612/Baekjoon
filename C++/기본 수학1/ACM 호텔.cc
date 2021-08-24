#include <iostream>
using namespace std;

int main() {
    int T, H, W, N, cnt = 1;
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        cin >> H >> W >> N;
        if(N % H == 0)
            cout << H * 100 + N / H << '\n';
        else
            cout << (N % H) * 100 + N / H + 1 << '\n';
    }

    return 0;
}