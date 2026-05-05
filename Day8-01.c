#include <stdio.h>

int power(int base, int exp) {
    if(exp == 0)
        return 1;  
    
    return base * power(base, exp - 1);
}

int main() {
    int base, exp;

    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exp);

    int result = power(base, exp);

    printf("Result = %d", result);

    return 0;
}