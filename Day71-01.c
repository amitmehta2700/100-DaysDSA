/*Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include <stdio.h>

#define MAX 100

int table[MAX];
int size;

// Initialize table
void init() {
    for (int i = 0; i < size; i++)
        table[i] = -1;
}

// Insert using quadratic probing
void insert(int key) {
    int h = key % size;

    for (int i = 0; i < size; i++) {
        int idx = (h + i * i) % size;

        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
    }
}

// Search using quadratic probing
int search(int key) {
    int h = key % size;

    for (int i = 0; i < size; i++) {
        int idx = (h + i * i) % size;

        if (table[idx] == key)
            return 1;

        if (table[idx] == -1)
            return 0;
    }
    return 0;
}

int main() {
    int q;
    printf("Enter size of hash table and number of queries: ");
    scanf("%d", &size);
    scanf("%d", &q);

    init();

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        printf("Enter operation (INSERT/SEARCH) and key: ");
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {   // INSERT
            insert(key);
        } else {              // SEARCH
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}