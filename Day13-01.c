#include <stdio.h>

int main() {
    int a[10][10], rows, cols;
    int top, bottom, left, right, i;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for(i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    top = 0;
    bottom = rows - 1;
    left = 0;
    right = cols - 1;

    printf("Boundary to Center Traversal:\n");

    while(top <= bottom && left <= right) {

        for(i = left; i <= right; i++) {
            printf("%d ", a[top][i]);
        }
        top++;

        for(i = top; i <= bottom; i++) {
            printf("%d ", a[i][right]);
        }
        right--;

        if(top <= bottom) {
            for(i = right; i >= left; i--) {
                printf("%d ", a[bottom][i]);
            }
            bottom--;
        }

        if(left <= right) {
            for(i = bottom; i >= top; i--) {
                printf("%d ", a[i][left]);
            }
            left++;
        }
    }

    return 0;
}