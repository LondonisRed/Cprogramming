#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 500
#define MAX_LENGTH 100

int is_proper_name(char *word) {
    if (isupper(word[0])) {
        return 1;
    }
    return 0;
}

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char text[MAX_WORDS * MAX_LENGTH];  
    char *words[MAX_WORDS];  
    int word_count = 0; 
    char *delimiters = " ,.!?;:\n\t"; 

    // Đọc input vào
    fgets(text, sizeof(text), stdin);

    char *token = strtok(text, delimiters);
    while (token != NULL) {
        words[word_count++] = token;
        token = strtok(NULL, delimiters);
    }

    char *proper_names[MAX_WORDS];
    int proper_names_count = 0;

    // Lọc các tên riêng
    for (int i = 0; i < word_count; i++) {
        if (is_proper_name(words[i])) {
            int is_duplicate = 0;
            for (int j = 0; j < proper_names_count; j++) {
                if (strcmp(proper_names[j], words[i]) == 0) {
                    is_duplicate = 1;
                    break;
                }
            }
            if (!is_duplicate) {
                proper_names[proper_names_count++] = words[i];
            }
        }
    }

    if (proper_names_count == 0) {
        printf("EMPTY\n");
    } else {
        qsort(proper_names, proper_names_count, sizeof(char *), compare);
        for (int i = 0; i < proper_names_count; i++) {
            printf("%s ", proper_names[i]);
        }
        printf("\n");
    }

    return 0;
}