#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    double *prices = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &prices[i]);
    }
    
    int max_length = 1;
    int start_index = 0;
    int current_length = 1;
    int current_start = 0;
    
    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) {
            current_length++;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
                start_index = current_start;
            }
            current_length = 1;
            current_start = i;
        }
    }
    
    if (current_length > max_length) {
        max_length = current_length;
        start_index = current_start;
    }
    
    for (int i = start_index; i < start_index + max_length; i++) {
        printf("%.2lf", prices[i]);
        if (i < start_index + max_length - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    free(prices);
    return 0;
}