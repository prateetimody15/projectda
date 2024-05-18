#include <stdio.h>
#include <string.h>

void naiveStringMatch(char *text, char *pattern) {
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    int i, j;

    for (i = 0; i <= text_len - pattern_len; i++) {
        j = 0;
        while (j < pattern_len && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == pattern_len) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[100], pattern[100];

    printf("Enter the text string: ");
    fgets(text, sizeof(text), stdin);
    // Remove newline character if present
    if (text[strlen(text) - 1] == '\n')
        text[strlen(text) - 1] = '\0';

    printf("Enter the pattern string: ");
    fgets(pattern, sizeof(pattern), stdin);
    // Remove newline character if present
    if (pattern[strlen(pattern) - 1] == '\n')
        pattern[strlen(pattern) - 1] = '\0';

    naiveStringMatch(text, pattern);

    return 0;
}
