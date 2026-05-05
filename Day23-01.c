#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* merge(struct node *h1, struct node *h2)
{
    struct node *head,*temp;

    if(h1->data <= h2->data){
        head=h1;
        h1=h1->next;
    }
    else{
        head=h2;
        h2=h2->next;
    }

    temp=head;

    while(h1!=NULL && h2!=NULL){
        if(h1->data <= h2->data){
            temp->next=h1;
            h1=h1->next;
        }
        else{
            temp->next=h2;
            h2=h2->next;
        }
        temp=temp->next;
    }

    if(h1!=NULL)
        temp->next=h1;
    else
        temp->next=h2;

    return head;
}

void display(struct node *head)
{
    while(head!=NULL){
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head1=NULL,*head2=NULL;
    struct node *temp1=NULL,*temp2=NULL;
    struct node *newnode,*merged;
    int n1,n2,i;

    printf("Enter number of nodes in first list: ");
    scanf("%d",&n1);

    for(i=0;i<n1;i++){
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head1==NULL){
            head1=temp1=newnode;
        }
        else{
            temp1->next=newnode;
            temp1=newnode;
        }
    }

    printf("Enter number of nodes in second list: ");
    scanf("%d",&n2);

    for(i=0;i<n2;i++){
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head2==NULL){
            head2=temp2=newnode;
        }
        else{
            temp2->next=newnode;
            temp2=newnode;
        }
    }

    merged=merge(head1,head2);

    printf("\nMerged Linked List:\n");
    display(merged);

    return 0;
}