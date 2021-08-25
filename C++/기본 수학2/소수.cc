#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, check = 0, min = 0, sum = 0;
    cin >> a >> b;
    
    for(int i = a; i <= b; i++) {
        for(int j = 1; j < i; j++) {
            if(i % j == 0)
                check++;
        }
        if(check == 1) {
            if(min == 0)
                min = i;
            sum += i;
        }
		check = 0;
    }
    
    if(sum == 0)
        cout << -1;
    else
        cout << sum << '\n' << min;
   
    return 0;
}