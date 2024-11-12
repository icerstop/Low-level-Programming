#include <stdio.h>

int SumOfDivisors(int n)
{
    int sum = 0;
    for (int i=1; i<=n/2; i++)
    {
        if (n%i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int a;
    printf("Enter the number a, the limit of the search interval ([1, a]) for amicable numbers: ");
    scanf("%d", &a);
    printf("\n");

    printf("Amicable numbers in interval [1, %d]:\n ", a);

    for (int i=1; i <= a; i++)
    {
        int sum1 = SumOfDivisors(i);
        int sum2 = SumOfDivisors(sum1);

        if (i == sum2 && i < sum1)
        {
            printf("%d and %d\n", i, sum1);
        }
    }
    return 0;
}