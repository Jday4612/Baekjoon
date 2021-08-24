#include <iostream>
#include <string>
using namespace std;

int sum[10001], carry = 0;
string str1, str2, tmp;

void get_num(string a, string b) {
    for(int i = a.length()-1; i >= 0; i--) {
        sum[a.length()-1-i] = (a[i] - '0') + (b[i] - '0') + carry;
        if(sum[a.length()-1-i] >= 10) {
            sum[a.length()-1-i] -= 10;
            carry = 1;
        }
        else
            carry = 0;
    }
    
    if(carry)
        cout << 1;
    for(int j = a.length()-1; j >= 0; j--)
        cout << sum[j];
}

int main() {
    cin >> str1 >> str2;
    
    if(str1.length() > str2.length()) {
        for(int i = 0; i < str1.length() - str2.length(); i++)
            tmp += '0';
        str2 = tmp + str2;
    }
    else if(str1.length() < str2.length()) {
        for(int i = 0; i < str2.length() - str1.length(); i++)
            tmp += '0';
        str1 = tmp + str1;
    }
    
    get_num(str1, str2);
    
    return 0;
}