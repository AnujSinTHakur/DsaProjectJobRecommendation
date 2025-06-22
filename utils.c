#include <string.h>
#include <ctype.h>
#include "utils.h"

// Convert string to lowercase
void to_lowercase(char* str) {
    int i;
    for (i = 0; str[i]; i++)
        str[i] = tolower((unsigned char)str[i]);
}

// Split string into space-separated tokens
int tokenize(char* input, char tokens[][50]) {
    int count = 0;
    char* token = strtok(input, " ");
    while (token && count < 50) {
        strncpy(tokens[count], token, 49);
        tokens[count][49] = '\0';
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Check if word exists in tokens
int contains(char* word, char tokens[][50], int count) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(word, tokens[i]) == 0)
            return 1;
    }
    return 0;
}
