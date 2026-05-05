#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter size of matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }

    printf("Identity Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}