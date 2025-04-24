#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 500
#define MAX_WORD_LENGTH 50

bool isProperName(const char *word) {
    return isupper(word[0]);
}

bool isWordInList(const char *word, char list[][MAX_WORD_LENGTH], int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(word, list[i]) == 0) {
            return true;
        }
    }
    return false;
}

void sortNames(char names[][MAX_WORD_LENGTH], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char temp[MAX_WORD_LENGTH];
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    char names[MAX_WORDS][MAX_WORD_LENGTH];
    int wordCount = 0;
    int nameCount = 0;

    while (scanf("%s", words[wordCount]) == 1 && wordCount < MAX_WORDS - 1) {
        wordCount++;
    }

    for (int i = 0; i < wordCount; i++) {
        if (isProperName(words[i])) {
            if (!isWordInList(words[i], names, nameCount)) {
                strcpy(names[nameCount], words[i]);
                nameCount++;
            }
        }
    }

    sortNames(names, nameCount);

    if (nameCount == 0) {
        printf("EMPTY\n");
    } else {
        for (int i = 0; i < nameCount; i++) {
            printf("%s", names[i]);
            if (i < nameCount - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}