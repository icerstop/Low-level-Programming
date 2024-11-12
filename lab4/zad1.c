#include <stdio.h>
#include <math.h>

// Zdefiniowanie maksymalnego rozmiaru macierzy
#define MAX_SIZE 50

// Definicja funkcji do przekształcania elementów
double calculateElement(double element) {
    if(element < -1.0) {
        return 3.31;
    } else {
        return (pow(sin(element), 2) - 3) / sqrt(element + 1);
    }
}

int main() {
    // Definicja rozmiaru i macierzy
    int n, m;
    double A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];

    // Wczytanie rozmiaru macierzy
    printf("Podaj liczbe wierszy (n): ");
    scanf("%d", &n);
    printf("Podaj liczbe kolumn (m): ");
    scanf("%d", &m);

    // Wczytanie macierzy A
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    // Przekształcenie macierzy A do macierzy B
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            B[i][j] = calculateElement(A[i][j]);
        }
    }

    // Wyświetlenie macierzy B
    printf("\nMacierz B:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%.2lf ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}
