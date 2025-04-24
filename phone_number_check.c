#include <stdio.h>
#include <string.h>

const char *viettel_prefixes[] = {"096", "097", "098", "086", "032", "033", "034", "035", "036", "037", "038", "039"};
const int prefix_count = 12;


int is_viettel_number(char *input) {
    char formatted[13]; 
    strcpy(formatted,input);

    if (strncmp(formatted, "84", 2) == 0) {
        formatted[0] = '0'; 
        formatted[1] = formatted[2];
        for (int i = 2; i < strlen(formatted); i++) {
            formatted[i] = formatted[i + 1];
        }
    }
    
    for (int i = 0; i < prefix_count; i++) {
        if (strncmp(formatted, viettel_prefixes[i], 3) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char phoneNumber[12];
    scanf("%s", phoneNumber);
    if(strlen(phoneNumber) != 11 && strlen(phoneNumber) != 10) {
        printf("0\n");
        return 0;
    }
    if (is_viettel_number(phoneNumber)) printf("1\n");
    return 0;
}




