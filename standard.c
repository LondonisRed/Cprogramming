#include <stdio.h>

int main() {
    int n;
    float min_weight, max_weight;
    scanf("%d %f %f", &n, &min_weight, &max_weight);
    
    int qualified = 0, unqualified = 0;
    float weight;
    
    for (int i = 0; i < n; i++) {
        scanf("%f", &weight);
        if (weight >= min_weight && weight <= max_weight) {
            qualified++;
        } else {
            unqualified++;
        }
    }
    
    printf("%d %d ", qualified, unqualified);
    
    if (unqualified * 100 <= n * 5) {
        printf("OK\n");
    } else {
        printf("FAIL\n");
    }
    
    return 0;
}