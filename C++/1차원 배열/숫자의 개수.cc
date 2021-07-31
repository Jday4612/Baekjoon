#include <iostream>
using namespace std;

int main() {
    int a, b, c, ans;
    cin >> a >> b >> c;
    ans = a * b * c;
    
    int z[10] = {0};
    while(ans != 0) {
        int tmp = ans % 10;
        z[tmp]++;
        ans /= 10;
    }
    
    for(int i = 0; i < 10; i++)
        cout << z[i] << '\n';
}