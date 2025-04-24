#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void normalize_string(char *str) {
    if (str == NULL) return;

    int len = strlen(str);
    if (len == 0) return;

    int start = 0;
    while (start < len && isspace(str[start])) {
        start++;
    }

    int end = len - 1;
    while (end >= 0 && isspace(str[end])) {
        end--;
    }

    if (start > end) {
        str[0] = '\0';
        return;
    }

    if (start > 0) {
        memmove(str, str + start, end - start + 1);
    }
    str[end - start + 1] = '\0';
    len = strlen(str);

    int j = 0;
    bool prev_space = false;
    for (int i = 0; i < len; i++) {
        if (str[i] == '\r' || str[i] == '\n') {
            continue;
        }
        
        if (isspace(str[i])) {
            if (!prev_space) {
                str[j++] = ' ';
                prev_space = true;
            }
        } else {
            str[j++] = str[i];
            prev_space = false;
        }
    }
    str[j] = '\0';
    if (j > 0) {
        str[0] = toupper(str[0]);
    }
}

int main() {
    char input[1000];

    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("EMPTY\n");
        return 0;
    }
    input[strcspn(input, "\n")] = '\0';
    normalize_string(input);

    if (strlen(input) == 0) {
        printf("EMPTY\n");
    } else {
        printf("%s\n", input);
    }
    return 0;
}