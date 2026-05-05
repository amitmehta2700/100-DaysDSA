#include <stdio.h>
#include <stdlib.h>  
int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int minSum = 1000000;
    int a, b;

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            if(abs(sum) < abs(minSum)) {
                minSum = sum;
                a = arr[i];
                b = arr[j];
            }
        }
    }

    printf("Pair closest to zero: %d and %d\n", a, b);
    printf("Sum: %d\n", minSum);

    return 0;
}