#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void displayElementsofLinkedList(struct node* node)
{   
    while(node!=NULL)
    {
        printf("Element: %d\n", node->data);
        node = node->next;
    }
}
struct node * insertNodeAtBeginning(struct node *head, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = head;
    return(ptr);

}
void insertNodeAtIndex(struct node*head, int data, int index)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p = head;
    ptr->data = data;
    int i = 0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
}
void insertNodeAtEnd(struct node *head, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = (struct node*)malloc(sizeof(struct node));

    ptr->data = data;
    p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;
    
}
struct node* deleteAtBeginning(struct node* head)
{
    return head->next;
}

void deleteAtIndex(struct node* head, int index)
{
    struct node* p = head;
    struct node* q = head->next;
    for(int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
}
void deleteValue(struct node* head, int data)
{
    struct node *p = head;
    struct node *q = head->next;
    while(q->data != data)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
}
int main()
{
    struct node *head, *first, *second, *third, *fourth;
    
    // Allocation memory to each node
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    
    // Assigning data to each node and linking each node
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    int n,index;
    printf("Enter the element to be inserted in the beginning: ");
    scanf("%d", &n);

    head = insertNodeAtBeginning(head,n);

    printf("Enter the element and which index you wish to store it at: ");
    scanf("%d %d", &n, &index);
    insertNodeAtIndex(head, n, index);

    printf("Enter the element to be stored at the end: ");
    scanf("%d", &n);
    insertNodeAtEnd(head, n);

    displayElementsofLinkedList(head);

    head = deleteAtBeginning(head);

    printf("Enter the index for element to be deleted at: ");
    scanf("%d", &index);
    deleteAtIndex(head, index);

    displayElementsofLinkedList(head);

    printf("Enter the data to be deleted: ");
    scanf("%d", &n);
    deleteValue(head, n);

    displayElementsofLinkedList(head);

    return 0;
}