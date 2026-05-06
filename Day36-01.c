/*Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;
int size = 0;

void enqueue(int x)
{
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    size++;
}

void dequeue()
{
    if(size == 0)
        return;

    front = (front + 1) % MAX;
    size--;
}

void display()
{
    int i;
    int index = front;

    for(i = 0; i < size; i++)
    {
        printf("%d ", queue[index]);
        index = (index + 1) % MAX;
    }
}

int main()
{
    int n,m,x,i;
printf("Enter number of elements: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d",&x);
        enqueue(x);
    }
printf("Enter number of dequeue operations: ");
    scanf("%d",&m);

    for(i=0;i<m;i++)
    {
        dequeue();
    }

    display();

    return 0;
}