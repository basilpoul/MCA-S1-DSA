#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* Create(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode ->data=data;
    newNode ->next=NULL;    
    return newNode;
}

void Insert(struct node** head,int data){
    struct node* newNode = Create(data);
    if (*head==NULL){
        *head=newNode;
        return;
    }
    struct node* temp=*head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp ->next=newNode;
}

void PrintList(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct node* head=NULL;
    int c=1;
    while(c==1){
        int choice;
        printf("What do you want to do\n1.Insert an element\n2.Display linked list \nEnter choice : ");
        scanf("%d",&choice);

        if (choice==1){
            int element;
            printf("Enter the element to insert : ");
            scanf("%d",element);
            Insert(&head,element);
            printf("Element Inserted");
        }else if (choice==2){
            PrintList(head);
        }else{
            printf("Enter a valid choice");
        }
        
        printf("Do you want to continue Yes(1)/No(0) : ");
        scanf("%d",&c);
    }

    return 0;

}