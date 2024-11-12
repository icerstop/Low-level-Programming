#include <stdio.h>

// Definicja funkcji obliczających
double calculateAverage(double a, double b, double c, double d) {
    return (a + b + c + d) / 4;
}

double findMax(double a, double b, double c, double d) {
    double max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    return max;
}

double findMin(double a, double b, double c, double d) {
    double min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    return min;
}

int main() {
    // Tablica wskaźników funkcji
    double (*calculationFuncs[3])(double, double, double, double) = {calculateAverage, findMax, findMin};

    FILE *inputFile, *outputFile;
    int seriesNumber, calculationMethod;
    double measurement1, measurement2, measurement3, measurement4;

    inputFile = fopen("Pomiary.txt", "r");
    if (inputFile == NULL) {
        printf("Nie mozna otworzyc pliku Pomiary.txt\n");
        return 1;
    }

    outputFile = fopen("Wyniki.txt", "w");
    if (outputFile == NULL) {
        printf("Nie mozna otworzyc pliku Wyniki.txt\n");
        return 1;
    }

    while (fscanf(inputFile, "%d %lf %lf %lf %lf %d", &seriesNumber, &measurement1, &measurement2, &measurement3, &measurement4, &calculationMethod) == 6) {
        if (calculationMethod >= 0 && calculationMethod <= 2) {
            double calculatedValue = calculationFuncs[calculationMethod](measurement1, measurement2, measurement3, measurement4);
            fprintf(outputFile, "%d %lf %d\n", seriesNumber, calculatedValue, calculationMethod);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
