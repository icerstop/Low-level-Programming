#include <stdio.h>

int main()
{
    int n;
    int m;
    double R = 0.0;

    printf("Enter n parameter: ");
    scanf("%d", &n);
    printf("Enter m parameter: ");
    scanf("%d", &m);
    

    for (int i = 1; i <= n; i++)
    {
        double product = 1.0;
        for (int j = 1; j <= m; j++)
        {
            product *= (i*i + j*j - 1.0) / (2.0*i + 3.0*j + 4.0);
        }
        R += product;
    }
    printf("Result = %lf", R);
}