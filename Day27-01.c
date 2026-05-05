//Find Intersection Point of Two Linked Lists
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB) return NULL;

    struct ListNode *a = headA;
    struct ListNode *b = headB;

    while (a != b) {
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }

    return a;
}

int main() {
    struct ListNode* common = createNode(8);
    common->next = createNode(10);

    struct ListNode* headA = createNode(3);
    headA->next = createNode(7);
    headA->next->next = common;

    struct ListNode* headB = createNode(99);
    headB->next = createNode(1);
    headB->next->next = common;

    struct ListNode* intersection = getIntersectionNode(headA, headB);

    if (intersection)
        printf("%d\n", intersection->val);
    else
        printf("No Intersection\n");

    return 0;
}