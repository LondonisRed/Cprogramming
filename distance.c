#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    char input[1000];
    float x_prev = 0, y_prev = 0; 
    float x_curr = 0, y_curr = 0;
    float total_distance = 0.0;

    while (1) {
        scanf("%s", input);

        if (strcmp(input, "-1") == 0) {
            break;
        }

        if (sscanf(input, "%f:%f", &x_curr, &y_curr) != 2) {
            continue;
        }

        float dx = x_curr - x_prev;
        float dy = y_curr - y_prev;
        total_distance += sqrt(dx * dx + dy * dy);

        x_prev = x_curr;
        y_prev = y_curr;
    }

    float distance_from_origin = sqrt(x_curr * x_curr + y_curr * y_curr);
    printf("%.2f %.2f\n", total_distance, distance_from_origin);

    return 0;
}