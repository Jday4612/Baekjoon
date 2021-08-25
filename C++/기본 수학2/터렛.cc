#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t, x[2], y[2], r[2];
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1];
    
        double d = sqrt(pow(x[1] - x[0], 2) + pow(y[1] - y[0],2));
		int r_1 = abs(r[1] - r[0]);
		int r_2 = r[1] + r[0];

		if(d == 0) {
			if(r[1] == r[0])
			    cout << -1 << '\n';
			else
			    cout << 0 << '\n';
		}
		else {
			if(d == r_1 || d == r_2)
			    cout << 1 << '\n';
			else if(r_1 < d && d < r_2)
    			cout << 2 << '\n';
			else
			    cout << 0 << '\n';
		}
    }
    
    return 0;
}