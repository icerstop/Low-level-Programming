#include <stdio.h>

#define MAX_SIZE 15

int main() {
    int n, m;
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], R[MAX_SIZE][MAX_SIZE], P[MAX_SIZE][MAX_SIZE];

    printf("Podaj liczbe wierszy (n): ");
    scanf("%d", &n);
    printf("Podaj liczbe kolumn (m): ");
    scanf("%d", &m);

    // Wczytanie macierzy A
    printf("\nWprowadzanie macierzy A:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Wczytanie macierzy B
    printf("\nWprowadzanie macierzy B:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Przekształcanie macierzy A i B do macierzy R i P
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (A[i][j] == B[i][j]) {
                R[i][j] = 1;
                P[i][j] = 0;
            } else {
                R[i][j] = 0;
                if (A[i][j] > B[i][j]) {
                    P[i][j] = 1;
                } else {
                    P[i][j] = 0;
                }
            }
        }
    }

    // Wyświetlanie macierzy R
    printf("\nMacierz R:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    // Wyświetlanie macierzy P
    printf("\nMacierz P:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", P[i][j]);
        }
        printf("\n");
    }

    return 0;
}
