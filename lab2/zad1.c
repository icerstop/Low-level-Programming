#include <stdio.h>
#include <math.h>

int automorphism(int n){
    int tmp = n*n; //squared number
    int digits = log10(n) + 1; //number of number n
    int enddig = pow(10, digits); //how many last numbers have to be checked
    return(tmp % enddig == n); //are numbers the same
}

int main()
{
    int a, b;
    printf("Enter parameters a, b for interval <a, b>: ");
    scanf("%d %d", &a, &b);
    printf("Automorphic numbers of interval <%d, %d>:\n", a, b);
    for (int i=a; i<=b; i++){
        if(automorphism(i)){ 
            printf("%d\n", i);
        }
    }
    return 0;
}
