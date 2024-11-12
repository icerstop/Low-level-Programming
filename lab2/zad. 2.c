#include <stdio.h>

int sum_of_digits(int n){
    if(n==0){
        return 0;
    }
    else{
        return n%10 + sum_of_digits(n/10);
    }
}

int main(){
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    int sum = sum_of_digits(n);
    printf("%d", sum);
    return 0;
}
