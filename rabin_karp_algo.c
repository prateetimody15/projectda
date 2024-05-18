#include <stdio.h>
#include <string.h>
#include <math.h>

#define PRIME 101 // A prime number for hash function

// Function to calculate the hash value of a substring
int calculateHash(char *str, int len) {
    int hash = 0;
    for (int i = 0; i < len; i++) {
        hash += str[i] * pow(PRIME, i);
    }
    return hash;
}

// Function to re-calculate the hash value using rolling hash
int recalculateHash(char *str, int oldHash, int oldChar, int newChar, int len) {
    int newHash = oldHash - oldChar;
    newHash /= PRIME;
    newHash += newChar * pow(PRIME, len - 1);
    return newHash;
}

// Function to perform Rabin-Karp string matching
void rabinKarp(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int patternHash = calculateHash(pattern, m);
    int textHash = calculateHash(text, m);

    for (int i = 0; i <= n - m; i++) {
        if (textHash == patternHash) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                printf("Pattern found at index %d\n", i);
        }
        if (i < n - m) {
            textHash = recalculateHash(text + i, textHash, text[i], text[i + m], m);
            if (textHash < 0)
                textHash += PRIME;
        }
    }
}

int main() {
    char text[100], pattern[100];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    rabinKarp(text, pattern);

    return 0;
}
