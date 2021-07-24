#include <iostream>
using namespace std;

int main(){
    int a, b;
    int y1, y2, y3;
    cin >> a >> b;
    y1 = b % 10;
    y2 = b / 10 % 10;
    y3 = b / 100;
    
    cout << a * y1 << endl << a * y2 << endl << a * y3 << endl << a * b;
}