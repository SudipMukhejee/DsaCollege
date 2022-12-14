#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head;

struct node *GetNewNode(int x){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void InsertAtHead(int x){
    struct node *newNode = GetNewNode(x);
    if(head == NULL) {
		head = newNode;
		return;
	}
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void InsertAttail(int x){
    struct node *temp = head;
    struct node *newnode = GetNewNode(x);
    if(head == NULL){
        head = newnode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}
void InsertAtPosi(int x,int posi){
    struct node *temp = head;
    struct node *newnode = GetNewNode(x);
    int cnt = 1;
    while(temp != NULL && cnt < posi - 1){
        temp =temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        temp->next = newnode;
        newnode->prev = temp;
    }
    else{
        struct node *temp2 = temp->next;
        temp->next = newnode;
        temp2->prev = newnode;
        newnode->prev = temp;
        newnode->next = temp2;
    }
}
void print(){
    struct node *temp = head;
    printf("Forward :");
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
}
void reversePrint(){
    struct node *temp = head;
    if(temp == NULL){
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    printf("Reverse :");
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->prev;
    }
    printf("NULL");
    printf("\n");
}
int main()
{
    head = NULL;
    InsertAtHead(2);
    InsertAttail(3);
    InsertAttail(4);
    InsertAttail(5);
    InsertAtPosi(88,5);
    print();
    reversePrint();
    return 0;
}
