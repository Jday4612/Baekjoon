#include <iostream>
using namespace std;

int main() {
    int n, tmp, min = 1000000, max = -1000000;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        if(min > tmp)
            min = tmp;
        if(max < tmp)
            max = tmp;
    }
    cout << min << " " << max;
}