#include <stdio.h>

int main() {
    int s;
    printf("Enter the size of the triangle: ");
    scanf("%d", &s);
    
    for(int i = 0; i < s; i++) {
        for(int j = 0; j < s - i - 1; j++) {
            printf(" ");
        }
        for(int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}