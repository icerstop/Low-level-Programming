#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024
#define MAX_DEPTH 10
#define INDENT_SIZE 3

char get_label(int depth, int value) {
    switch (depth) {
        case 0: return 'A' + value;
        case 1: return '1' + value;
        case 2: return 'a' + value;
        default: return '(' + value;
    }
}

void process_file(FILE *input, FILE *output) {
    char line[MAX_LINE_LEN];
    int depth_counters[MAX_DEPTH] = {0};

    while (fgets(line, MAX_LINE_LEN, input)) {
        int depth = 0;

        while (line[depth] == '*') {
            depth++;
        }

        if (depth == 0) {
            continue;
        }

        depth_counters[depth - 1]++;
        for (int i = depth; i < MAX_DEPTH; i++) {
            depth_counters[i] = 0;
        }

        for (int i = 0; i < depth - 1; i++) {
            fprintf(output, "%*s", INDENT_SIZE, "");
        }
        fprintf(output, "%c. %s", get_label(depth - 1, depth_counters[depth - 1] - 1), line + depth);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_filename> <output_filename>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 2;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return 3;
    }

    process_file(input, output);

    fclose(input);
    fclose(output);
    return 0;
}
