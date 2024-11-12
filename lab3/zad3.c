#include <stdio.h>
#include <stdlib.h>

int main() {
    // Deklaracja wskaźników plików wejściowych i wyjściowych
    FILE *inputFile, *outputFile;
    
    // Deklaracja tablicy do przechowywania sum kolumn
    int sum[100] = {0};
    
    // Deklaracja zmiennej przechowującej liczbę wierszy
    int rowCount = 0;
    
    // Deklaracja zmiennej przechowującej liczbę kolumn
    int colCount;
    
    // Deklaracja tablicy do przechowywania średnich kolumn
    float average[100];

    // Otwarcie pliku wejściowego w trybie odczytu
    inputFile = fopen("input.txt", "r");
    
    // Sprawdzenie, czy plik wejściowy został pomyślnie otwarty
    if (inputFile == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    // Odczyt pliku wejściowego aż do napotkania końca pliku
    while (!feof(inputFile)) {
        // Inicjalizacja licznika kolumn na 0 dla każdego wiersza
        colCount = 0;
        
        // Odczyt liczb całkowitych z pliku wejściowego i zapisanie ich w tablicy sum
        while (fscanf(inputFile, "%d", &sum[colCount]) == 1) {
            colCount++;
        }
        
        // Zwiększenie licznika wierszy po przeczytaniu każdego wiersza
        rowCount++;
        
        // Odczyt znaku nowej linii na końcu każdego wiersza
        fscanf(inputFile, "\n");
    }
    
    // Zamknięcie pliku wejściowego
    fclose(inputFile);

    // Obliczenie średniej dla każdej kolumny
    for (int i = 0; i < colCount; i++) {
        average[i] = (float)sum[i] / rowCount;
    }

    // Otwarcie pliku wyjściowego w trybie zapisu
    outputFile = fopen("output.txt", "w");
    
    // Sprawdzenie, czy plik wyjściowy został pomyślnie otwarty
    if (outputFile == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    // Zapisanie sumy każdej kolumny do pliku wyjściowego
    fprintf(outputFile, "Sum: ");
    for (int i = 0; i < colCount; i++) {
        fprintf(outputFile, "%d ", sum[i]);
    }
    fprintf(outputFile, "\n");

     // Zapisanie średniej każdej kolumny do pliku wyjściowego
    fprintf(outputFile, "Average: ");
    for (int i = 0; i < colCount; i++) {
        fprintf(outputFile, "%.1f ", average[i]);
    }
    fprintf(outputFile, "\n");

    // Zamknięcie pliku wyjściowego
    fclose(outputFile);

    // Wyświetlenie informacji o zakończeniu obliczeń statystycznych i zapisaniu wyników do pliku output.txt
    printf("File output.txt has been saved and closed.\n");

    return 0;
}