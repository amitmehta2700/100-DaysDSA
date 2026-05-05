#include <stdio.h>

int diagonalSum(int mat[][100], int n) {
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += mat[i][i];

        sum += mat[i][n - i - 1];
    }

    if(n % 2 == 1) {
        sum -= mat[n/2][n/2];
    }

    return sum;
}

int main() {
    int n;
    printf("Enter size of matrix: ");
    scanf("%d", &n);

    int mat[100][100];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int result = diagonalSum(mat, n);
    printf("Diagonal Sum = %d\n", result);

    return 0;
}