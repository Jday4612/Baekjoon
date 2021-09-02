#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int start, int stop, int end, int k) {
    if(k > 0) {
        hanoi(start, end, stop, k-1);
        cout << start << ' ' << end << '\n';
        hanoi(stop, start, end, k-1);
    }
}

int main() {
    int k;
    cin >> k;
    cout << (int)pow(2, k) - 1 << '\n';
    
    hanoi(1, 2, 3, k);
    
    return 0;
}