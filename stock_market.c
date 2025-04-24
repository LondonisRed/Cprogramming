#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if (n <= 3) {
        printf("0\n");
        return 0;
    }
    
    float *prices = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        scanf("%f", &prices[i]);
    }
    
    float max_profit = 0;
    float buy_price = prices[0];
    float sell_price = prices[2]; 
    
    
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 2; j < n; j++) {
            float profit = prices[j] - prices[i];
            if (profit > max_profit) {
                max_profit = profit;
                buy_price = prices[i];
                sell_price = prices[j];
            }
        }
    }
    
    printf("%.2f %.2f\n", buy_price, sell_price);
    
    free(prices);
    return 0;
}