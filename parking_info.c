#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PLATE_LENGTH 11
#define MAX_VEHICLES 100

typedef struct {
    char license_plate[MAX_PLATE_LENGTH];
    bool is_parked;
} Vehicle;

int main() {
    Vehicle vehicles[MAX_VEHICLES];
    int count = 0;
    char input[20];
    
    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; 
        
        if (strcmp(input, "-1") == 0) {
            break;
        }
        
        fgets(input, sizeof(input), stdin);
        
        int type;
        scanf("%d", &type);
        getchar(); 
 
        if (strlen(input) > 0) {
            int found_index = -1;
            for (int i = 0; i < count; i++) {
                if (strcmp(vehicles[i].license_plate, input) == 0) {
                    found_index = i;
                    break;
                }
            }
            
            if (type == 1) {
                if (found_index == -1) {
                    strcpy(vehicles[count].license_plate, input);
                    vehicles[count].is_parked = true;
                    count++;
                } else {
                    vehicles[found_index].is_parked = true;
                }
            } else if (type == 0) { 
                if (found_index != -1) {
                    vehicles[found_index].is_parked = false;
                }
            }
        }
    }

    int parked_count = 0;
    for (int i = 0; i < count; i++) {
        if (vehicles[i].is_parked) {
            parked_count++;
        }
    }
    
    printf("%d\n", parked_count);
    for (int i = 0; i < count; i++) {
        if (vehicles[i].is_parked) {
            printf("%s\n", vehicles[i].license_plate);
        }
    }
    return 0;
}