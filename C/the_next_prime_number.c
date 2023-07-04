#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    long long n, x, t, z, ans;
    
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &x);

        t = x < 3 ? 0 : 1;
        ans = x < 3 ? 2 : x;
        
        while (t) {
            z = sqrt(x) + 1;
            for (long long j = 2; j <= z; j++) {
                if (x % j == 0) {
                    break;
                }

                if (j == z) {
                    ans = x;
                    t = 0;
                }
            }
            x++;
        }

        printf("%lld\n", ans);
    }

    return 0;
}