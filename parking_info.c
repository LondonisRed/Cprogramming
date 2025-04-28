#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000
#define PLATE_LEN 11

void standaliseString(char* str) {
    while (strlen(str) > 0 && (str[strlen(str) - 1] == '\r' || str[strlen(str) - 1] == '\n'))
        str[strlen(str) - 1] = '\0';
}

void clearStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

typedef struct {
    char plate[PLATE_LEN];
    int status; 
} Car;

int main() {
    Car cars[MAX_LEN];
    int carCount = 0;

    char plate[PLATE_LEN];
    char datetime[20];
    int type;

    while (1) {
        fgets(plate, sizeof(plate), stdin);
        standaliseString(plate);

        if (strcmp(plate, "-1") == 0)
            break;

        fgets(datetime, sizeof(datetime), stdin); 
        standaliseString(datetime);

        scanf("%d", &type);
        clearStdin();

        int found = 0;
        for (int i = 0; i < carCount; ++i) {
            if (strcmp(cars[i].plate, plate) == 0) {
                if (type == 1)
                    cars[i].status = 1;
                else
                    cars[i].status = 0;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(cars[carCount].plate, plate);
            cars[carCount].status = (type == 1) ? 1 : 0;
            carCount++;
        }
    }

    int inParking = 0;
    for (int i = 0; i < carCount; ++i) {
        if (cars[i].status == 1)
            inParking++;
    }

    printf("%d\n", inParking);
    for (int i = 0; i < carCount; ++i) {
        if (cars[i].status == 1)
            printf("%s\n", cars[i].plate);
    }
    return 0;
}