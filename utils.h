#ifndef UTILS_H
#define UTILS_H

// Convert string to lowercase (case-insensitive comparison ke liye)
void to_lowercase(char* str);

// Tokenize space-separated string into array of words
int tokenize(char* input, char tokens[][50]);

// Check if word exists in token list
int contains(char* word, char tokens[][50], int count);

#endif
