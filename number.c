#include <stdio.h>
#include <string.h>

void findSequentialGroups(char *number) {
    int len = strlen(number);
    int start = 0;
    int hasOutput = 0;

    for (int i = 0; i < len - 1; i++) {
        if (number[i] == '0') {
            start = 0;
            continue;
        }
        if (number[i + 1] == number[i] + 1) {
            if (start == 0) {
                start = 1;
                if (hasOutput) {
                    printf(" ");
                }
                printf("%c", number[i]);
            }
            printf("%c", number[i + 1]);
            hasOutput = 1;
        } else {
            start = 0;
        }
    }

    if (hasOutput) {
        return;
    }
    printf("  ");
}

int main() {
    char number[16]; 
    scanf("%s", number);

    findSequentialGroups(number);

    return 0;
}