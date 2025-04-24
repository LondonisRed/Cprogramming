#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COORDINATES 1000

typedef struct {
    double x;
    double y;
} Coordinate;

int main() {
    Coordinate coords[MAX_COORDINATES];
    int count = 0;
    char input[50];
    
    while (true) {
        scanf("%s", input);
        if (strcmp(input, "-1") == 0) break;
        sscanf(input, "%lf:%lf", &coords[count].x, &coords[count].y);
        count++;
    }

    int start = -1, end = -1;
    for (int i = 0; i < count && start == -1; i++) {
        for (int j = i + 1; j < count && start == -1; j++) {
            if ((int)(coords[i].x * 100) == (int)(coords[j].x * 100) &&
                (int)(coords[i].y * 100) == (int)(coords[j].y * 100)) {
                start = i;
                end = j;
            }
        }
    }

    if (start != -1) {
        for (int i = start; i <= end; i++) {
            printf("%.2lf:%.2lf ", coords[i].x, coords[i].y);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }

    return 0;
}