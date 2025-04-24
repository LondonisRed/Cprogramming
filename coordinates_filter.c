#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_COORDINATES 1000

typedef struct {
    double x;
    double y;
} Coordinate;

double distance(Coordinate a, Coordinate b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    double max_distance;
    scanf("%lf", &max_distance);
    
    Coordinate coords[MAX_COORDINATES];
    Coordinate filtered[MAX_COORDINATES];
    bool is_valid[MAX_COORDINATES];
    int count = 0;
    char input[50];
    
    while (true) {
        scanf("%s", input);
        if (strcmp(input, "-1") == 0) break;
        
        sscanf(input, "%lf:%lf", &coords[count].x, &coords[count].y);
        count++;
    }

    if (count == 0) {
        printf("0 -1\n");
        return 0;
    }

    is_valid[0] = true;
    int invalid_count = 0;

    for (int i = 1; i < count; i++) {
        double dist = distance(coords[i], coords[i-1]);
        is_valid[i] = (dist <= max_distance);
        if (!is_valid[i]) invalid_count++;
    }

    int filtered_count = 0;
    for (int i = 0; i < count; i++) {
        if (is_valid[i]) {
            filtered[filtered_count++] = coords[i];
        }
    }

    printf("%d ", invalid_count);
    if (filtered_count == 0) {
        printf("-1\n");
    } else {
        for (int i = 0; i < filtered_count; i++) {
            printf("%.2lf:%.2lf", filtered[i].x, filtered[i].y);
            if (i < filtered_count - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}