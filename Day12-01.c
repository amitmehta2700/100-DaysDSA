#include <stdio.h>

int main() {
    int n, i, j;
    int mat[10][10];
    int isSymmetric = 1;

    printf("Enter order of matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(mat[i][j] != mat[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
    }

    if(isSymmetric)
        printf("The matrix is symmetric.");
    else
        printf("The matrix is not symmetric.");

    return 0;
}
