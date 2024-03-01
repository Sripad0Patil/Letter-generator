#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* link;
}n;
void llt(n *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element %d\n",ptr->data);
        ptr = ptr->link;
    }
}
n* insert(n* head, int data)
{
    n* ptr=(n*)malloc(sizeof(n));
    ptr->prev=NULL;
    ptr->link=head;
    ptr->data=data;
    return ptr;

}
n* delete(n* head)
{
    n* p=head;
    n* q=head->link;
    while(q->link!=NULL)
    {
        p=p->link;
        q=q->link;
    }
    p->link=NULL;
    free(q);
    return head;
}
int main()
{
    n*head=(n*)malloc(sizeof(n));
    n*first=(n*)malloc(sizeof(n));
    n*sec=(n*)malloc(sizeof(n));

    head->prev=NULL;
    head->data=1;
    head->link=first;

    first->prev=head;
    first->data=2;
    first->link=sec;

    sec->prev=first;
    sec->data=3;
    sec->link=NULL;
    printf("Original: \n");
    llt(head);
    printf("\nAfter insertion: \n");
    head = insert(head, 0);
    llt(head);
    printf("\nAfter deletion: \n");
    head = delete(head);
    llt(head);


}