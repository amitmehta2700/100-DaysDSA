#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int i, length;

    printf("Enter your name: ");
    scanf("%s", name);

    length = strlen(name);

    printf("Mirrored name: ");
    for(i = length - 1; i >= 0; i--) {
        printf("%c", name[i]);
    }

    return 0;
}