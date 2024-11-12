#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024
#define MAX_DEPTH 10
#define INDENT_SIZE 3

// Funkcja przetwarzająca plik wejściowy i zapisująca wynik do pliku wyjściowego
void process_file(FILE *input, FILE *output) {
    char line[MAX_LINE_LEN];
    int depth_counters[MAX_DEPTH] = {0};

    // Odczytujemy linie z pliku wejściowego
    while (fgets(line, MAX_LINE_LEN, input)) {
        int depth = 0;

        // Obliczamy głębokość linii (liczbę gwiazdek)
        while (line[depth] == '*') {
            depth++;
        }

        // Jeśli głębokość wynosi 0, kontynuujemy z następną linią
        if (depth == 0) {
            continue;
        }

        // Zwiększamy licznik głębokości i zerujemy liczniki niższych poziomów
        depth_counters[depth - 1]++;
        for (int i = depth; i < MAX_DEPTH; i++) {
            depth_counters[i] = 0;
        }

        // Wypisujemy wcięcia
        for (int i = 0; i < depth - 1; i++) {
            fprintf(output, "%*s", INDENT_SIZE, "");
        }

        // Wypisujemy numerację linii
        for (int i = 0; i < depth; i++) {
            fprintf(output, "%d.", depth_counters[i]);
        }

        // Wypisujemy zawartość linii
        fprintf(output, " %s", line + depth);
    }
}

int main(int argc, char *argv[]) {
    // Sprawdzamy, czy użytkownik podał wymagane argumenty
    if (argc < 3) {
        printf("Usage: %s <input_filename> <output_filename>\n", argv[0]);
        return 1;
    }

    // Otwieramy plik wejściowy do odczytu
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 2;
    }

    // Otwieramy plik wyjściowy do zapisu
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return 3;
    }

    // Przetwarzamy plik wejściowy i zapisujemy wynik do pliku wyjściowego
    process_file(input, output);

    // Zamykamy pliki
    fclose(input);
    fclose(output);

    return 0;
}
