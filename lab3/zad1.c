#include <stdio.h>

int main() {
    char character;
    char target_character;
    int count = 0;

    printf("Enter the character whose occurrence count you want to find: ");
    scanf("%c", &target_character);

    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    while ((character = fgetc(file)) != EOF) {
        if (character == target_character) {
            count++;
        }
    }

    fclose(file);

    printf("Number of occurrences of character '%c' in the input file: %d\n", target_character, count);

    return 0;
}
