#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if (n <= 1) {
        printf("0\n");
        return 0;
    }
    
    double prices[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &prices[i]);
    }
    
    int up_days = 0, down_days = 0;
    
    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i-1]) {
            up_days++;
        } else if (prices[i] < prices[i-1]) {
            down_days++;
        }
    }
    
    double threshold = (n - 1) * 2.0 / 3.0;
    
    if (up_days > threshold) {
        printf("1\n");
    } else if (down_days > threshold) {
        printf("-1\n");
    } else {
        printf("0\n");
    }
    
    return 0;
}