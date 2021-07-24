#include <iostream>
using namespace std;

bool check[10001];
int get_num(int n) {
    int tmp = n + n / 1000 + n % 1000 / 100 + n % 100 / 10 + n % 10;
    return tmp;
}

void selfnum() {
	int tmp;
    
	for(int i = 0; i < 10000; i++) {
		if(i < 10000) {
			tmp = get_num(i);
            
			if(tmp < 10000)
				check[tmp] = true;
		}
	}
}

int main() {
    check[1] = false;
    selfnum();
    
	for(int i = 1; i < 10000; i++)
		if(!check[i])
			cout << i << '\n';
}